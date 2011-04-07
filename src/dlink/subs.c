/*
 *    (c)Copyright 1992-1997 Obvious Implementations Corp.  Redistribution and
 *    use is allowed under the terms of the DICE-LICENSE FILE,
 *    DICE-LICENSE.TXT.
 */

/*
 *  SUBS.C
 *
 */

/*
**      $Filename: subs.c $
**      $Author: dice $
**      $Revision: 30.326 $
**      $Date: 1995/12/24 06:10:40 $
**      $Log: subs.c,v $
 * Revision 30.326  1995/12/24  06:10:40  dice
 * .
 *
 * Revision 30.5  1994/06/13  18:38:38  dice
 * removed assignment prefix to include for unix portability
 * byte ordering portability
 *
 * Revision 30.0  1994/06/10  18:05:40  dice
 * .
 *
 * Revision 1.3  1993/10/13  19:52:19  jtoebes
 * Fix warning message about pointer mismatch.
 *
 * Revision 1.2  1993/10/13  19:48:28  jtoebes
 * FIX BUG01046 - Dlink should look in DCC_CONFIG: for config files.
 *
**/


#include "defs.h"
#include <fcntl.h>

Prototype long	  MemMalloced;
Prototype long	  MemAllocated;
Prototype long	  MemRequested;
Prototype long	  MemReclaimed;
Prototype long	  MemNumSyms;
Prototype long	  MemNumHunks;
Prototype long	  MemNumModules;
Prototype long	  MemNumHunksMalReclaim;
Prototype long	  MemNumSymsMalReclaim;

Prototype void	cerror(short, ...);
Prototype void	_Assert(char *, int);
Prototype void	*zalloc(long);
Prototype void	zfree(void *, long);
Prototype void	putl(FILE *, long);
Prototype char	*HunkToStr(Hunk *);
Prototype void _SanityCheck(int);
Prototype int  open_lpath(char *, long);
Prototype Node *MakeNode(char *);
Prototype Node *MakeNode2(char *, char *);
Prototype char *ObtainErrorString(short);
Prototype void NoMemory(void);

Prototype void eprintf(const char *ctl, ...);
Prototype void veprintf(const char *ctl, va_list va);
Prototype void eputc(char c);

void *SetRequester(void *);

char	*ErrorFileName1 = DCC_CONFIG "dice.errors";
char	*ErrorFileName2 = DCC "config/dice.errors";
char	*ErrorAry;
long	ErrorArySize;
char	ErrBuf[128];


long	MemMalloced;
long	MemAllocated;
long	MemRequested;
long	MemReclaimed;
long	MemNumSyms;
long	MemNumHunks;
long	MemNumModules;
long	MemNumHunksMalReclaim;
long	MemNumSymsMalReclaim;

#define BLOCK_SIZE  4096
#define MAX_FREE    256

long **FreeList[MAX_FREE/4];

void
cerror(short errorId, ...)
{
    static const char *Ary[] = {
	"?Bad", NULL, "Warning", "Error", "SoftError", "Fatal"
    };
    va_list va;

    if (Ary[errorId >> 12]) {
	eprintf("DLINK: \"%s\" L:0 C:0 %.*s:%d ",
	    "",
	    ((ErrorOpt == 2) ? 1 : (int)strlen(Ary[errorId >> 12])),
	    Ary[errorId >> 12],
	    errorId & 0x0FFF
	);
    }

    va_start(va, errorId);
    veprintf(ObtainErrorString(errorId & 0x0FFF), va);
    va_end(va);
    eputc('\n');

    switch(errorId & EF_MASK) {
    case EF_WARN:
	if (ExitCode < 5)
	    ExitCode = 5;
	break;
    case EF_FATAL:
    case EF_SOFT:
	xexit(20);
	break;
    case EF_ERROR:
	if (ExitCode < 20)
	    ExitCode = 20;
	break;
    }
}

void
NoMemory()
{
    eprintf("NO MEMORY!\n");
    xexit(25);
}

void        
eprintf(const char *ctl, ...)
{   
    va_list va;
    
    va_start(va, ctl);
    veprintf(ctl, va);
    va_end(va); 
}
    
void    
veprintf(const char *ctl, va_list va)
{   
    vfprintf(stderr, ctl, va);
    if (ErrorFi)
        vfprintf(ErrorFi, ctl, va);
}           

void
eputc(char c)
{
    fputc(c, stderr);
    if (ErrorFi)
        fputc(c, ErrorFi);
}


void
_Assert(file, line)
char *file;
int line;
{
    cerror(EFATAL_ASSERT, line, file);
}

void *
zalloc(bytes)
long bytes;
{
    void *ptr;
    static char *BufPtr1;
    static char *BufPtr2;
    static long BufLen1;
    static long BufLen2;

    if (bytes == 0)
	return((void *)"");

    bytes = (bytes + 7) & ~3;
    MemRequested += bytes;
    if (bytes < MAX_FREE) {
	long index = bytes >> 2;

	if ((ptr = FreeList[index]) != NULL) {
	    FreeList[index] = (long **)*(long *)ptr;
	    setmem(ptr, bytes, 0);
	    return(ptr);
	}
    }
    MemAllocated += bytes;

    if (bytes <= BufLen1) {
	ptr = BufPtr1;
	BufPtr1 += bytes;
	BufLen1 -= bytes;
	if (BufLen1 == 0) {
	    BufLen1 = BufLen2;
	    BufPtr1 = BufPtr2;
	    BufLen2 = 0;
	}
	return(ptr);
    }
    if (bytes <= BufLen2) {
	ptr = BufPtr2;
	BufPtr2 += bytes;
	BufLen2 -= bytes;
	return(ptr);
    }
    if (bytes > BLOCK_SIZE/4) {
	ptr = malloc(bytes);
	setmem(ptr, bytes, 0);
	return(ptr);
    }
    if (BufLen2) {
	BufLen1 = BufLen2;
	BufPtr1 = BufPtr2;
    }
    ptr = malloc(BLOCK_SIZE);
    if (ptr == NULL)
	NoMemory();
    setmem(ptr, BLOCK_SIZE, 0);

    BufPtr2 = (char *)ptr + bytes;
    BufLen2 = BLOCK_SIZE - bytes;

    return(ptr);
}

void
zfree(ptr, bytes)
void *ptr;
long bytes;
{
    long index = (bytes + 7) >> 2;

    if (bytes == 0) {
	cerror(EFATAL_MEMORY_FREE_ERROR);
    }
    if (index < MAX_FREE/4) {
	*(long *)ptr = (long)FreeList[index];
	FreeList[index] = (long **)ptr;
	MemReclaimed += index << 2;
    }
}

void
putl(fo, n)
long n;
FILE *fo;
{
    n = ToMsbOrder(n);
    fwrite((char *)&n, sizeof(long), 1, fo);
}

char *
HunkToStr(hunk)
Hunk *hunk;
{
    static char Buf[2][256];
    static int Which;
    char *ptr = Buf[Which];

    Which = 1 - Which;
    if (hunk == NULL) {
	sprintf(ptr, "[NULL]");
	return(ptr);
    }
    sprintf(ptr, "[%s:%s hn#%d.%ld off %ld siz %ld]", hunk->Module->FNode->Node.ln_Name, hunk->Module->Node.ln_Name, hunk->HunkNo, hunk->HX->FinalHunkNo, hunk->Offset, hunk->Bytes);
    return(ptr);
}

#ifdef SANITY_CHECK

void
_SanityCheck(n)
{
    static short x = 0;
    static short y = 1085;

    Forbid();
    AvailMem(MEMF_LARGEST);
    Permit();
    if (y)
	--y;
    else
	Delay(50);
    printf("%d %d\n", x++, n);
}

#endif

/*
 *  find and open a file
 */

int
open_lpath(name, modes)
char *name;
long modes;
{
    int fd = -1;
    short fullPath = (strchr(name, ':') ? 1 : 0);
    Node *node;

    Tmp[0] = 0;
    for (node = GetHead(&LibDirList); node; node = GetSucc(node)) {
	sprintf(Tmp, "%s%s", node->ln_Name, name);
	fd = open(Tmp, modes);
	if (fd >= 0 || fullPath)
	    break;
    }
    if (fd < 0 && PostFix[0]) {
	for (node = GetHead(&LibDirList); node; node = GetSucc(node)) {
	    char *ptr;

	    sprintf(Tmp, "%s%s", node->ln_Name, name);
	    if ((ptr = strstr(Tmp, ".lib")) != NULL)
		strins(ptr, PostFix);
	    else
		strcat(Tmp, PostFix);

	    fd = open(Tmp, modes);
	    if (fd >= 0 || fullPath)
		break;
	}
    }
    if (fd < 0)
	cerror(EERROR_CANT_FIND_LIB, name, PostFix);
    return(fd);
}

Node *
MakeNode(ptr)
char *ptr;
{
    return(MakeNode2(ptr, ""));
}

Node *
MakeNode2(p1, p2)
char *p1;
char *p2;
{
    Node *node = malloc(sizeof(Node) + strlen(p1) + strlen(p2) + 1);

    node->ln_Name = (char *)(node + 1);
    strcpy(node->ln_Name, p1);
    strcat(node->ln_Name, p2);
    return(node);
}


char *
ObtainErrorString(short errNum)
{
    short i;
    static char *UseFileName;

    if (ErrorAry == NULL) {
	int fd;
	short siz;
	void *save;

	save = SetRequester((void *)-1);
	UseFileName = ErrorFileName1;
	fd = open(ErrorFileName1, O_RDONLY|O_BINARY);
	SetRequester(save);

	if (fd < 0) {
	    if ((fd = open(ErrorFileName2, O_RDONLY|O_BINARY)) < 0) {
		sprintf(ErrBuf, "(can't open %s!)", ErrorFileName2);
		return(ErrBuf);
	    }
	    UseFileName = ErrorFileName2;
	}
	siz = lseek(fd, 0L, 2);
	lseek(fd, 0L, 0);
	ErrorAry = malloc(siz + 1);
	read(fd, ErrorAry, siz);
	close(fd);
	{
	    char *ptr;
	    for (ptr = strchr(ErrorAry, '\n'); ptr; ptr = strchr(ptr + 1, '\n'))
		*ptr = 0;
	}
	ErrorAry[siz] = 0;
	ErrorArySize = siz;
    }
    for (i = 0; i < ErrorArySize; i += strlen(ErrorAry + i) + 1) {
	char *ptr;
	if (ErrorAry[i] == 'L' && ErrorAry[i+1] == 'K' && strtol(ErrorAry + i + 3, &ptr, 10) == errNum)
	    return(ptr + 1);
    }
    sprintf(ErrBuf, "(no entry in %s for error)", UseFileName ? UseFileName : "?");
    return(ErrBuf);
}

/*
 *  Routines that do not exist in Lattice C
 */

#ifndef _DCC

void *
GetSucc(struct Node *node)
{
    struct Node *next = node->ln_Succ;

    if (next->ln_Succ == NULL)
	next = NULL;
    return((void *)next);
}

void *
GetTail(struct List *list)
{
    struct Node *node = list->lh_TailPred;

    if (node->ln_Pred == NULL)
	node = NULL;
    return((void *)node);
}

void *
GetHead(struct List *list)
{
    struct Node *node = list->lh_Head;

    if (node->ln_Succ == NULL)
	node = NULL;
    return((void *)node);
}


void *
GetPred(struct Node *node)
{
    struct Node *pred = node->ln_Pred;

    if (pred->ln_Pred == NULL)
	pred = NULL;
    return((void *)pred);
}

#endif

#ifdef AMIGA

void *
SetRequester(void *new)
{
    void *old;
    struct Process *proc = (struct Process *)FindTask(NULL);

    old = proc->pr_WindowPtr;
    proc->pr_WindowPtr = new;
    return(old);
}

#else

void *
SetRequester(void *new)
{
    return(NULL);
}

#endif

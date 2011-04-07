
/*
 *  DC1/SYM.H
 *
 *    (c)Copyright 1992-1997 Obvious Implementations Corp.  Redistribution and
 *    use is allowed under the terms of the DICE-LICENSE FILE,
 *    DICE-LICENSE.TXT.
 */

typedef struct Symbol {
    struct Symbol *Next;    /*	hash table link 		*/
    void    *SemBase;	    /*	for semantics junk		*/
    const char   *Name;	    /*	pointer to unterminated symbol	*/
    long    Hv; 	    /*	hash value			*/
    short   Len;	    /*	length of symbol		*/
    short   LexId;	    /*	currently overloaded id 	*/
    void    *Data;	    /*	currently overloaded data	*/
} Symbol;

typedef struct SemInfo {
    struct SemInfo *MasterNext;
    struct SemInfo *Next;
    struct SemInfo **Prev;
    Symbol  *Sym;
    short   LexId;
    short   SemLevel;
    void    *Data;
} SemInfo;

typedef struct StrNode {
    struct StrNode *sn_Next;
    struct StrNode *sn_Prev;
    char    *sn_Ptr;
    long    sn_Len;
} StrNode;


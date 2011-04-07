#ifndef	EXEC_INITIALIZERS_H
#define	EXEC_INITIALIZERS_H
/*
**	$Filename: exec/initializers.h $
**	$Release: 2.04 Includes, V37.4 $
**	$Revision: 36.5 $
**	$Date: 90/05/10 $
**
**	Macros for use with the InitStruct() function.
**
**	(C) Copyright 1985-1991 Commodore-Amiga, Inc.
**	    All Rights Reserved
*/

#define	OFFSET(structName, structEntry) \
				(&(((struct structName *) 0)->structEntry))
#define	INITBYTE(offset,value)	0xe000,(UWORD) (offset),(UWORD) ((value)<<8)
#define	INITWORD(offset,value)	0xd000,(UWORD) (offset),(UWORD) (value)
#define	INITLONG(offset,value)	0xc000,(UWORD) (offset), \
				(UWORD) ((value)>>16), \
				(UWORD) ((value) & 0xffff)
#define	INITSTRUCT(size,offset,value,count) \
				(UWORD) (0xc000|(size<<12)|(count<<8)| \
				((UWORD) ((offset)>>16)), \
				((UWORD) (offset)) & 0xffff)
#endif /* EXEC_INITIALIZERS_H */

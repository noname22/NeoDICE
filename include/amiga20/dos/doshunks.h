#ifndef DOS_DOSHUNKS_H
#define DOS_DOSHUNKS_H
/*
**	$Filename: dos/doshunks.h $
**	$Release: 2.04 Includes, V37.4 $
**	$Revision: 36.5 $
**	$Date: 90/07/12 $
**
**	Hunk definitions for object and load modules.
**
**	(C) Copyright 1989-1991 Commodore-Amiga, Inc.
**	    All Rights Reserved
*/

/* hunk types */
#define HUNK_UNIT	999
#define HUNK_NAME	1000
#define HUNK_CODE	1001
#define HUNK_DATA	1002
#define HUNK_BSS	1003
#define HUNK_RELOC32	1004
#define HUNK_RELOC16	1005
#define HUNK_RELOC8	1006
#define HUNK_EXT	1007
#define HUNK_SYMBOL	1008
#define HUNK_DEBUG	1009
#define HUNK_END	1010
#define HUNK_HEADER	1011

#define HUNK_OVERLAY	1013
#define HUNK_BREAK	1014

#define HUNK_DREL32	1015
#define HUNK_DREL16	1016
#define HUNK_DREL8	1017

#define HUNK_LIB	1018
#define HUNK_INDEX	1019

/* hunk_ext sub-types */
#define EXT_SYMB	0	/* symbol table */
#define EXT_DEF		1	/* relocatable definition */
#define EXT_ABS		2	/* Absolute definition */
#define EXT_RES		3	/* no longer supported */
#define EXT_REF32	129	/* 32 bit reference to symbol */
#define EXT_COMMON	130	/* 32 bit reference to COMMON block */
#define EXT_REF16	131	/* 16 bit reference to symbol */
#define EXT_REF8	132	/*  8 bit reference to symbol */
#define EXT_DEXT32	133	/* 32 bit data releative reference */
#define EXT_DEXT16	134	/* 16 bit data releative reference */
#define EXT_DEXT8	135	/*  8 bit data releative reference */

#endif	/* DOS_DOSHUNKS_H */

#ifndef DEVICES_BOOTBLOCK_H
#define DEVICES_BOOTBLOCK_H
/*
**	$Filename: devices/bootblock.h $
**	$Release: 2.04 Includes, V37.4 $
**	$Revision: 36.6 $
**	$Date: 90/11/05 $
**
**	floppy BootBlock definition
**
**	(C) Copyright 1985-1991 Commodore-Amiga, Inc.
**	    All Rights Reserved
*/

#ifndef EXEC_TYPES_H
#include	"exec/types.h"
#endif

struct BootBlock {
	UBYTE	bb_id[4];		/* 4 character identifier */
	LONG	bb_chksum;		/* boot block checksum (balance) */
	LONG	bb_dosblock;		/* reserved for DOS patch */
};

#define		BOOTSECTS	2	/* 1K bootstrap */

#define BBID_DOS	{ 'D', 'O', 'S', '\0' }
#define BBID_KICK	{ 'K', 'I', 'C', 'K' }

#define BBNAME_DOS	0x444F5300	/* 'DOS\0' */
#define BBNAME_KICK	0x4B49434B	/* 'KICK' */

#endif	/* DEVICES_BOOTBLOCK_H */

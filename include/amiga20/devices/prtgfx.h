#ifndef DEVICES_PRTGFX_H
#define DEVICES_PRTGFX_H
/*
**	$Filename: devices/prtgfx.h $
**	$Release: 2.04 Includes, V37.4 $
**	$Revision: 1.12 $
**	$Date: 90/07/26 $
**
**	printer.device structure definitions
**
**	(C) Copyright 1987-1991 Commodore-Amiga, Inc.
**	    All Rights Reserved
*/

#ifndef  EXEC_TYPES_H
#include "exec/types.h"
#endif

#define	PCMYELLOW	0		/* byte index for yellow */
#define	PCMMAGENTA	1		/* byte index for magenta */
#define	PCMCYAN		2		/* byte index for cyan */
#define	PCMBLACK	3		/* byte index for black */
#define PCMBLUE		PCMYELLOW	/* byte index for blue */
#define PCMGREEN	PCMMAGENTA	/* byte index for green */
#define PCMRED		PCMCYAN		/* byte index for red */
#define PCMWHITE	PCMBLACK	/* byte index for white */

union colorEntry {
	ULONG colorLong;	/* quick access to all of YMCB */
	UBYTE colorByte[4];	/* 1 entry for each of YMCB */
	BYTE colorSByte[4];	/* ditto (except signed) */
};

struct PrtInfo { /* printer info */
	int (*pi_render)();		/* PRIVATE - DO NOT USE! */
	struct RastPort *pi_rp;		/* PRIVATE - DO NOT USE! */
	struct RastPort *pi_temprp;	/* PRIVATE - DO NOT USE! */
	UWORD *pi_RowBuf;		/* PRIVATE - DO NOT USE! */
	UWORD *pi_HamBuf;		/* PRIVATE - DO NOT USE! */
	union colorEntry *pi_ColorMap;	/* PRIVATE - DO NOT USE! */
	union colorEntry *pi_ColorInt;	/* color intensities for entire row */
	union colorEntry *pi_HamInt;	/* PRIVATE - DO NOT USE! */
	union colorEntry *pi_Dest1Int;	/* PRIVATE - DO NOT USE! */
	union colorEntry *pi_Dest2Int;	/* PRIVATE - DO NOT USE! */
	UWORD *pi_ScaleX;		/* array of scale values for X */
	UWORD *pi_ScaleXAlt;		/* PRIVATE - DO NOT USE! */
	UBYTE *pi_dmatrix;		/* pointer to dither matrix */
	UWORD *pi_TopBuf;		/* PRIVATE - DO NOT USE! */
	UWORD *pi_BotBuf;		/* PRIVATE - DO NOT USE! */

	UWORD pi_RowBufSize;		/* PRIVATE - DO NOT USE! */
	UWORD pi_HamBufSize;		/* PRIVATE - DO NOT USE! */
	UWORD pi_ColorMapSize;		/* PRIVATE - DO NOT USE! */
	UWORD pi_ColorIntSize;		/* PRIVATE - DO NOT USE! */
	UWORD pi_HamIntSize;		/* PRIVATE - DO NOT USE! */
	UWORD pi_Dest1IntSize;		/* PRIVATE - DO NOT USE! */
	UWORD pi_Dest2IntSize;		/* PRIVATE - DO NOT USE! */
	UWORD pi_ScaleXSize;		/* PRIVATE - DO NOT USE! */
	UWORD pi_ScaleXAltSize;		/* PRIVATE - DO NOT USE! */

	UWORD pi_PrefsFlags;		/* PRIVATE - DO NOT USE! */
	ULONG pi_special;		/* PRIVATE - DO NOT USE! */
	UWORD pi_xstart;		/* PRIVATE - DO NOT USE! */
	UWORD pi_ystart;		/* PRIVATE - DO NOT USE! */
	UWORD pi_width;			/* source width (in pixels) */
	UWORD pi_height;		/* PRIVATE - DO NOT USE! */
	ULONG pi_pc;			/* PRIVATE - DO NOT USE! */
	ULONG pi_pr;			/* PRIVATE - DO NOT USE! */
	UWORD pi_ymult;			/* PRIVATE - DO NOT USE! */
	UWORD pi_ymod;			/* PRIVATE - DO NOT USE! */
	WORD pi_ety;			/* PRIVATE - DO NOT USE! */
	UWORD pi_xpos;			/* offset to start printing picture */
	UWORD pi_threshold;		/* threshold value (from prefs) */
	UWORD pi_tempwidth;		/* PRIVATE - DO NOT USE! */
	UWORD pi_flags;			/* PRIVATE - DO NOT USE! */
};

#endif	/* DEVICES_PRTGFX_H */

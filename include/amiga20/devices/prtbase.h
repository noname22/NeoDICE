#ifndef  DEVICES_PRTBASE_H
#define  DEVICES_PRTBASE_H
/*
**	$Filename: devices/prtbase.h $
**	$Release: 2.04 Includes, V37.4 $
**	$Revision: 1.10 $
**	$Date: 90/11/02 $
**
**	printer.device base structure definitions
**
**	(C) Copyright 1987-1991 Commodore-Amiga, Inc.
**	    All Rights Reserved
*/

#ifndef  EXEC_TYPES_H
#include "exec/types.h"
#endif
#ifndef  EXEC_NODES_H
#include "exec/nodes.h"
#endif
#ifndef  EXEC_LISTS_H
#include "exec/lists.h"
#endif
#ifndef  EXEC_PORTS_H
#include "exec/ports.h"
#endif
#ifndef  EXEC_LIBRARIES_H
#include "exec/libraries.h"
#endif
#ifndef  EXEC_TASKS_H
#include "exec/tasks.h"
#endif

#ifndef  DEVICES_PARALLEL_H
#include "devices/parallel.h"
#endif
#ifndef  DEVICES_SERIAL_H
#include "devices/serial.h"
#endif
#ifndef  DEVICES_TIMER_H
#include "devices/timer.h"
#endif
#ifndef  LIBRARIES_DOSEXTENS_H
#include "libraries/dosextens.h"
#endif
#ifndef  INTUITION_INTUITION_H
#include "intuition/intuition.h"
#endif


struct DeviceData {
    struct Library dd_Device; /* standard library node */
    APTR dd_Segment;	      /* A0 when initialized */
    APTR dd_ExecBase;	      /* A6 for exec */
    APTR dd_CmdVectors;       /* command table for device commands */
    APTR dd_CmdBytes;	      /* bytes describing which command queue */
    UWORD   dd_NumCommands;   /* the number of commands supported */
};

#define P_OLDSTKSIZE	0x0800	/* stack size for child task (OBSOLETE) */
#define P_STKSIZE	0x1000	/* stack size for child task */
#define P_BUFSIZE	256	/* size of internal buffers for text i/o */
#define P_SAFESIZE	128	/* safety margin for text output buffer */

struct	 PrinterData {
	struct DeviceData pd_Device;
	struct MsgPort pd_Unit;	/* the one and only unit */
	BPTR pd_PrinterSegment;	/* the printer specific segment */
	UWORD pd_PrinterType;	/* the segment printer type */
				/* the segment data structure */
	struct PrinterSegment *pd_SegmentData;
	UBYTE *pd_PrintBuf;	/* the raster print buffer */
	int (*pd_PWrite)();	/* the write function */
	int (*pd_PBothReady)();	/* write function's done */
	union {			/* port I/O request 0 */
		struct IOExtPar pd_p0;
		struct IOExtSer pd_s0;
	} pd_ior0;

#define  pd_PIOR0 pd_ior0.pd_p0
#define  pd_SIOR0 pd_ior0.pd_s0

	union {			/*   and 1 for double buffering */
		struct IOExtPar pd_p1;
		struct IOExtSer pd_s1;
	} pd_ior1;

#define  pd_PIOR1 pd_ior1.pd_p1
#define  pd_SIOR1 pd_ior1.pd_s1

	struct timerequest pd_TIOR;	/* timer I/O request */
	struct MsgPort pd_IORPort;	/* and message reply port */
	struct Task pd_TC;		/* write task */
	UBYTE pd_OldStk[P_OLDSTKSIZE];	/* and stack space (OBSOLETE) */
	UBYTE pd_Flags;			/* device flags */
	UBYTE pd_pad;			/* padding */
	struct Preferences pd_Preferences;	/* the latest preferences */
	UBYTE pd_PWaitEnabled;		/* wait function switch */
	/* new fields for V2.0 */
	UBYTE pd_Flags1;		/* padding */
	UBYTE pd_Stk[P_STKSIZE];	/* stack space */
};

/* Printer Class */
#define PPCB_GFX	0	/* graphics (bit position) */
#define PPCF_GFX	0x1	/* graphics (and/or flag) */
#define PPCB_COLOR	1	/* color (bit position) */
#define PPCF_COLOR	0x2	/* color (and/or flag) */

#define PPC_BWALPHA	0x00	/* black&white alphanumerics */
#define PPC_BWGFX	0x01	/* black&white graphics */
#define PPC_COLORALPHA	0x02	/* color alphanumerics */
#define PPC_COLORGFX	0x03	/* color graphics */

/* Color Class */
#define	PCC_BW		0x01	/* black&white only */
#define	PCC_YMC		0x02	/* yellow/magenta/cyan only */
#define	PCC_YMC_BW	0x03	/* yellow/magenta/cyan or black&white */
#define	PCC_YMCB	0x04	/* yellow/magenta/cyan/black */
#define	PCC_4COLOR	0x04	/* a flag for YMCB and BGRW */
#define	PCC_ADDITIVE	0x08	/* not ymcb but blue/green/red/white */
#define	PCC_WB		0x09	/* black&white only, 0 == BLACK */
#define	PCC_BGR		0x0A	/* blue/green/red */
#define	PCC_BGR_WB	0x0B	/* blue/green/red or black&white */
#define	PCC_BGRW	0x0C	/* blue/green/red/white */
/*
	The picture must be scanned once for each color component, as the
	printer can only define one color at a time.  ie. If 'PCC_YMC' then
	first pass sends all 'Y' info to printer, second pass sends all 'M'
	info, and third pass sends all C info to printer.  The CalComp
	PlotMaster is an example of this type of printer.
*/
#define PCC_MULTI_PASS	0x10	/* see explanation above */

struct PrinterExtendedData {
	char	*ped_PrinterName;    /* printer name, null terminated */
	VOID	(*ped_Init)();	     /* called after LoadSeg */
	VOID	(*ped_Expunge)();    /* called before UnLoadSeg */
	int	(*ped_Open)();	     /* called at OpenDevice */
	VOID	(*ped_Close)();      /* called at CloseDevice */
	UBYTE	ped_PrinterClass;    /* printer class */
	UBYTE	ped_ColorClass;      /* color class */
	UBYTE	ped_MaxColumns;      /* number of print columns available */
	UBYTE	ped_NumCharSets;     /* number of character sets */
	UWORD	ped_NumRows;	     /* number of 'pins' in print head */
	ULONG	ped_MaxXDots;	     /* number of dots max in a raster dump */
	ULONG	ped_MaxYDots;	     /* number of dots max in a raster dump */
	UWORD	ped_XDotsInch;	     /* horizontal dot density */
	UWORD	ped_YDotsInch;	     /* vertical dot density */
	char	***ped_Commands;     /* printer text command table */
	int	(*ped_DoSpecial)();  /* special command handler */
	int	(*ped_Render)();     /* raster render function */
	LONG	ped_TimeoutSecs;     /* good write timeout */
	/* the following only exists if the segment version is >= 33 */
	char	**ped_8BitChars;     /* conv. strings for the extended font */
	LONG	ped_PrintMode;	     /* set if text printed, otherwise 0 */
	/* the following only exists if the segment version is >= 34 */
	/* ptr to conversion function for all chars */
	int	(*ped_ConvFunc)();
};

struct PrinterSegment {
    ULONG   ps_NextSegment;	 /* (actually a BPTR) */
    ULONG   ps_runAlert;	 /* MOVEQ #0,D0 : RTS */
    UWORD   ps_Version;	 /* segment version */
    UWORD   ps_Revision;	 /* segment revision */
    struct  PrinterExtendedData ps_PED;   /* printer extended data */
};
#endif

#ifndef     DEVICES_PRINTER_H
#define     DEVICES_PRINTER_H
/*
**	$Filename: devices/printer.h $
**	$Release: 2.04 Includes, V37.4 $
**	$Revision: 1.7 $
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

#ifndef  EXEC_NODES_H
#include "exec/nodes.h"
#endif

#ifndef  EXEC_LISTS_H
#include "exec/lists.h"
#endif

#ifndef  EXEC_PORTS_H
#include "exec/ports.h"
#endif

#define  PRD_RAWWRITE	   (CMD_NONSTD+0)
#define  PRD_PRTCOMMAND    (CMD_NONSTD+1)
#define  PRD_DUMPRPORT	   (CMD_NONSTD+2)
#define  PRD_QUERY	   (CMD_NONSTD+3)

/* printer command definitions */

#define aRIS	 0  /* ESCc  reset		      ISO */
#define aRIN	 1  /* ESC#1 initialize	      +++ */
#define aIND	 2  /* ESCD  lf		      ISO */
#define aNEL	 3  /* ESCE  return,lf		      ISO */
#define aRI	 4  /* ESCM  reverse lf	      ISO */

#define aSGR0	 5  /* ESC[0m normal char set	      ISO */
#define aSGR3	 6  /* ESC[3m italics on	      ISO */
#define aSGR23	 7  /* ESC[23m italics off	      ISO */
#define aSGR4	 8  /* ESC[4m underline on	      ISO */
#define aSGR24	 9  /* ESC[24m underline off	      ISO */
#define aSGR1	10  /* ESC[1m boldface on	      ISO */
#define aSGR22	11  /* ESC[22m boldface off	      ISO */
#define aSFC	12  /* SGR30-39  set foreground color ISO */
#define aSBC	13  /* SGR40-49  set background color ISO */

#define aSHORP0 14  /* ESC[0w normal pitch	      DEC */
#define aSHORP2 15  /* ESC[2w elite on		      DEC */
#define aSHORP1 16  /* ESC[1w elite off	      DEC */
#define aSHORP4 17  /* ESC[4w condensed fine on       DEC */
#define aSHORP3 18  /* ESC[3w condensed off	      DEC */
#define aSHORP6 19  /* ESC[6w enlarged on	      DEC */
#define aSHORP5 20  /* ESC[5w enlarged off	      DEC */

#define aDEN6	21  /* ESC[6"z shadow print on	      DEC (sort of) */
#define aDEN5	22  /* ESC[5"z shadow print off       DEC */
#define aDEN4	23  /* ESC[4"z doublestrike on	      DEC */
#define aDEN3	24  /* ESC[3"z doublestrike off       DEC */
#define aDEN2	25  /* ESC[2"z	NLQ on		      DEC */
#define aDEN1	26  /* ESC[1"z	NLQ off	      DEC */

#define aSUS2	27  /* ESC[2v superscript on	      +++ */
#define aSUS1	28  /* ESC[1v superscript off	      +++ */
#define aSUS4	29  /* ESC[4v subscript on	      +++ */
#define aSUS3	30  /* ESC[3v subscript off	      +++ */
#define aSUS0	31  /* ESC[0v normalize the line      +++ */
#define aPLU	32  /* ESCL  partial line up	      ISO */
#define aPLD	33  /* ESCK  partial line down	      ISO */

#define aFNT0	34  /* ESC(B US char set	or Typeface  0 (default) */
#define aFNT1	35  /* ESC(R French char set	or Typeface  1 */
#define aFNT2	36  /* ESC(K German char set	or Typeface  2 */
#define aFNT3	37  /* ESC(A UK char set	or Typeface  3 */
#define aFNT4	38  /* ESC(E Danish I char set	or Typeface  4 */
#define aFNT5	39  /* ESC(H Sweden char set	or Typeface  5 */
#define aFNT6	40  /* ESC(Y Italian char set	or Typeface  6 */
#define aFNT7	41  /* ESC(Z Spanish char set	or Typeface  7 */
#define aFNT8	42  /* ESC(J Japanese char set	or Typeface  8 */
#define aFNT9	43  /* ESC(6 Norweign char set	or Typeface  9 */
#define aFNT10	44  /* ESC(C Danish II char set or Typeface 10 */

/*
	Suggested typefaces are:

	 0 - default typeface.
	 1 - Line Printer or equiv.
	 2 - Pica or equiv.
	 3 - Elite or equiv.
	 4 - Helvetica or equiv.
	 5 - Times Roman or equiv.
	 6 - Gothic or equiv.
	 7 - Script or equiv.
	 8 - Prestige or equiv.
	 9 - Caslon or equiv.
	10 - Orator or equiv.
*/

#define aPROP2	45  /* ESC[2p  proportional on	      +++ */
#define aPROP1	46  /* ESC[1p  proportional off       +++ */
#define aPROP0	47  /* ESC[0p  proportional clear     +++ */
#define aTSS	48  /* ESC[n E set proportional offset ISO */
#define aJFY5	49  /* ESC[5 F auto left justify      ISO */
#define aJFY7	50  /* ESC[7 F auto right justify     ISO */
#define aJFY6	51  /* ESC[6 F auto full justify      ISO */
#define aJFY0	52  /* ESC[0 F auto justify off       ISO */
#define aJFY3	53  /* ESC[3 F letter space (justify) ISO (special) */
#define aJFY1	54  /* ESC[1 F word fill(auto center) ISO (special) */

#define aVERP0	55  /* ESC[0z  1/8" line spacing      +++ */
#define aVERP1	56  /* ESC[1z  1/6" line spacing      +++ */
#define aSLPP	57  /* ESC[nt  set form length n      DEC */
#define aPERF	58  /* ESC[nq  perf skip n (n>0)      +++ */
#define aPERF0	59  /* ESC[0q  perf skip off	      +++ */

#define aLMS	60  /* ESC#9   Left margin set	      +++ */
#define aRMS	61  /* ESC#0   Right margin set       +++ */
#define aTMS	62  /* ESC#8   Top margin set	      +++ */
#define aBMS	63  /* ESC#2   Bottom marg set	      +++ */
#define aSTBM	64  /* ESC[Pn1;Pn2r  T&B margins      DEC */
#define aSLRM	65  /* ESC[Pn1;Pn2s  L&R margin       DEC */
#define aCAM	66  /* ESC#3   Clear margins	      +++ */

#define aHTS	67  /* ESCH    Set horiz tab	      ISO */
#define aVTS	68  /* ESCJ    Set vertical tabs      ISO */
#define aTBC0	69  /* ESC[0g  Clr horiz tab	      ISO */
#define aTBC3	70  /* ESC[3g  Clear all h tab	      ISO */
#define aTBC1	71  /* ESC[1g  Clr vertical tabs      ISO */
#define aTBC4	72  /* ESC[4g  Clr all v tabs	      ISO */
#define aTBCALL 73  /* ESC#4   Clr all h & v tabs     +++ */
#define aTBSALL 74  /* ESC#5   Set default tabs       +++ */
#define aEXTEND 75  /* ESC[Pn"x extended commands     +++ */

#define aRAW	76	/* ESC[Pn"r	Next 'Pn' chars are raw +++ */

struct IOPrtCmdReq {
    struct  Message io_Message;
    struct  Device  *io_Device;     /* device node pointer  */
    struct  Unit    *io_Unit;	    /* unit (driver private)*/
    UWORD   io_Command;	    /* device command */
    UBYTE   io_Flags;
    BYTE    io_Error;		    /* error or warning num */
    UWORD   io_PrtCommand;	    /* printer command */
    UBYTE   io_Parm0;		    /* first command parameter */
    UBYTE   io_Parm1;		    /* second command parameter */
    UBYTE   io_Parm2;		    /* third command parameter */
    UBYTE   io_Parm3;		    /* fourth command parameter */
};

struct IODRPReq {
    struct  Message io_Message;
    struct  Device  *io_Device;     /* device node pointer  */
    struct  Unit    *io_Unit;	    /* unit (driver private)*/
    UWORD   io_Command;	    /* device command */
    UBYTE   io_Flags;
    BYTE    io_Error;		    /* error or warning num */
    struct  RastPort *io_RastPort;  /* raster port */
    struct  ColorMap *io_ColorMap;  /* color map */
    ULONG   io_Modes;		    /* graphics viewport modes */
    UWORD   io_SrcX;		    /* source x origin */
    UWORD   io_SrcY;		    /* source y origin */
    UWORD   io_SrcWidth;	    /* source x width */
    UWORD   io_SrcHeight;	    /* source x height */
    LONG    io_DestCols;	    /* destination x width */
    LONG    io_DestRows;	    /* destination y height */
    UWORD   io_Special;	    /* option flags */
};

#define SPECIAL_MILCOLS		0x0001	/* DestCols specified in 1/1000" */
#define SPECIAL_MILROWS		0x0002	/* DestRows specified in 1/1000" */
#define SPECIAL_FULLCOLS	0x0004	/* make DestCols maximum possible */
#define SPECIAL_FULLROWS	0x0008	/* make DestRows maximum possible */
#define SPECIAL_FRACCOLS	0x0010	/* DestCols is fraction of FULLCOLS */
#define SPECIAL_FRACROWS	0x0020	/* DestRows is fraction of FULLROWS */
#define SPECIAL_CENTER		0x0040	/* center image on paper */
#define SPECIAL_ASPECT		0x0080	/* ensure correct aspect ratio */
#define SPECIAL_DENSITY1	0x0100	/* lowest resolution (dpi) */
#define SPECIAL_DENSITY2	0x0200	/* next res */
#define SPECIAL_DENSITY3	0x0300	/* next res */
#define SPECIAL_DENSITY4	0x0400	/* next res */
#define SPECIAL_DENSITY5	0x0500	/* next res */
#define SPECIAL_DENSITY6	0x0600	/* next res */
#define SPECIAL_DENSITY7	0x0700	/* highest res */
#define SPECIAL_NOFORMFEED	0x0800	/* don't eject paper on gfx prints */
#define SPECIAL_TRUSTME		0x1000	/* don't reset on gfx prints */
/*
	Compute print size, set 'io_DestCols' and 'io_DestRows' in the calling
	program's 'IODRPReq' structure and exit, DON'T PRINT.  This allows the
	calling program to see what the final print size would be in printer
	pixels.  Note that it modifies the 'io_DestCols' and 'io_DestRows'
	fields of your 'IODRPReq' structure.  Also, set the print density and
	update the 'MaxXDots', 'MaxYDots', 'XDotsInch', and 'YDotsInch' fields
	of the 'PrinterExtendedData' structure.
*/
#define SPECIAL_NOPRINT		0x2000	/* see above */

#define PDERR_NOERR		0	/* clean exit, no errors */
#define PDERR_CANCEL		1	/* user cancelled print */
#define PDERR_NOTGRAPHICS	2	/* printer cannot output graphics */
#define PDERR_INVERTHAM		3	/* OBSOLETE */
#define PDERR_BADDIMENSION	4	/* print dimensions illegal */
#define PDERR_DIMENSIONOVFLOW	5	/* OBSOLETE */
#define PDERR_INTERNALMEMORY	6	/* no memory for internal variables */
#define PDERR_BUFFERMEMORY	7	/* no memory for print buffer */
/*
	Note : this is an internal error that can be returned from the render
	function to the printer device.  It is NEVER returned to the user.
	If the printer device sees this error it converts it 'PDERR_NOERR'
	and exits gracefully.  Refer to the document on
	'How to Write a Graphics Printer Driver' for more info.
*/
#define PDERR_TOOKCONTROL	8	/* Took control in case 0 of render */

/* internal use */
#define SPECIAL_DENSITYMASK	0x0700	/* masks out density values */
#define SPECIAL_DIMENSIONSMASK \
	(SPECIAL_MILCOLS|SPECIAL_MILROWS|SPECIAL_FULLCOLS|SPECIAL_FULLROWS\
	|SPECIAL_FRACCOLS|SPECIAL_FRACROWS|SPECIAL_ASPECT)
#endif

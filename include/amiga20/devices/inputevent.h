#ifndef DEVICES_INPUTEVENT_H
#define DEVICES_INPUTEVENT_H
/*
**	$Filename: devices/inputevent.h $
**	$Release: 2.04 Includes, V37.4 $
**	$Revision: 36.7 $
**	$Date: 91/01/22 $
**
**	input event definitions
**
**	(C) Copyright 1985-1991 Commodore-Amiga, Inc.
**	    All Rights Reserved
*/

#ifndef DEVICES_TIMER_H
#include "devices/timer.h"
#endif

/*----- constants --------------------------------------------------*/

/*  --- InputEvent.ie_Class --- */
/* A NOP input event */
#define IECLASS_NULL			0x00
/* A raw keycode from the keyboard device */
#define IECLASS_RAWKEY			0x01
/* The raw mouse report from the game port device */
#define IECLASS_RAWMOUSE		0x02
/* A private console event */
#define IECLASS_EVENT			0x03
/* A Pointer Position report */
#define IECLASS_POINTERPOS		0x04
/* A timer event */
#define IECLASS_TIMER			0x06
/* select button pressed down over a Gadget (address in ie_EventAddress) */
#define IECLASS_GADGETDOWN		0x07
/* select button released over the same Gadget (address in ie_EventAddress) */
#define IECLASS_GADGETUP		0x08
/* some Requester activity has taken place.  See Codes REQCLEAR and REQSET */
#define IECLASS_REQUESTER		0x09
/* this is a Menu Number transmission (Menu number is in ie_Code) */
#define IECLASS_MENULIST		0x0A
/* User has selected the active Window's Close Gadget */
#define IECLASS_CLOSEWINDOW		0x0B
/* this Window has a new size */
#define IECLASS_SIZEWINDOW		0x0C
/* the Window pointed to by ie_EventAddress needs to be refreshed */
#define IECLASS_REFRESHWINDOW		0x0D
/* new preferences are available */
#define IECLASS_NEWPREFS		0x0E
/* the disk has been removed */
#define IECLASS_DISKREMOVED		0x0F
/* the disk has been inserted */
#define IECLASS_DISKINSERTED		0x10
/* the window is about to be been made active */
#define IECLASS_ACTIVEWINDOW		0x11
/* the window is about to be made inactive */
#define IECLASS_INACTIVEWINDOW		0x12
/* extended-function pointer position report (V36) */
#define IECLASS_NEWPOINTERPOS		0x13
/* Help key report during Menu session (V36) */
#define IECLASS_MENUHELP		0x14
/* the Window has been modified with move, size, zoom, or change (V36) */
#define	IECLASS_CHANGEWINDOW		0x15

/* the last class */
#define IECLASS_MAX			0x15


/*  --- InputEvent.ie_SubClass --- */
/*  IECLASS_NEWPOINTERPOS */
/*	like IECLASS_POINTERPOS */
#define IESUBCLASS_COMPATIBLE	0x00
/*	ie_EventAddress points to struct IEPointerPixel */
#define IESUBCLASS_PIXEL	0x01
/*	ie_EventAddress points to struct IEPointerTablet */
#define IESUBCLASS_TABLET	0x02

/* pointed to by ie_EventAddress for IECLASS_NEWPOINTERPOS,
 * and IESUBCLASS_PIXEL.
 *
 * You specify a screen and pixel coordinates in that screen
 * at which you'd like the mouse to be positioned.
 * Intuition will try to oblige, but there will be restrictions
 * to positioning the pointer over offscreen pixels.
 *
 * IEQUALIFIER_RELATIVEMOUSE is supported for IESUBCLASS_PIXEL.
 */
struct IEPointerPixel	{
    struct Screen	*iepp_Screen;	/* pointer to an open screen */
    struct {				/* pixel coordinates in iepp_Screen */
	WORD	X;
	WORD	Y;
    }			iepp_Position;
};

/* pointed to by ie_EventAddress for IECLASS_NEWPOINTERPOS,
 * and IESUBCLASS_TABLET.
 *
 * You specify a range of values and a value within the range
 * independently for each of X and Y (the minimum value of
 * the ranges is always normalized to 0).
 *
 * Intuition will position the mouse proportionally within its
 * natural mouse position rectangle limits.
 *
 * IEQUALIFIER_RELATIVEMOUSE is not supported for IESUBCLASS_TABLET.
 */
struct IEPointerTablet	{
    struct {
	UWORD	X;
	UWORD	Y;
    }			iept_Range;	/* 0 is min, these are max	*/
    struct {
	UWORD	X;
	UWORD	Y;
    }			iept_Value;	/* between 0 and iept_Range	*/

    WORD		iept_Pressure;	/* -128 to 127 (unused, set to 0)  */
};



/*  --- InputEvent.ie_Code --- */
/*  IECLASS_RAWKEY */
#define IECODE_UP_PREFIX		0x80
#define IECODE_KEY_CODE_FIRST		0x00
#define IECODE_KEY_CODE_LAST		0x77
#define IECODE_COMM_CODE_FIRST		0x78
#define IECODE_COMM_CODE_LAST		0x7F

/*  IECLASS_ANSI */
#define IECODE_C0_FIRST			0x00
#define IECODE_C0_LAST			0x1F
#define IECODE_ASCII_FIRST		0x20
#define IECODE_ASCII_LAST		0x7E
#define IECODE_ASCII_DEL		0x7F
#define IECODE_C1_FIRST			0x80
#define IECODE_C1_LAST			0x9F
#define IECODE_LATIN1_FIRST		0xA0
#define IECODE_LATIN1_LAST		0xFF

/*  IECLASS_RAWMOUSE */
#define IECODE_LBUTTON			0x68	/* also uses IECODE_UP_PREFIX */
#define IECODE_RBUTTON			0x69
#define IECODE_MBUTTON			0x6A
#define IECODE_NOBUTTON			0xFF

/*  IECLASS_EVENT (V36) */
#define IECODE_NEWACTIVE		0x01	/* new active input window */
#define IECODE_NEWSIZE			0x02	/* resize of window */
#define IECODE_REFRESH			0x03	/* refresh of window */

/*  IECLASS_REQUESTER */
/*	broadcast when the first Requester (not subsequent ones) opens up in */
/*	the Window */
#define IECODE_REQSET			0x01
/*	broadcast when the last Requester clears out of the Window */
#define IECODE_REQCLEAR			0x00



/*  --- InputEvent.ie_Qualifier --- */
#define IEQUALIFIER_LSHIFT		0x0001
#define IEQUALIFIER_RSHIFT		0x0002
#define IEQUALIFIER_CAPSLOCK		0x0004
#define IEQUALIFIER_CONTROL		0x0008
#define IEQUALIFIER_LALT		0x0010
#define IEQUALIFIER_RALT		0x0020
#define IEQUALIFIER_LCOMMAND		0x0040
#define IEQUALIFIER_RCOMMAND		0x0080
#define IEQUALIFIER_NUMERICPAD		0x0100
#define IEQUALIFIER_REPEAT		0x0200
#define IEQUALIFIER_INTERRUPT		0x0400
#define IEQUALIFIER_MULTIBROADCAST	0x0800
#define IEQUALIFIER_MIDBUTTON		0x1000
#define IEQUALIFIER_RBUTTON		0x2000
#define IEQUALIFIER_LEFTBUTTON		0x4000
#define IEQUALIFIER_RELATIVEMOUSE	0x8000

#define IEQUALIFIERB_LSHIFT		0
#define IEQUALIFIERB_RSHIFT		1
#define IEQUALIFIERB_CAPSLOCK		2
#define IEQUALIFIERB_CONTROL		3
#define IEQUALIFIERB_LALT		4
#define IEQUALIFIERB_RALT		5
#define IEQUALIFIERB_LCOMMAND		6
#define IEQUALIFIERB_RCOMMAND		7
#define IEQUALIFIERB_NUMERICPAD		8
#define IEQUALIFIERB_REPEAT		9
#define IEQUALIFIERB_INTERRUPT		10
#define IEQUALIFIERB_MULTIBROADCAST	11
#define IEQUALIFIERB_MIDBUTTON		12
#define IEQUALIFIERB_RBUTTON		13
#define IEQUALIFIERB_LEFTBUTTON		14
#define IEQUALIFIERB_RELATIVEMOUSE	15

/*----- InputEvent -------------------------------------------------*/

struct InputEvent {
    struct  InputEvent *ie_NextEvent;	/* the chronologically next event */
    UBYTE   ie_Class;			/* the input event class */
    UBYTE   ie_SubClass;		/* optional subclass of the class */
    UWORD   ie_Code;			/* the input event code */
    UWORD   ie_Qualifier;		/* qualifiers in effect for the event*/
    union {
	struct {
	    WORD    ie_x;		/* the pointer position for the event*/
	    WORD    ie_y;
	} ie_xy;
	APTR	ie_addr;		/* the event address */
	struct {
	    UBYTE   ie_prev1DownCode;	/* previous down keys for dead */
	    UBYTE   ie_prev1DownQual;	/*   key translation: the ie_Code */
	    UBYTE   ie_prev2DownCode;	/*   & low byte of ie_Qualifier for */
	    UBYTE   ie_prev2DownQual;	/*   last & second last down keys */
	} ie_dead;
    } ie_position;
    struct timeval ie_TimeStamp;	/* the system tick at the event */
};

#define	ie_X			ie_position.ie_xy.ie_x
#define	ie_Y			ie_position.ie_xy.ie_y
#define	ie_EventAddress		ie_position.ie_addr
#define	ie_Prev1DownCode	ie_position.ie_dead.ie_prev1DownCode
#define	ie_Prev1DownQual	ie_position.ie_dead.ie_prev1DownQual
#define	ie_Prev2DownCode	ie_position.ie_dead.ie_prev2DownCode
#define	ie_Prev2DownQual	ie_position.ie_dead.ie_prev2DownQual

#endif	/* DEVICES_INPUTEVENT_H */

#ifndef	LIBRARIES_ASL_H
#define	LIBRARIES_ASL_H	1

/*
**	$Filename: libraries/asl.h $
**	$Release: 2.04 Includes, V37.4 $
**	$Revision: 36.5 $
**	$Date: 91/11/08 $
**
**	ASL library name and useful definitions.
**
**	(C) Copyright 1989,1990 Charlie Heath
**	(C) Copyright 1989-1991 Commodore-Amiga, Inc.
**		All Rights Reserved
*/

#ifndef	EXEC_TYPES_H
#include	<exec/types.h>
#endif

#ifndef	EXEC_LISTS_H
#include	<exec/lists.h>
#endif

#ifndef	EXEC_LIBRARIES_H
#include	<exec/libraries.h>
#endif

#ifndef UTILITY_HOOKS_H
#include <utility/hooks.h>
#endif

#ifndef UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif

#ifndef WBArg
#include <workbench/startup.h>
#endif

#ifndef GRAPHICS_TEXT_H
#include <graphics/text.h>
#endif

/*
 ************************************************************************
 *	Standard definitions for asl library information		*
 ************************************************************************
 */

#define	AslName		"asl.library"

/*
 ************************************************************************
 *									*
 *	The ASL file requester data structure...			*
 *									*
 * The fields described here are for READ ACCESS to the structure	*
 * returned by AllocAslRequest( ASL_FileRequest, ... )			*
 *									*
 * Any modifications MUST be done via TAGS either at the time of	*
 * creation by AllocAslRequest(), or when used, via AslRequest()	*
 *									*
 ************************************************************************
 */
struct FileRequester	{
	APTR	rf_Reserved1;
	BYTE	*rf_File;	/* Filename pointer		*/
	BYTE	*rf_Dir;	/* Directory name pointer	*/
	CPTR	rf_Reserved2;
	UBYTE	rf_Reserved3;
	UBYTE	rf_Reserved4;
	APTR	rf_Reserved5;
	WORD	rf_LeftEdge,rf_TopEdge;	/* Preferred window pos	*/
	WORD	rf_Width,rf_Height;   /* Preferred window size	*/
	WORD	rf_Reserved6;
	LONG	rf_NumArgs;	/* A-la WB Args, for multiselects */
	struct WBArg *rf_ArgList;
	APTR	rf_UserData;	/* Applihandle (you may write!!) */
	APTR	rf_Reserved7;
	APTR	rf_Reserved8;
	BYTE	*rf_Pat;	/* Pattern match pointer */
	};			/* note - more reserved fields follow */


/*
 * The following defined values are the ASL_FuncFlags tag values which
 * are defined for the ASL file request.  These values may be passed
 * as a TagItem to modify the way the requester is presented.  Each
 * flag value defined has a description of the particular action.
 *
 * Also related to the ASL_FuncFlags values is the ASL_HookFunc tagitem,
 * which provides a callback function pointer to allow the application
 * to interact with the requester.  If an ASL_HookFunc TagItem is
 * provided, the hook function will be called like so:
 *
 * ULONG rf_Function(ULONG Mask, CPTR Object, CPTR AslRequester)
 *
 * The Mask value is a copy of the specific ASL_FuncFlags value
 * the callback is for; Object is a pointer to a data object.
 * AslRequester is a pointer to the requester structure.
 *
 * For the ASL file and font requesters, two ASL_FuncFlags values
 * are currently defined; FILF_DOWILDFUNC and FILF_DOMSGFUNC.
 *
 */

#define	FILB_DOWILDFUNC	7L /* Called with an Object=AnchorPath,	*/
			   /*		 ZERO return accepts.	*/
#define	FILB_DOMSGFUNC	6L /* Called with Object=IDCMP message	*/
			   /*  for other window of shared port. */
			   /* You must return pointer to Object,*/
			   /* asl will reply the Object for you */
#define	FILB_SAVE	5L /* For a SAVE operation, set this bit */
#define	FILB_NEWIDCMP	4L /* Force a new IDCMP (only if rf_Window != NULL)  */
#define FILB_MULTISELECT 3L /* Request multiple selections returned from FR. */
			   /*	MULISELECT is ignored if FILB_SAVE is on     */
#define	FILB_PATGAD	0L /* Ask for pattern gadget			     */


#define	FILF_DOWILDFUNC	(1L << FILB_DOWILDFUNC)
#define	FILF_DOMSGFUNC	(1L << FILB_DOMSGFUNC)

#define	FILF_SAVE	(1L << FILB_SAVE)
#define	FILF_NEWIDCMP	(1L << FILB_NEWIDCMP)
#define	FILF_MULTISELECT (1L << FILB_MULTISELECT)
#define	FILF_PATGAD	(1L << FILB_PATGAD)


/* The following additional flags may be passed with the
 * ASL_ExtFlags1 tag.
 */
#define	FIL1B_NOFILES	0L /* Do not want a file gadget, no files shown      */
#define	FIL1B_MATCHDIRS	1L /* Have Patgad or rf_Pat screen files AND DIRS    */

#define	FIL1F_NOFILES	(1L << FIL1B_NOFILES)
#define	FIL1F_MATCHDIRS	(1L << FIL1B_MATCHDIRS)


/*
 ************************************************************************
 *	The ASL font requester data structure...			*
 *									*
 * As with the FileRequest structure, the fields documented here are	*
 * for READ ACCESS ONLY.  Any modifications must be done via tags.	*
 ************************************************************************
 */
struct FontRequester	{
	APTR	fo_Reserved1[2];
	struct TextAttr fo_Attr;	/* Returned TextAttr		*/
	UBYTE	fo_FrontPen;		/* Returned pens, if selected	*/
	UBYTE	fo_BackPen;
	UBYTE	fo_DrawMode;
	APTR	fo_UserData;
	};

/* Bit defines for ASL_FuncFlags, for FONT requester			*/
/* See descriptive text for FILF_ values above for an overview.		*/
/* Note - old mixed-case defines were nonstandard, now obsolete		*/

#define	FONB_FRONTCOLOR	0	/* Display Front color selector?	*/
#define	FONB_BACKCOLOR	1	/* Display Back color selector?		*/
#define	FONB_STYLES	2	/* Display Styles checkboxes?		*/
#define	FONB_DRAWMODE	3	/* Display DrawMode NWay?		*/
#define	FONB_FIXEDWIDTH	4	/* Only allow fixed-width fonts?	*/
#define	FONB_NEWIDCMP	5	/* Create a new IDCMP port, not shared	*/
#define	FONB_DOMSGFUNC	6	/* Called with Object=IntuiMessage for	*/
				/*	other windows in shared port,	*/
				/*   you must return Object pointer	*/
				/*   and asl will reply Object for you	*/
#define	FONB_DOWILDFUNC	7	/* Called with Object=TextAttr to approve*/
				/*	NON-Zero return accepts		*/

#define	FONF_FRONTCOLOR	(1L << FONB_FRONTCOLOR)
#define	FONF_BACKCOLOR	(1L << FONB_BACKCOLOR)
#define	FONF_STYLES	(1L << FONB_STYLES)
#define	FONF_DRAWMODE	(1L << FONB_DRAWMODE)
#define	FONF_FIXEDWIDTH	(1L << FONB_FIXEDWIDTH)
#define	FONF_NEWIDCMP	(1L << FONB_NEWIDCMP)
#define	FONF_DOMSGFUNC	(1L << FONB_DOMSGFUNC)
#define	FONF_DOWILDFUNC	(1L << FONB_DOWILDFUNC)


/************************************************************************/
/* Arguments to AllocAslRequest()					*/
/* Types of requester structures which may be allocated:		*/
/************************************************************************/
#define	ASL_FileRequest	0
#define	ASL_FontRequest	1

/************************************************************************/
/* Tags for AllocAslRequest() and AslRequest()				*/
/************************************************************************/

#define ASL_Dummy (TAG_USER + 0x80000)

#define ASL_Hail	ASL_Dummy+1	/* Hailing text follows		     */
#define ASL_Window	ASL_Dummy+2	/* Parent window for IDCMP & screen  */
#define	ASL_LeftEdge	ASL_Dummy+3	/* Initialize LeftEdge		     */
#define	ASL_TopEdge	ASL_Dummy+4	/* Initialize TopEdge		     */
#define	ASL_Width	ASL_Dummy+5
#define	ASL_Height	ASL_Dummy+6
#define	ASL_HookFunc	ASL_Dummy+7	/* Hook function pointer	     */

/* Tags specific to file request					     */
#define	ASL_File	ASL_Dummy+8	/* Initial name of file follows	     */
#define	ASL_Dir		ASL_Dummy+9	/* Initial string of filerequest dir */

/* Tags specific to font request					     */
#define	ASL_FontName	ASL_Dummy+10	/* Initial font name		     */
#define	ASL_FontHeight	ASL_Dummy+11	/* Initial font height		     */
#define	ASL_FontStyles	ASL_Dummy+12	/* Initial font styles		     */
#define	ASL_FontFlags	ASL_Dummy+13	/* Initial font flags for textattr   */
#define	ASL_FrontPen	ASL_Dummy+14	/* Initial frontpen color	     */
#define	ASL_BackPen	ASL_Dummy+15	/* Initial backpen color	     */
#define	ASL_MinHeight	ASL_Dummy+16	/* Minimum font height to display    */
#define	ASL_MaxHeight	ASL_Dummy+17	/* Max font height to display	     */

#define	ASL_OKText	ASL_Dummy+18	/* Text displayed in OK gadget	     */
#define	ASL_CancelText	ASL_Dummy+19	/* Text displayed in CANCEL gadget   */
#define	ASL_FuncFlags	ASL_Dummy+20	/* Function flags, depend on request */

#define	ASL_ModeList	ASL_Dummy+21	/* Substitute list for font drawmodes */
#define	ASL_ExtFlags1	ASL_Dummy+22	/* For passing extended FIL1F flags   */

#define	ASL_Pattern	ASL_FontName	/* File requester pattern string     */

/******** END of ASL Tag values	*****************************************/

#endif

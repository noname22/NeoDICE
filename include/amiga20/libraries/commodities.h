#ifndef LIBRARIES_COMMODITIES_H
#define LIBRARIES_COMMODITIES_H

/*
**   $Filename: libraries/commodities.h $
**   $Release: 2.04 Includes, V37.4 $
**   $Revision: 37.1 $
**   $Date: 91/04/15 $
**
**   Commodities definitions.
**
**   (C) Copyright 1988-1991 Commodore-Amiga Inc.
**	All Rights Reserved
*/

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

/*************************
 * object creation macros
 *************************/
#define CxFilter(d)	    CreateCxObj((LONG)CX_FILTER, (LONG) d, 0)
#define CxTypeFilter(type)  CreateCxObj((LONG)CX_TYPEFILTER, (LONG) type, 0)
#define CxSender(port,id)   CreateCxObj((LONG)CX_SEND, (LONG) port, (LONG) id)
#define CxSignal(task,sig)  CreateCxObj((LONG)CX_SIGNAL,(LONG) task, (LONG) sig)
#define CxTranslate(ie)     CreateCxObj((LONG)CX_TRANSLATE, (LONG) ie, 0)
#define CxDebug(id)	    CreateCxObj((LONG)CX_DEBUG, (LONG) id, 0)
#define CxCustom(action,id) CreateCxObj((LONG)CX_CUSTOM,(LONG)action,(LONG)id)

/***************
 * Broker stuff
 ***************/

/* buffer sizes   */
#define CBD_NAMELEN	24
#define CBD_TITLELEN	40
#define CBD_DESCRLEN	40

/* CxBroker errors   */
#define CBERR_OK	0	 /* No error			     */
#define CBERR_SYSERR	1	 /* System error , no memory, etc    */
#define CBERR_DUP	2	 /* uniqueness violation	     */
#define CBERR_VERSION	3	 /* didn't understand nb_VERSION     */

#define NB_VERSION	5	 /* Version of NewBroker structure   */

struct NewBroker {
   BYTE     nb_Version;	 /* set to NB_VERSION		     */
   BYTE     *nb_Name;
   BYTE     *nb_Title;
   BYTE     *nb_Descr;
   SHORT    nb_Unique;
   SHORT    nb_Flags;
   BYTE     nb_Pri;
   struct MsgPort   *nb_Port;
   WORD     nb_ReservedChannel;  /* plans for later port sharing     */
};

/* Flags for nb_Unique */
#define NBU_DUPLICATE	0
#define NBU_UNIQUE	1	 /* will not allow duplicates	     */
#define NBU_NOTIFY	2	 /* sends CXM_UNIQUE to existing broker */

/* Flags for nb_Flags */
#define   COF_SHOW_HIDE 4

/********
 * cxusr
 ********/

/** Fake data types for system private objects	 */
#ifndef CX_H
typedef LONG   CxObj;
typedef LONG   CxMsg;
#endif

/* Pointer to Function returning Long	*/
typedef LONG   (*PFL)();

/********************************/
/** Commodities Object Types   **/
/********************************/
#define CX_INVALID	0     /* not a valid object (probably null)  */
#define CX_FILTER	1     /* input event messages only	     */
#define CX_TYPEFILTER	2     /* filter on message type	     */
#define CX_SEND	3     /* sends a message		     */
#define CX_SIGNAL	4     /* sends a signal		     */
#define CX_TRANSLATE	5     /* translates IE into chain	     */
#define CX_BROKER	6     /* application representative	     */
#define CX_DEBUG	7     /* dumps kprintf to serial port	     */
#define CX_CUSTOM	8     /* application provids function	     */
#define CX_ZERO	9     /* system terminator node	     */

/*****************/
/** CxMsg types **/
/*****************/
#define CXM_UNIQUE   (1 << 4) /* sent down broker by CxBroker()      */
/* Obsolete: subsumed by CXM_COMMAND (below)   */

/* Messages of this type rattle around the Commodities input network.
 * They will be sent to you by a Sender object, and passed to you
 * as a synchronous function call by a Custom object.
 *
 * The message port or function entry point is stored in the object,
 * and the ID field of the message will be set to what you arrange
 * issuing object.
 *
 * The Data field will point to the input event triggering the
 * message.
 */
#define CXM_IEVENT   (1 << 5)

/* These messages are sent to a port attached to your Broker.
 * They are sent to you when the controller program wants your
 * program to do something.  The ID field identifies the command.
 *
 * The Data field will be used later.
 */
#define CXM_COMMAND   (1 << 6)

/* ID values   */
#define CXCMD_DISABLE	(15)  /* please disable yourself       */
#define CXCMD_ENABLE	(17)  /* please enable yourself        */
#define CXCMD_APPEAR	(19)  /* open your window, if you can  */
#define CXCMD_DISAPPEAR (21)  /* go dormant		       */
#define CXCMD_KILL	(23)  /* go away for good	       */
#define CXCMD_UNIQUE	(25)  /* someone tried to create a broker
			       * with your name.  Suggest you Appear.
			       */
#define CXCMD_LIST_CHG	(27)  /* Used by Exchange program. Someone */
			      /* has changed the broker list	   */

/* return values for BrokerCommand(): */
#define CMDE_OK	(0)
#define CMDE_NOBROKER	(-1)
#define CMDE_NOPORT	(-2)
#define CMDE_NOMEM	(-3)

/* IMPORTANT NOTE:
 * Only CXM_IEVENT messages are passed through the input network.
 *
 * Other types of messages are sent to an optional port in your broker.
 *
 * This means that you must test the message type in your message handling,
 * if input messages and command messages come to the same port.
 *
 * Older programs have no broker port, so processing loops which
 * make assumptions about type won't encounter the new message types.
 *
 * The TypeFilter CxObject is hereby obsolete.
 *
 * It is less convenient for the application, but eliminates testing
 * for type of input messages.
 */

/**********************************************************/
/** CxObj Error Flags (return values from CxObjError())  **/
/**********************************************************/
#define COERR_ISNULL	   1  /* you called CxError(NULL)	     */
#define COERR_NULLATTACH   2  /* someone attached NULL to my list    */
#define COERR_BADFILTER    4  /* a bad filter description was given  */
#define COERR_BADTYPE	   8  /* unmatched type-specific operation   */


/*****
 * ix
 *****/

#define IX_VERSION   2

struct InputXpression {
   UBYTE   ix_Version;	   /* must be set to IX_VERSION  */
   UBYTE   ix_Class;	   /* class must match exactly	 */

   UWORD   ix_Code;
   UWORD   ix_CodeMask;    /* normally used for UPCODE	 */

   UWORD   ix_Qualifier;
   UWORD   ix_QualMask;
   UWORD   ix_QualSame;    /* synonyms in qualifier	 */
   };
typedef struct InputXpression IX;

/* QualSame identifiers */
#define IXSYM_SHIFT  1	   /* left- and right- shift are equivalent	*/
#define IXSYM_CAPS   2	   /* either shift or caps lock are equivalent	*/
#define IXSYM_ALT    4	   /* left- and right- alt are equivalent	*/

/* corresponding QualSame masks */
#define IXSYM_SHIFTMASK (IEQUALIFIER_LSHIFT | IEQUALIFIER_RSHIFT)
#define IXSYM_CAPSMASK	(IXSYM_SHIFTMASK    | IEQUALIFIER_CAPSLOCK)
#define IXSYM_ALTMASK	(IEQUALIFIER_LALT   | IEQUALIFIER_RALT)

#define IX_NORMALQUALS	0x7FFF;/* for QualMask field: avoid RELATIVEMOUSE */

/* matches nothing   */
#define NULL_IX(I)   ((I)->ix_Class == IECLASS_NULL)

#endif

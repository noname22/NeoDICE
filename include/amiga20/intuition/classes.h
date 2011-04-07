#ifndef	INTUITION_CLASSES_H
#define INTUITION_CLASSES_H	1
/*
**  $Filename: intuition/classes.h $
**  $Release: 2.04 Includes, V37.4 $
**  $Revision: 36.2 $
**  $Date: 91/11/08 $
**
**  Used only by class implementors
**
**  (C) Copyright 1989-1991 Commodore-Amiga, Inc.
**	    All Rights Reserved
*/

#ifndef UTILITY_HOOKS_H
#include <utility/hooks.h>
#endif

#ifndef	INTUITION_CLASSUSR_H
#include <intuition/classusr.h>
#endif

/*******************************************/
/*** "White box" access to struct IClass ***/
/*******************************************/

/* This structure is READ-ONLY, and allocated only by Intuition */
typedef struct IClass {
    struct Hook		cl_Dispatcher;
    ULONG		cl_Reserved;	/* must be 0  */
    struct IClass	*cl_Super;
    ClassID		cl_ID;

    /* where within an object is the instance data for this class? */
    UWORD		cl_InstOffset;
    UWORD		cl_InstSize;

    ULONG		cl_UserData;	/* per-class data of your choice */
    ULONG		cl_SubclassCount;
					/* how many direct subclasses?	*/
    ULONG		cl_ObjectCount;
				/* how many objects created of this class? */
    ULONG		cl_Flags;
#define	CLF_INLIST	0x00000001	/* class is in public class list */
} Class;

/* add offset for instance data to an object handle */
#define INST_DATA( cl, o )	((VOID *) (((UBYTE *)o)+cl->cl_InstOffset))

/* sizeof the instance data for a given class */
#define SIZEOF_INSTANCE( cl )	((cl)->cl_InstOffset + (cl)->cl_InstSize \
			+ sizeof (struct _Object ))

/**************************************************/
/*** "White box" access to struct _Object	***/
/**************************************************/

/*
 * We have this, the instance data of the root class, PRECEDING
 * the "object".  This is so that Gadget objects are Gadget pointers,
 * and so on.  If this structure grows, it will always have o_Class
 * at the end, so the macro OCLASS(o) will always have the same
 * offset back from the pointer returned from NewObject().
 *
 * This data structure is subject to change.  Do not use the o_Node
 * embedded structure.
 */
struct _Object {
    struct MinNode	o_Node;
    struct IClass	*o_Class;
};

/* convenient typecast	*/
#define _OBJ( o )	((struct _Object *)(o))

/* get "public" handle on baseclass instance from real beginning of obj data */
#define BASEOBJECT( _obj )	( (Object *) (_OBJ(_obj)+1) )

/* get back to object data struct from public handle */
#define _OBJECT( o )		(_OBJ(o) - 1)

/* get class pointer from an object handle	*/
#define OCLASS( o )	( (_OBJECT(o))->o_Class )

#endif

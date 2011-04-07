#ifndef	GRAPHICS_GRAPHINT_H
#define	GRAPHICS_GRAPHINT_H
/*
**	$Filename: graphics/graphint.h $
**	$Release: 2.04 Includes, V37.4 $
**	$Revision: 37.0 $
**	$Date: 91/01/07 $
**
**
**
**	(C) Copyright 1985-1991 Commodore-Amiga, Inc.
**	    All Rights Reserved
*/

#ifndef EXEC_NODES_H
#include <exec/nodes.h>
#endif

/* structure used by AddTOFTask */
struct Isrvstr
{
    struct Node is_Node;
    struct Isrvstr *Iptr;   /* passed to srvr by os */
    int (*code)();
    int (*ccode)();
    int Carg;
};

#endif	/* GRAPHICS_GRAPHINT_H */

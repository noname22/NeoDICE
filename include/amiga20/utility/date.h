#ifndef UTILITY_DATE_H
#define UTILITY_DATE_H 1
/*
**	$Filename: utility/date.h $
**	$Release: 2.04 Includes, V37.4 $
**	$Revision: 36.2 $
**	$Date: 91/03/04 $
**
**	Date conversion routines ClockData definition.
**
**	(C) Copyright 1989-1991 Commodore-Amiga Inc.
**		All Rights Reserved
*/

#ifndef EXEC_TYPES_H
#include "exec/types.h"
#endif

struct ClockData
	{
	UWORD sec;
	UWORD min;
	UWORD hour;
	UWORD mday;
	UWORD month;
	UWORD year;
	UWORD wday;
	};

#endif

#ifndef	LIBRARIES_MATHFFP_H
#define	LIBRARIES_MATHFFP_H 1
/*
**	$Filename: libraries/mathffp.h $
**	$Release: 2.04 Includes, V37.4 $
**	$Revision: 36.2 $
**	$Date: 90/05/01 $
**
**	general floating point declarations
**
**	(C) Copyright 1985-1991 Commodore-Amiga, Inc.
**	    All Rights Reserved
*/

#ifndef PI
#define PI	  ((float) 3.141592653589793)
#endif
#define TWO_PI	  (((float) 2) * PI)
#define PI2	  (PI / ((float) 2))
#define PI4	  (PI / ((float) 4))
#ifndef E
#define E	  ((float) 2.718281828459045)
#endif
#define LOG10	  ((float) 2.302585092994046)

#define FPTEN	  ((float) 10.0)
#define FPONE	  ((float) 1.0)
#define FPHALF	  ((float) 0.5)
#define FPZERO	  ((float) 0.0)

#define trunc(x)  ((int) (x))
#define round(x)  ((int) ((x) + 0.5))
#define itof(i)   ((float) (i))

#endif	/* LIBRARIES_MATHFFP_H */

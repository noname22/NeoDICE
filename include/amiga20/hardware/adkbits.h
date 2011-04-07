#ifndef	HARDWARE_ADKBITS_H
#define	HARDWARE_ADKBITS_H
/*
**	$Filename: hardware/adkbits.h $
**	$Release: 2.04 Includes, V37.4 $
**	$Revision: 36.2 $
**	$Date: 90/07/10 $
**
**	bit definitions for adkcon register
**
**	(C) Copyright 1985-1991 Commodore-Amiga, Inc.
**	    All Rights Reserved
*/

#define  ADKB_SETCLR	15 /* standard set/clear bit */
#define  ADKB_PRECOMP1	14 /* two bits of precompensation */
#define  ADKB_PRECOMP0	13
#define  ADKB_MFMPREC	12 /* use mfm style precompensation */
#define  ADKB_UARTBRK	11 /* force uart output to zero */
#define  ADKB_WORDSYNC	10 /* enable DSKSYNC register matching */
#define  ADKB_MSBSYNC	9  /* (Apple GCR Only) sync on MSB for reading */
#define  ADKB_FAST	8  /* 1 -> 2 us/bit (mfm), 2 -> 4 us/bit (gcr) */
#define  ADKB_USE3PN	7  /* use aud chan 3 to modulate period of ?? */
#define  ADKB_USE2P3	6  /* use aud chan 2 to modulate period of 3 */
#define  ADKB_USE1P2	5  /* use aud chan 1 to modulate period of 2 */
#define  ADKB_USE0P1	4  /* use aud chan 0 to modulate period of 1 */
#define  ADKB_USE3VN	3  /* use aud chan 3 to modulate volume of ?? */
#define  ADKB_USE2V3	2  /* use aud chan 2 to modulate volume of 3 */
#define  ADKB_USE1V2	1  /* use aud chan 1 to modulate volume of 2 */
#define  ADKB_USE0V1	0  /* use aud chan 0 to modulate volume of 1 */

#define  ADKF_SETCLR	(1<<15)
#define  ADKF_PRECOMP1	(1<<14)
#define  ADKF_PRECOMP0	(1<<13)
#define  ADKF_MFMPREC	(1<<12)
#define  ADKF_UARTBRK	(1<<11)
#define  ADKF_WORDSYNC	(1<<10)
#define  ADKF_MSBSYNC	(1<<9)
#define  ADKF_FAST	(1<<8)
#define  ADKF_USE3PN	(1<<7)
#define  ADKF_USE2P3	(1<<6)
#define  ADKF_USE1P2	(1<<5)
#define  ADKF_USE0P1	(1<<4)
#define  ADKF_USE3VN	(1<<3)
#define  ADKF_USE2V3	(1<<2)
#define  ADKF_USE1V2	(1<<1)
#define  ADKF_USE0V1	(1<<0)

#define ADKF_PRE000NS	0			/* 000 ns of precomp */
#define ADKF_PRE140NS	(ADKF_PRECOMP0)	/* 140 ns of precomp */
#define ADKF_PRE280NS	(ADKF_PRECOMP1)	/* 280 ns of precomp */
#define ADKF_PRE560NS	(ADKF_PRECOMP0|ADKF_PRECOMP1) /* 560 ns of precomp */

#endif	/* HARDWARE_ADKBITS_H */

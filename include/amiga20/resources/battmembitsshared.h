#ifndef RESOURCES_BATTMEMBITSSHARED_H
#define RESOURCES_BATTMEMBITSSHARED_H 1
/*
**	$Filename: resources/battmembitsshared.h $
**	$Release: 2.04 Includes, V37.4 $
**	$Revision: 1.1 $
**	$Date: 90/05/25 $
**
**	BattMem shared specific bit definitions.
**
**	(C) Copyright 1989-1991 Commodore-Amiga Inc.
**		All Rights Reserved
*/


/*
 * Shared bits in the battery-backedup ram.
 *
 *	Bits 64 and above
 */

/*
 * SHARED_AMNESIA
 *
 *		The battery-backedup memory has had a memory loss.
 *		This bit is used as a flag that the user should be
 *		notified that all battery-backed bit have been
 *		reset and that some attention is required. Zero
 *		indicates that a memory loss has occured.
 */

#define BATTMEM_SHARED_AMNESIA_ADDR	64
#define BATTMEM_SHARED_AMNESIA_LEN	1


/*
 * SCSI_HOST_ID
 *
 *		a 3 bit field (0-7) that is stored in complemented form
 *		(this is so that default value of 0 really means 7)
 *		It's used to set the A3000 controllers SCSI ID (on reset)
 */

#define BATTMEM_SCSI_HOST_ID_ADDR	65
#define BATTMEM_SCSI_HOST_ID_LEN	3


/*
 * SCSI_SYNC_XFER
 *
 *		determines if the driver should initiate synchronous
 *		transfer requests or leave it to the drive to send the
 *		first request.	This supports drives that crash or
 *		otherwise get confused when presented with a sync xfer
 *		message.  Default=0=sync xfer not initiated.
 */

#define BATTMEM_SCSI_SYNC_XFER_ADDR	68
#define BATTMEM_SCSI_SYNC_XFER_LEN	1


#endif /* RESOURCES_BATTMEMBITSSHARED_H */

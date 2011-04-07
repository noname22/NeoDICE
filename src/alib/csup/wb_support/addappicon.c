
/* Workbench tag call */

#include <exec/types.h>
#include <clib/wb_protos.h>

#ifndef HYPER
#define HYPER
#endif

typedef struct TagItem	 TagItem;

struct AppIcon *
HYPER ## AddAppIcon( unsigned long id, unsigned long userdata,
	UBYTE *text, struct MsgPort *msgport, struct FileLock *lock,
	struct DiskObject *diskobj, Tag tag1, ... )
{
	return AddAppIconA(id, userdata, text, msgport, lock, diskobj, (TagItem *)&tag1);
}

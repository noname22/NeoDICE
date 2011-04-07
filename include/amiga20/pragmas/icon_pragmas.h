/* "icon.library"*/
/*--- functions in V36 or higher (distributed as Release 2.0) ---*/
/*	Use DiskObjects instead of obsolete WBObjects*/
/*pragma libcall IconBase iconPrivate1 1E 0*/
/*pragma libcall IconBase iconPrivate2 24 0*/
#pragma libcall IconBase GetIcon 2A A9803
#pragma libcall IconBase PutIcon 30 9802
#pragma libcall IconBase FreeFreeList 36 801
/*pragma libcall IconBase iconPrivate3 3C 0*/
/*pragma libcall IconBase iconPrivate4 42 0*/
#pragma libcall IconBase AddFreeList 48 A9803
#pragma libcall IconBase GetDiskObject 4E 801
#pragma libcall IconBase PutDiskObject 54 9802
#pragma libcall IconBase FreeDiskObject 5A 801
#pragma libcall IconBase FindToolType 60 9802
#pragma libcall IconBase MatchToolValue 66 9802
#pragma libcall IconBase BumpRevision 6C 9802
/*pragma libcall IconBase iconPrivate5 72 0*/
#pragma libcall IconBase GetDefDiskObject 78 001
#pragma libcall IconBase PutDefDiskObject 7E 801
#pragma libcall IconBase GetDiskObjectNew 84 801
#pragma libcall IconBase DeleteDiskObject 8A 801
/*--- (4 function slots reserved here) ---*/

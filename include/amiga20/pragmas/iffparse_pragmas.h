/* "iffparse.library"*/
/*--- functions in V33 or higher (distributed as Release 1.2) ---*/
/*------ Basic functions ------*/
#pragma libcall IFFParseBase AllocIFF 1E 0
#pragma libcall IFFParseBase OpenIFF 24 0802
#pragma libcall IFFParseBase ParseIFF 2A 0802
#pragma libcall IFFParseBase CloseIFF 30 801
#pragma libcall IFFParseBase FreeIFF 36 801
/*------ Read/Write functions ------*/
#pragma libcall IFFParseBase ReadChunkBytes 3C 09803
#pragma libcall IFFParseBase WriteChunkBytes 42 09803
#pragma libcall IFFParseBase ReadChunkRecords 48 109804
#pragma libcall IFFParseBase WriteChunkRecords 4E 109804
/*------ Context entry/exit ------*/
#pragma libcall IFFParseBase PushChunk 54 210804
#pragma libcall IFFParseBase PopChunk 5A 801
/*--- (1 function slot reserved here) ---*/
/*------ Low-level handler installation ------*/
#pragma libcall IFFParseBase EntryHandler 66 A9210806
#pragma libcall IFFParseBase ExitHandler 6C A9210806
/*------ Built-in chunk/property handlers ------*/
#pragma libcall IFFParseBase PropChunk 72 10803
#pragma libcall IFFParseBase PropChunks 78 09803
#pragma libcall IFFParseBase StopChunk 7E 10803
#pragma libcall IFFParseBase StopChunks 84 09803
#pragma libcall IFFParseBase CollectionChunk 8A 10803
#pragma libcall IFFParseBase CollectionChunks 90 09803
#pragma libcall IFFParseBase StopOnExit 96 10803
/*------ Context utilities ------*/
#pragma libcall IFFParseBase FindProp 9C 10803
#pragma libcall IFFParseBase FindCollection A2 10803
#pragma libcall IFFParseBase FindPropContext A8 801
#pragma libcall IFFParseBase CurrentChunk AE 801
#pragma libcall IFFParseBase ParentChunk B4 801
/*------ LocalContextItem support functions ------*/
#pragma libcall IFFParseBase AllocLocalItem BA 321004
#pragma libcall IFFParseBase LocalItemData C0 801
#pragma libcall IFFParseBase SetLocalItemPurge C6 9802
#pragma libcall IFFParseBase FreeLocalItem CC 801
#pragma libcall IFFParseBase FindLocalItem D2 210804
#pragma libcall IFFParseBase StoreLocalItem D8 09803
#pragma libcall IFFParseBase StoreItemInContext DE A9803
/*------ IFFHandle initialization ------*/
#pragma libcall IFFParseBase InitIFF E4 90803
#pragma libcall IFFParseBase InitIFFasDOS EA 801
#pragma libcall IFFParseBase InitIFFasClip F0 801
/*------ Internal clipboard support ------*/
#pragma libcall IFFParseBase OpenClipboard F6 001
#pragma libcall IFFParseBase CloseClipboard FC 801
/*------ Miscellaneous ------*/
#pragma libcall IFFParseBase GoodID 102 001
#pragma libcall IFFParseBase GoodType 108 001
#pragma libcall IFFParseBase IDtoStr 10E 8002

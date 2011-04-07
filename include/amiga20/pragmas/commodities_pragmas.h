/* "commodities.library"*/
/*--- functions in V36 or higher (distributed as Release 2.0) ---*/
/**/
/*  OBJECT UTILITIES*/
/**/
#pragma libcall CxBase CreateCxObj 1E 98003
#pragma libcall CxBase CxBroker 24 0802
#pragma libcall CxBase ActivateCxObj 2A 0802
#pragma libcall CxBase DeleteCxObj 30 801
#pragma libcall CxBase DeleteCxObjAll 36 801
#pragma libcall CxBase CxObjType 3C 801
#pragma libcall CxBase CxObjError 42 801
#pragma libcall CxBase ClearCxObjError 48 801
#pragma libcall CxBase SetCxObjPri 4E 0802
/**/
/*  OBJECT ATTACHMENT*/
/**/
#pragma libcall CxBase AttachCxObj 54 9802
#pragma libcall CxBase EnqueueCxObj 5A 9802
#pragma libcall CxBase InsertCxObj 60 A9803
#pragma libcall CxBase RemoveCxObj 66 801
/**/
/*  TYPE SPECIFIC*/
/**/
/*pragma libcall CxBase commoditiesPrivate1 6C 0*/
#pragma libcall CxBase SetTranslate 72 9802
#pragma libcall CxBase SetFilter 78 9802
#pragma libcall CxBase SetFilterIX 7E 9802
#pragma libcall CxBase ParseIX 84 9802
/**/
/*  COMMON MESSAGE*/
/**/
#pragma libcall CxBase CxMsgType 8A 801
#pragma libcall CxBase CxMsgData 90 801
#pragma libcall CxBase CxMsgID 96 801
/**/
/*  MESSAGE ROUTING*/
/**/
#pragma libcall CxBase DivertCxMsg 9C A9803
#pragma libcall CxBase RouteCxMsg A2 9802
#pragma libcall CxBase DisposeCxMsg A8 801
/**/
/*  INPUT EVENT HANDLING*/
/**/
#pragma libcall CxBase InvertKeyMap AE 98003
#pragma libcall CxBase AddIEvents B4 801
/**/
/* FOR USE ONLY BY CONTROLLER PROGRAM*/
/**/
/*pragma libcall CxBase commoditiesPrivate2 BA 0*/
/*pragma libcall CxBase commoditiesPrivate3 C0 0*/
/*pragma libcall CxBase commoditiesPrivate4 C6 0*/

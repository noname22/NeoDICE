/* "utility.library"*/
/* *** TagItem FUNCTIONS ****/
#pragma libcall UtilityBase FindTagItem 1E 8002
#pragma libcall UtilityBase GetTagData 24 81003
#pragma libcall UtilityBase PackBoolTags 2A 98003
#pragma libcall UtilityBase NextTagItem 30 801
#pragma libcall UtilityBase FilterTagChanges 36 09803
#pragma libcall UtilityBase MapTags 3C 09803
#pragma libcall UtilityBase AllocateTagItems 42 001
#pragma libcall UtilityBase CloneTagItems 48 801
#pragma libcall UtilityBase FreeTagItems 4E 801
#pragma libcall UtilityBase RefreshTagItemClones 54 9802
#pragma libcall UtilityBase TagInArray 5A 8002
#pragma libcall UtilityBase FilterTagItems 60 09803
/**/
/* *** HOOK FUNCTIONS *** **/
#pragma libcall UtilityBase CallHookPkt 66 9A803
/*--- (1 function slot reserved here) ---*/
/**/
/* *** DATE FUNCTIONS *** **/
/*--- (1 function slot reserved here) ---*/
#pragma libcall UtilityBase Amiga2Date 78 8002
#pragma libcall UtilityBase Date2Amiga 7E 801
#pragma libcall UtilityBase CheckDate 84 801
/**/
/* *** 32 BIT MATH FUNCTIONS *** **/
#pragma libcall UtilityBase SMult32 8A 1002
#pragma libcall UtilityBase UMult32 90 1002
/* NOTE: Quotient:Remainder returned in d0:d1*/
#pragma libcall UtilityBase SDivMod32 96 1002
#pragma libcall UtilityBase UDivMod32 9C 1002
/**/
/* *** International string routines ****/
#pragma libcall UtilityBase Stricmp A2 9802
#pragma libcall UtilityBase Strnicmp A8 09803
#pragma libcall UtilityBase ToUpper AE 001
#pragma libcall UtilityBase ToLower B4 001

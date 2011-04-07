/* "intuition.library"*/
/* Public functions OpenIntuition() and Intuition() are intentionally*/
/* not documented.*/
#pragma libcall IntuitionBase OpenIntuition 1E 0
#pragma libcall IntuitionBase Intuition 24 801
#pragma libcall IntuitionBase AddGadget 2A 09803
#pragma libcall IntuitionBase ClearDMRequest 30 801
#pragma libcall IntuitionBase ClearMenuStrip 36 801
#pragma libcall IntuitionBase ClearPointer 3C 801
#pragma libcall IntuitionBase CloseScreen 42 801
#pragma libcall IntuitionBase CloseWindow 48 801
#pragma libcall IntuitionBase CloseWorkBench 4E 0
#pragma libcall IntuitionBase CurrentTime 54 9802
#pragma libcall IntuitionBase DisplayAlert 5A 18003
#pragma libcall IntuitionBase DisplayBeep 60 801
#pragma libcall IntuitionBase DoubleClick 66 321004
#pragma libcall IntuitionBase DrawBorder 6C 109804
#pragma libcall IntuitionBase DrawImage 72 109804
#pragma libcall IntuitionBase EndRequest 78 9802
#pragma libcall IntuitionBase GetDefPrefs 7E 0802
#pragma libcall IntuitionBase GetPrefs 84 0802
#pragma libcall IntuitionBase InitRequester 8A 801
#pragma libcall IntuitionBase ItemAddress 90 0802
#pragma libcall IntuitionBase ModifyIDCMP 96 0802
#pragma libcall IntuitionBase ModifyProp 9C 43210A9808
#pragma libcall IntuitionBase MoveScreen A2 10803
#pragma libcall IntuitionBase MoveWindow A8 10803
#pragma libcall IntuitionBase OffGadget AE A9803
#pragma libcall IntuitionBase OffMenu B4 0802
#pragma libcall IntuitionBase OnGadget BA A9803
#pragma libcall IntuitionBase OnMenu C0 0802
#pragma libcall IntuitionBase OpenScreen C6 801
#pragma libcall IntuitionBase OpenWindow CC 801
#pragma libcall IntuitionBase OpenWorkBench D2 0
#pragma libcall IntuitionBase PrintIText D8 109804
#pragma libcall IntuitionBase RefreshGadgets DE A9803
#pragma libcall IntuitionBase RemoveGadget E4 9802
/* The official calling sequence for ReportMouse is given below.*/
/* Note the register order.  For the complete story, read the ReportMouse*/
/* autodoc.*/
#pragma libcall IntuitionBase ReportMouse EA 8002
#pragma libcall IntuitionBase Request F0 9802
#pragma libcall IntuitionBase ScreenToBack F6 801
#pragma libcall IntuitionBase ScreenToFront FC 801
#pragma libcall IntuitionBase SetDMRequest 102 9802
#pragma libcall IntuitionBase SetMenuStrip 108 9802
#pragma libcall IntuitionBase SetPointer 10E 32109806
#pragma libcall IntuitionBase SetWindowTitles 114 A9803
#pragma libcall IntuitionBase ShowTitle 11A 0802
#pragma libcall IntuitionBase SizeWindow 120 10803
#pragma libcall IntuitionBase ViewAddress 126 0
#pragma libcall IntuitionBase ViewPortAddress 12C 801
#pragma libcall IntuitionBase WindowToBack 132 801
#pragma libcall IntuitionBase WindowToFront 138 801
#pragma libcall IntuitionBase WindowLimits 13E 3210805
/*--- start of next generation of names -------------------------------------*/
#pragma libcall IntuitionBase SetPrefs 144 10803
/*--- start of next next generation of names --------------------------------*/
#pragma libcall IntuitionBase IntuiTextLength 14A 801
#pragma libcall IntuitionBase WBenchToBack 150 0
#pragma libcall IntuitionBase WBenchToFront 156 0
/*--- start of next next next generation of names ---------------------------*/
#pragma libcall IntuitionBase AutoRequest 15C 3210BA9808
#pragma libcall IntuitionBase BeginRefresh 162 801
#pragma libcall IntuitionBase BuildSysRequest 168 210BA9807
#pragma libcall IntuitionBase EndRefresh 16E 0802
#pragma libcall IntuitionBase FreeSysRequest 174 801
#pragma libcall IntuitionBase MakeScreen 17A 801
#pragma libcall IntuitionBase RemakeDisplay 180 0
#pragma libcall IntuitionBase RethinkDisplay 186 0
/*--- start of next next next next generation of names ----------------------*/
#pragma libcall IntuitionBase AllocRemember 18C 10803
/* Public function AlohaWorkbench() is intentionally not documented*/
#pragma libcall IntuitionBase AlohaWorkbench 192 801
#pragma libcall IntuitionBase FreeRemember 198 0802
/*--- start of 15 Nov 85 names ------------------------*/
#pragma libcall IntuitionBase LockIBase 19E 001
#pragma libcall IntuitionBase UnlockIBase 1A4 801
/*--- functions in V33 or higher (distributed as Release 1.2) ---*/
#pragma libcall IntuitionBase GetScreenData 1AA 910804
#pragma libcall IntuitionBase RefreshGList 1B0 0A9804
#pragma libcall IntuitionBase AddGList 1B6 A109805
#pragma libcall IntuitionBase RemoveGList 1BC 09803
#pragma libcall IntuitionBase ActivateWindow 1C2 801
#pragma libcall IntuitionBase RefreshWindowFrame 1C8 801
#pragma libcall IntuitionBase ActivateGadget 1CE A9803
#pragma libcall IntuitionBase NewModifyProp 1D4 543210A9809
/*--- functions in V36 or higher (distributed as Release 2.0) ---*/
#pragma libcall IntuitionBase QueryOverscan 1DA 09803
#pragma libcall IntuitionBase MoveWindowInFrontOf 1E0 9802
#pragma libcall IntuitionBase ChangeWindowBox 1E6 3210805
#pragma libcall IntuitionBase SetEditHook 1EC 801
#pragma libcall IntuitionBase SetMouseQueue 1F2 0802
#pragma libcall IntuitionBase ZipWindow 1F8 801
/*--- public screens ---*/
#pragma libcall IntuitionBase LockPubScreen 1FE 801
#pragma libcall IntuitionBase UnlockPubScreen 204 9802
#pragma libcall IntuitionBase LockPubScreenList 20A 0
#pragma libcall IntuitionBase UnlockPubScreenList 210 0
#pragma libcall IntuitionBase NextPubScreen 216 9802
#pragma libcall IntuitionBase SetDefaultPubScreen 21C 801
#pragma libcall IntuitionBase SetPubScreenModes 222 001
#pragma libcall IntuitionBase PubScreenStatus 228 0802
/**/
#pragma libcall IntuitionBase ObtainGIRPort 22E 801
#pragma libcall IntuitionBase ReleaseGIRPort 234 801
#pragma libcall IntuitionBase GadgetMouse 23A A9803
/* system private and not to be used by applications:*/
/*pragma libcall IntuitionBase intuitionPrivate1 240 0*/
#pragma libcall IntuitionBase GetDefaultPubScreen 246 801
#pragma libcall IntuitionBase EasyRequestArgs 24C BA9804
#pragma libcall IntuitionBase BuildEasyRequestArgs 252 B09804
#pragma libcall IntuitionBase SysReqHandler 258 09803
#pragma libcall IntuitionBase OpenWindowTagList 25E 9802
#pragma tagcall IntuitionBase OpenWindowTags 25E 9802
#pragma libcall IntuitionBase OpenScreenTagList 264 9802
#pragma tagcall IntuitionBase OpenScreenTags 264 9802
/**/
/*	new Image functions*/
#pragma libcall IntuitionBase DrawImageState 26A A2109806
#pragma libcall IntuitionBase PointInImage 270 8002
#pragma libcall IntuitionBase EraseImage 276 109804
/**/
#pragma libcall IntuitionBase NewObjectA 27C A9803
#pragma tagcall IntuitionBase NewObject 27C A9803
/**/
#pragma libcall IntuitionBase DisposeObject 282 801
#pragma libcall IntuitionBase SetAttrsA 288 9802
#pragma tagcall IntuitionBase SetAttrs 288 9802
/**/
#pragma libcall IntuitionBase GetAttr 28E 98003
/**/
/* 	special set attribute call for gadgets*/
#pragma libcall IntuitionBase SetGadgetAttrsA 294 BA9804
#pragma tagcall IntuitionBase SetGadgetAttrs 294 BA9804
/**/
/*	for class implementors only*/
#pragma libcall IntuitionBase NextObject 29A 801
/*pragma libcall IntuitionBase intuitionPrivate2 2A0 0*/
#pragma libcall IntuitionBase MakeClass 2A6 10A9805
#pragma libcall IntuitionBase AddClass 2AC 801
/**/
/**/
#pragma libcall IntuitionBase GetScreenDrawInfo 2B2 801
#pragma libcall IntuitionBase FreeScreenDrawInfo 2B8 9802
/**/
#pragma libcall IntuitionBase ResetMenuStrip 2BE 9802
#pragma libcall IntuitionBase RemoveClass 2C4 801
#pragma libcall IntuitionBase FreeClass 2CA 801
/*pragma libcall IntuitionBase intuitionPrivate3 2D0 0*/
/*pragma libcall IntuitionBase intuitionPrivate4 2D6 0*/

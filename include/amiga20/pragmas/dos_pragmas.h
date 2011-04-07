/* "dos.library"*/
#pragma libcall DOSBase Open 1E 2102
#pragma libcall DOSBase Close 24 101
#pragma libcall DOSBase Read 2A 32103
#pragma libcall DOSBase Write 30 32103
#pragma libcall DOSBase Input 36 0
#pragma libcall DOSBase Output 3C 0
#pragma libcall DOSBase Seek 42 32103
#pragma libcall DOSBase DeleteFile 48 101
#pragma libcall DOSBase Rename 4E 2102
#pragma libcall DOSBase Lock 54 2102
#pragma libcall DOSBase UnLock 5A 101
#pragma libcall DOSBase DupLock 60 101
#pragma libcall DOSBase Examine 66 2102
#pragma libcall DOSBase ExNext 6C 2102
#pragma libcall DOSBase Info 72 2102
#pragma libcall DOSBase CreateDir 78 101
#pragma libcall DOSBase CurrentDir 7E 101
#pragma libcall DOSBase IoErr 84 0
#pragma libcall DOSBase CreateProc 8A 432104
#pragma libcall DOSBase Exit 90 101
#pragma libcall DOSBase LoadSeg 96 101
#pragma libcall DOSBase UnLoadSeg 9C 101
/*pragma libcall DOSBase dosPrivate1 A2 0*/
/*pragma libcall DOSBase dosPrivate2 A8 0*/
#pragma libcall DOSBase DeviceProc AE 101
#pragma libcall DOSBase SetComment B4 2102
#pragma libcall DOSBase SetProtection BA 2102
#pragma libcall DOSBase DateStamp C0 101
#pragma libcall DOSBase Delay C6 101
#pragma libcall DOSBase WaitForChar CC 2102
#pragma libcall DOSBase ParentDir D2 101
#pragma libcall DOSBase IsInteractive D8 101
#pragma libcall DOSBase Execute DE 32103
/*--- functions in V36 or higher (distributed as Release 2.0) ---*/
/*	DOS Object creation/deletion*/
#pragma libcall DOSBase AllocDosObject E4 2102
#pragma libcall DOSBase AllocDosObjectTagList E4 2102
#pragma tagcall DOSBase AllocDosObjectTags E4 2102
#pragma libcall DOSBase FreeDosObject EA 2102
/*	Packet Level routines*/
#pragma libcall DOSBase DoPkt F0 765432107
#pragma libcall DOSBase SendPkt F6 32103
#pragma libcall DOSBase WaitPkt FC 0
#pragma libcall DOSBase ReplyPkt 102 32103
#pragma libcall DOSBase AbortPkt 108 2102
/*	Record Locking*/
#pragma libcall DOSBase LockRecord 10E 5432105
#pragma libcall DOSBase LockRecords 114 2102
#pragma libcall DOSBase UnLockRecord 11A 32103
#pragma libcall DOSBase UnLockRecords 120 101
/*	Buffered File I/O*/
#pragma libcall DOSBase SelectInput 126 101
#pragma libcall DOSBase SelectOutput 12C 101
#pragma libcall DOSBase FGetC 132 101
#pragma libcall DOSBase FPutC 138 2102
#pragma libcall DOSBase UnGetC 13E 2102
#pragma libcall DOSBase FRead 144 432104
#pragma libcall DOSBase FWrite 14A 432104
#pragma libcall DOSBase FGets 150 32103
#pragma libcall DOSBase FPuts 156 2102
#pragma libcall DOSBase VFWritef 15C 32103
#pragma tagcall DOSBase FWritef 15C 32103
#pragma libcall DOSBase VFPrintf 162 32103
#pragma tagcall DOSBase FPrintf 162 32103
#pragma libcall DOSBase Flush 168 101
#pragma libcall DOSBase SetVBuf 16E 432104
/*	DOS Object Management*/
#pragma libcall DOSBase DupLockFromFH 174 101
#pragma libcall DOSBase OpenFromLock 17A 101
#pragma libcall DOSBase ParentOfFH 180 101
#pragma libcall DOSBase ExamineFH 186 2102
#pragma libcall DOSBase SetFileDate 18C 2102
#pragma libcall DOSBase NameFromLock 192 32103
#pragma libcall DOSBase NameFromFH 198 32103
#pragma libcall DOSBase SplitName 19E 5432105
#pragma libcall DOSBase SameLock 1A4 2102
#pragma libcall DOSBase SetMode 1AA 2102
#pragma libcall DOSBase ExAll 1B0 5432105
#pragma libcall DOSBase ReadLink 1B6 5432105
#pragma libcall DOSBase MakeLink 1BC 32103
#pragma libcall DOSBase ChangeMode 1C2 32103
#pragma libcall DOSBase SetFileSize 1C8 32103
/*	Error Handling*/
#pragma libcall DOSBase SetIoErr 1CE 101
#pragma libcall DOSBase Fault 1D4 432104
#pragma libcall DOSBase PrintFault 1DA 2102
#pragma libcall DOSBase ErrorReport 1E0 432104
/*--- (1 function slot reserved here) ---*/
/*	Process Management*/
#pragma libcall DOSBase Cli 1EC 0
#pragma libcall DOSBase CreateNewProc 1F2 101
#pragma libcall DOSBase CreateNewProcTagList 1F2 101
#pragma tagcall DOSBase CreateNewProcTags 1F2 101
#pragma libcall DOSBase RunCommand 1F8 432104
#pragma libcall DOSBase GetConsoleTask 1FE 0
#pragma libcall DOSBase SetConsoleTask 204 101
#pragma libcall DOSBase GetFileSysTask 20A 0
#pragma libcall DOSBase SetFileSysTask 210 101
#pragma libcall DOSBase GetArgStr 216 0
#pragma libcall DOSBase SetArgStr 21C 101
#pragma libcall DOSBase FindCliProc 222 101
#pragma libcall DOSBase MaxCli 228 0
#pragma libcall DOSBase SetCurrentDirName 22E 101
#pragma libcall DOSBase GetCurrentDirName 234 2102
#pragma libcall DOSBase SetProgramName 23A 101
#pragma libcall DOSBase GetProgramName 240 2102
#pragma libcall DOSBase SetPrompt 246 101
#pragma libcall DOSBase GetPrompt 24C 2102
#pragma libcall DOSBase SetProgramDir 252 101
#pragma libcall DOSBase GetProgramDir 258 0
/*	Device List Management*/
#pragma libcall DOSBase System 25E 2102
#pragma libcall DOSBase SystemTagList 25E 2102
#pragma tagcall DOSBase SystemTags 25E 2102
#pragma libcall DOSBase AssignLock 264 2102
#pragma libcall DOSBase AssignLate 26A 2102
#pragma libcall DOSBase AssignPath 270 2102
#pragma libcall DOSBase AssignAdd 276 2102
#pragma libcall DOSBase RemAssignList 27C 2102
#pragma libcall DOSBase GetDeviceProc 282 2102
#pragma libcall DOSBase FreeDeviceProc 288 101
#pragma libcall DOSBase LockDosList 28E 101
#pragma libcall DOSBase UnLockDosList 294 101
#pragma libcall DOSBase AttemptLockDosList 29A 101
#pragma libcall DOSBase RemDosEntry 2A0 101
#pragma libcall DOSBase AddDosEntry 2A6 101
#pragma libcall DOSBase FindDosEntry 2AC 32103
#pragma libcall DOSBase NextDosEntry 2B2 2102
#pragma libcall DOSBase MakeDosEntry 2B8 2102
#pragma libcall DOSBase FreeDosEntry 2BE 101
#pragma libcall DOSBase IsFileSystem 2C4 101
/*	Handler Interface*/
#pragma libcall DOSBase Format 2CA 32103
#pragma libcall DOSBase Relabel 2D0 2102
#pragma libcall DOSBase Inhibit 2D6 2102
#pragma libcall DOSBase AddBuffers 2DC 2102
/*	Date, Time Routines*/
#pragma libcall DOSBase CompareDates 2E2 2102
#pragma libcall DOSBase DateToStr 2E8 101
#pragma libcall DOSBase StrToDate 2EE 101
/*	Image Management*/
#pragma libcall DOSBase InternalLoadSeg 2F4 A98004
#pragma libcall DOSBase InternalUnLoadSeg 2FA 9102
#pragma libcall DOSBase NewLoadSeg 300 2102
#pragma libcall DOSBase NewLoadSegTagList 300 2102
#pragma tagcall DOSBase NewLoadSegTags 300 2102
#pragma libcall DOSBase AddSegment 306 32103
#pragma libcall DOSBase FindSegment 30C 32103
#pragma libcall DOSBase RemSegment 312 101
/*	Command Support*/
#pragma libcall DOSBase CheckSignal 318 101
#pragma libcall DOSBase ReadArgs 31E 32103
#pragma libcall DOSBase FindArg 324 2102
#pragma libcall DOSBase ReadItem 32A 32103
#pragma libcall DOSBase StrToLong 330 2102
#pragma libcall DOSBase MatchFirst 336 2102
#pragma libcall DOSBase MatchNext 33C 101
#pragma libcall DOSBase MatchEnd 342 101
#pragma libcall DOSBase ParsePattern 348 32103
#pragma libcall DOSBase MatchPattern 34E 2102
/* Not currently implemented.*/
/*pragma libcall DOSBase dosPrivate3 354 0*/
#pragma libcall DOSBase FreeArgs 35A 101
/*--- (1 function slot reserved here) ---*/
#pragma libcall DOSBase FilePart 366 101
#pragma libcall DOSBase PathPart 36C 101
#pragma libcall DOSBase AddPart 372 32103
/*	Notification*/
#pragma libcall DOSBase StartNotify 378 101
#pragma libcall DOSBase EndNotify 37E 101
/*	Environment Variable functions*/
#pragma libcall DOSBase SetVar 384 432104
#pragma libcall DOSBase GetVar 38A 432104
#pragma libcall DOSBase DeleteVar 390 2102
#pragma libcall DOSBase FindVar 396 2102
/*pragma libcall DOSBase dosPrivate4 39C 0*/
#pragma libcall DOSBase CliInitNewcli 3A2 801
#pragma libcall DOSBase CliInitRun 3A8 801
#pragma libcall DOSBase WriteChars 3AE 2102
#pragma libcall DOSBase PutStr 3B4 101
#pragma libcall DOSBase VPrintf 3BA 2102
#pragma tagcall DOSBase Printf 3BA 2102
/*--- (1 function slot reserved here) ---*/
/* these were unimplemented until dos 36.147*/
#pragma libcall DOSBase ParsePatternNoCase 3C6 32103
#pragma libcall DOSBase MatchPatternNoCase 3CC 2102
/*pragma libcall DOSBase dosPrivate5 3D2 0*/
/* this was added for V37 dos, returned 0 before then.*/
#pragma libcall DOSBase SameDevice 3D8 2102
/* These were added in dos 36.147*/
/*--- (4 function slots reserved here) ---*/
/* these were added in dos 37.1*/
/*--- (2 function slots reserved here) ---*/
/* these were added in dos 37.8*/
/*--- (2 function slots reserved here) ---*/

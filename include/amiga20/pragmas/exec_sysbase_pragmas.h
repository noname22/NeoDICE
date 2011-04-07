/* "exec.library"*/
/*------ misc ---------------------------------------------------------*/
#pragma libcall SysBase Supervisor 1E D01
/*------ special patchable hooks to internal exec activity ------------*/
/*pragma libcall SysBase execPrivate1 24 0*/
/*pragma libcall SysBase execPrivate2 2A 0*/
/*pragma libcall SysBase execPrivate3 30 0*/
/*pragma libcall SysBase execPrivate4 36 0*/
/*pragma libcall SysBase execPrivate5 3C 0*/
/*pragma libcall SysBase execPrivate6 42 0*/
/*------ module creation ----------------------------------------------*/
#pragma libcall SysBase InitCode 48 1002
#pragma libcall SysBase InitStruct 4E 0A903
#pragma libcall SysBase MakeLibrary 54 10A9805
#pragma libcall SysBase MakeFunctions 5A A9803
#pragma libcall SysBase FindResident 60 901
#pragma libcall SysBase InitResident 66 1902
/*------ diagnostics --------------------------------------------------*/
#pragma libcall SysBase Alert 6C 701
#pragma libcall SysBase Debug 72 001
/*------ interrupts ---------------------------------------------------*/
#pragma libcall SysBase Disable 78 0
#pragma libcall SysBase Enable 7E 0
#pragma libcall SysBase Forbid 84 0
#pragma libcall SysBase Permit 8A 0
#pragma libcall SysBase SetSR 90 1002
#pragma libcall SysBase SuperState 96 0
#pragma libcall SysBase UserState 9C 001
#pragma libcall SysBase SetIntVector A2 9002
#pragma libcall SysBase AddIntServer A8 9002
#pragma libcall SysBase RemIntServer AE 9002
#pragma libcall SysBase Cause B4 901
/*------ memory allocation --------------------------------------------*/
#pragma libcall SysBase Allocate BA 0802
#pragma libcall SysBase Deallocate C0 09803
#pragma libcall SysBase AllocMem C6 1002
#pragma libcall SysBase AllocAbs CC 9002
#pragma libcall SysBase FreeMem D2 0902
#pragma libcall SysBase AvailMem D8 101
#pragma libcall SysBase AllocEntry DE 801
#pragma libcall SysBase FreeEntry E4 801
/*------ lists --------------------------------------------------------*/
#pragma libcall SysBase Insert EA A9803
#pragma libcall SysBase AddHead F0 9802
#pragma libcall SysBase AddTail F6 9802
#pragma libcall SysBase Remove FC 901
#pragma libcall SysBase RemHead 102 801
#pragma libcall SysBase RemTail 108 801
#pragma libcall SysBase Enqueue 10E 9802
#pragma libcall SysBase FindName 114 9802
/*------ tasks --------------------------------------------------------*/
#pragma libcall SysBase AddTask 11A BA903
#pragma libcall SysBase RemTask 120 901
#pragma libcall SysBase FindTask 126 901
#pragma libcall SysBase SetTaskPri 12C 0902
#pragma libcall SysBase SetSignal 132 1002
#pragma libcall SysBase SetExcept 138 1002
#pragma libcall SysBase Wait 13E 001
#pragma libcall SysBase Signal 144 0902
#pragma libcall SysBase AllocSignal 14A 001
#pragma libcall SysBase FreeSignal 150 001
#pragma libcall SysBase AllocTrap 156 001
#pragma libcall SysBase FreeTrap 15C 001
/*------ messages -----------------------------------------------------*/
#pragma libcall SysBase AddPort 162 901
#pragma libcall SysBase RemPort 168 901
#pragma libcall SysBase PutMsg 16E 9802
#pragma libcall SysBase GetMsg 174 801
#pragma libcall SysBase ReplyMsg 17A 901
#pragma libcall SysBase WaitPort 180 801
#pragma libcall SysBase FindPort 186 901
/*------ libraries ----------------------------------------------------*/
#pragma libcall SysBase AddLibrary 18C 901
#pragma libcall SysBase RemLibrary 192 901
#pragma libcall SysBase OldOpenLibrary 198 901
#pragma libcall SysBase CloseLibrary 19E 901
#pragma libcall SysBase SetFunction 1A4 08903
#pragma libcall SysBase SumLibrary 1AA 901
/*------ devices ------------------------------------------------------*/
#pragma libcall SysBase AddDevice 1B0 901
#pragma libcall SysBase RemDevice 1B6 901
#pragma libcall SysBase OpenDevice 1BC 190804
#pragma libcall SysBase CloseDevice 1C2 901
#pragma libcall SysBase DoIO 1C8 901
#pragma libcall SysBase SendIO 1CE 901
#pragma libcall SysBase CheckIO 1D4 901
#pragma libcall SysBase WaitIO 1DA 901
#pragma libcall SysBase AbortIO 1E0 901
/*------ resources ----------------------------------------------------*/
#pragma libcall SysBase AddResource 1E6 901
#pragma libcall SysBase RemResource 1EC 901
#pragma libcall SysBase OpenResource 1F2 901
/*------ private diagnostic support -----------------------------------*/
/*pragma libcall SysBase execPrivate7 1F8 0*/
/*pragma libcall SysBase execPrivate8 1FE 0*/
/*pragma libcall SysBase execPrivate9 204 0*/
/*------ misc ---------------------------------------------------------*/
#pragma libcall SysBase RawDoFmt 20A BA9804
#pragma libcall SysBase GetCC 210 0
#pragma libcall SysBase TypeOfMem 216 901
#pragma libcall SysBase Procure 21C 9802
#pragma libcall SysBase Vacate 222 801
#pragma libcall SysBase OpenLibrary 228 0902
/*--- functions in V33 or higher (distributed as Release 1.2) ---*/
/*------ signal semaphores (note funny registers)----------------------*/
#pragma libcall SysBase InitSemaphore 22E 801
#pragma libcall SysBase ObtainSemaphore 234 801
#pragma libcall SysBase ReleaseSemaphore 23A 801
#pragma libcall SysBase AttemptSemaphore 240 801
#pragma libcall SysBase ObtainSemaphoreList 246 801
#pragma libcall SysBase ReleaseSemaphoreList 24C 801
#pragma libcall SysBase FindSemaphore 252 901
#pragma libcall SysBase AddSemaphore 258 901
#pragma libcall SysBase RemSemaphore 25E 901
/*------ kickmem support ----------------------------------------------*/
#pragma libcall SysBase SumKickData 264 0
/*------ more memory support ------------------------------------------*/
#pragma libcall SysBase AddMemList 26A 9821005
#pragma libcall SysBase CopyMem 270 09803
#pragma libcall SysBase CopyMemQuick 276 09803
/*------ cache --------------------------------------------------------*/
/*--- functions in V36 or higher (distributed as Release 2.0) ---*/
#pragma libcall SysBase CacheClearU 27C 0
#pragma libcall SysBase CacheClearE 282 10803
#pragma libcall SysBase CacheControl 288 1002
/*------ misc ---------------------------------------------------------*/
#pragma libcall SysBase CreateIORequest 28E 0802
#pragma libcall SysBase DeleteIORequest 294 801
#pragma libcall SysBase CreateMsgPort 29A 0
#pragma libcall SysBase DeleteMsgPort 2A0 801
#pragma libcall SysBase ObtainSemaphoreShared 2A6 801
/*------ even more memory support -------------------------------------*/
#pragma libcall SysBase AllocVec 2AC 1002
#pragma libcall SysBase FreeVec 2B2 901
#pragma libcall SysBase CreatePrivatePool 2B8 21003
#pragma libcall SysBase DeletePrivatePool 2BE 801
#pragma libcall SysBase AllocPooled 2C4 8002
#pragma libcall SysBase FreePooled 2CA 8902
/*------ misc ---------------------------------------------------------*/
#pragma libcall SysBase AttemptSemaphoreShared 2D0 801
#pragma libcall SysBase ColdReboot 2D6 0
#pragma libcall SysBase StackSwap 2DC 801
/*------ task trees ---------------------------------------------------*/
#pragma libcall SysBase ChildFree 2E2 001
#pragma libcall SysBase ChildOrphan 2E8 001
#pragma libcall SysBase ChildStatus 2EE 001
#pragma libcall SysBase ChildWait 2F4 001
/*------ future expansion ---------------------------------------------*/
#pragma libcall SysBase CachePreDMA 2FA 19803
#pragma libcall SysBase CachePostDMA 300 19803
/*pragma libcall SysBase execPrivate10 306 0*/
/*pragma libcall SysBase execPrivate11 30C 0*/
/*pragma libcall SysBase execPrivate12 312 0*/
/*pragma libcall SysBase execPrivate13 318 0*/

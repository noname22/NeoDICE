/* "exec.library"*/
/*------ misc ---------------------------------------------------------*/
#pragma syscall Supervisor 1E D01
/*------ special patchable hooks to internal exec activity ------------*/
/*pragma syscall execPrivate1 24 0*/
/*pragma syscall execPrivate2 2A 0*/
/*pragma syscall execPrivate3 30 0*/
/*pragma syscall execPrivate4 36 0*/
/*pragma syscall execPrivate5 3C 0*/
/*pragma syscall execPrivate6 42 0*/
/*------ module creation ----------------------------------------------*/
#pragma syscall InitCode 48 1002
#pragma syscall InitStruct 4E 0A903
#pragma syscall MakeLibrary 54 10A9805
#pragma syscall MakeFunctions 5A A9803
#pragma syscall FindResident 60 901
#pragma syscall InitResident 66 1902
/*------ diagnostics --------------------------------------------------*/
#pragma syscall Alert 6C 701
#pragma syscall Debug 72 001
/*------ interrupts ---------------------------------------------------*/
#pragma syscall Disable 78 0
#pragma syscall Enable 7E 0
#pragma syscall Forbid 84 0
#pragma syscall Permit 8A 0
#pragma syscall SetSR 90 1002
#pragma syscall SuperState 96 0
#pragma syscall UserState 9C 001
#pragma syscall SetIntVector A2 9002
#pragma syscall AddIntServer A8 9002
#pragma syscall RemIntServer AE 9002
#pragma syscall Cause B4 901
/*------ memory allocation --------------------------------------------*/
#pragma syscall Allocate BA 0802
#pragma syscall Deallocate C0 09803
#pragma syscall AllocMem C6 1002
#pragma syscall AllocAbs CC 9002
#pragma syscall FreeMem D2 0902
#pragma syscall AvailMem D8 101
#pragma syscall AllocEntry DE 801
#pragma syscall FreeEntry E4 801
/*------ lists --------------------------------------------------------*/
#pragma syscall Insert EA A9803
#pragma syscall AddHead F0 9802
#pragma syscall AddTail F6 9802
#pragma syscall Remove FC 901
#pragma syscall RemHead 102 801
#pragma syscall RemTail 108 801
#pragma syscall Enqueue 10E 9802
#pragma syscall FindName 114 9802
/*------ tasks --------------------------------------------------------*/
#pragma syscall AddTask 11A BA903
#pragma syscall RemTask 120 901
#pragma syscall FindTask 126 901
#pragma syscall SetTaskPri 12C 0902
#pragma syscall SetSignal 132 1002
#pragma syscall SetExcept 138 1002
#pragma syscall Wait 13E 001
#pragma syscall Signal 144 0902
#pragma syscall AllocSignal 14A 001
#pragma syscall FreeSignal 150 001
#pragma syscall AllocTrap 156 001
#pragma syscall FreeTrap 15C 001
/*------ messages -----------------------------------------------------*/
#pragma syscall AddPort 162 901
#pragma syscall RemPort 168 901
#pragma syscall PutMsg 16E 9802
#pragma syscall GetMsg 174 801
#pragma syscall ReplyMsg 17A 901
#pragma syscall WaitPort 180 801
#pragma syscall FindPort 186 901
/*------ libraries ----------------------------------------------------*/
#pragma syscall AddLibrary 18C 901
#pragma syscall RemLibrary 192 901
#pragma syscall OldOpenLibrary 198 901
#pragma syscall CloseLibrary 19E 901
#pragma syscall SetFunction 1A4 08903
#pragma syscall SumLibrary 1AA 901
/*------ devices ------------------------------------------------------*/
#pragma syscall AddDevice 1B0 901
#pragma syscall RemDevice 1B6 901
#pragma syscall OpenDevice 1BC 190804
#pragma syscall CloseDevice 1C2 901
#pragma syscall DoIO 1C8 901
#pragma syscall SendIO 1CE 901
#pragma syscall CheckIO 1D4 901
#pragma syscall WaitIO 1DA 901
#pragma syscall AbortIO 1E0 901
/*------ resources ----------------------------------------------------*/
#pragma syscall AddResource 1E6 901
#pragma syscall RemResource 1EC 901
#pragma syscall OpenResource 1F2 901
/*------ private diagnostic support -----------------------------------*/
/*pragma syscall execPrivate7 1F8 0*/
/*pragma syscall execPrivate8 1FE 0*/
/*pragma syscall execPrivate9 204 0*/
/*------ misc ---------------------------------------------------------*/
#pragma syscall RawDoFmt 20A BA9804
#pragma syscall GetCC 210 0
#pragma syscall TypeOfMem 216 901
#pragma syscall Procure 21C 9802
#pragma syscall Vacate 222 801
#pragma syscall OpenLibrary 228 0902
/*--- functions in V33 or higher (distributed as Release 1.2) ---*/
/*------ signal semaphores (note funny registers)----------------------*/
#pragma syscall InitSemaphore 22E 801
#pragma syscall ObtainSemaphore 234 801
#pragma syscall ReleaseSemaphore 23A 801
#pragma syscall AttemptSemaphore 240 801
#pragma syscall ObtainSemaphoreList 246 801
#pragma syscall ReleaseSemaphoreList 24C 801
#pragma syscall FindSemaphore 252 901
#pragma syscall AddSemaphore 258 901
#pragma syscall RemSemaphore 25E 901
/*------ kickmem support ----------------------------------------------*/
#pragma syscall SumKickData 264 0
/*------ more memory support ------------------------------------------*/
#pragma syscall AddMemList 26A 9821005
#pragma syscall CopyMem 270 09803
#pragma syscall CopyMemQuick 276 09803
/*------ cache --------------------------------------------------------*/
/*--- functions in V36 or higher (distributed as Release 2.0) ---*/
#pragma syscall CacheClearU 27C 0
#pragma syscall CacheClearE 282 10803
#pragma syscall CacheControl 288 1002
/*------ misc ---------------------------------------------------------*/
#pragma syscall CreateIORequest 28E 0802
#pragma syscall DeleteIORequest 294 801
#pragma syscall CreateMsgPort 29A 0
#pragma syscall DeleteMsgPort 2A0 801
#pragma syscall ObtainSemaphoreShared 2A6 801
/*------ even more memory support -------------------------------------*/
#pragma syscall AllocVec 2AC 1002
#pragma syscall FreeVec 2B2 901
#pragma syscall CreatePrivatePool 2B8 21003
#pragma syscall DeletePrivatePool 2BE 801
#pragma syscall AllocPooled 2C4 8002
#pragma syscall FreePooled 2CA 8902
/*------ misc ---------------------------------------------------------*/
#pragma syscall AttemptSemaphoreShared 2D0 801
#pragma syscall ColdReboot 2D6 0
#pragma syscall StackSwap 2DC 801
/*------ task trees ---------------------------------------------------*/
#pragma syscall ChildFree 2E2 001
#pragma syscall ChildOrphan 2E8 001
#pragma syscall ChildStatus 2EE 001
#pragma syscall ChildWait 2F4 001
/*------ future expansion ---------------------------------------------*/
#pragma syscall CachePreDMA 2FA 19803
#pragma syscall CachePostDMA 300 19803
/*pragma syscall execPrivate10 306 0*/
/*pragma syscall execPrivate11 30C 0*/
/*pragma syscall execPrivate12 312 0*/
/*pragma syscall execPrivate13 318 0*/

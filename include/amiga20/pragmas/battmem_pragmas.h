/* "battmem.resource"*/
#pragma libcall BattMemBase ObtainBattSemaphore 6 0
#pragma libcall BattMemBase ReleaseBattSemaphore C 0
#pragma libcall BattMemBase ReadBattMem 12 10803
#pragma libcall BattMemBase WriteBattMem 18 10803

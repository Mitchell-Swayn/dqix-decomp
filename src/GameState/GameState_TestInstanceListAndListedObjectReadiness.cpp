#include <globaldefs.h>
extern "C" void* _ZN9GameState11GetInstanceEv();extern "C" int GameState_GetIndexList();extern "C" int GameState_TestAllListedObjectLinkedFlags();
#pragma optimization_level 4
// Original: arm9/main @ 0x0209C140; symbol: func_0209c140; size: 0x34.
extern "C" ARM int GameState_TestInstanceListAndListedObjectReadiness(){if(_ZN9GameState11GetInstanceEv()&&GameState_GetIndexList()&&GameState_TestAllListedObjectLinkedFlags())return 1;return 0;}

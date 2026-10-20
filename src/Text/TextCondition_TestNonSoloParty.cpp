#include <globaldefs.h>
ARM
extern "C" unsigned char* GameState_GetIndexList(void*);
// Original: arm9/main @ 0x02068650; symbol: func_02068650; size: 0x2C.
extern "C" int TextCondition_TestNonSoloParty(void* p,signed char* entry){int flag=entry[48];if(flag<0)flag=(signed char)GameState_GetIndexList(p)[0xf7c];return flag!=1;}

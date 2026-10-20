#include <globaldefs.h>
ARM
struct GameResources;
extern "C" GameResources* GameResources_GetInstance();
extern "C" int GameResources_GetMaskedPrimaryFlags(GameResources*,unsigned);
extern "C" int LinkedQueue_GetFrontKindOrInvalid(char**);
extern "C" void Script_WriteIntegerReferenceOutput(void*,int);
extern "C" void GameResources_SetPrimaryFlags(unsigned*,unsigned);
// Original: arm9/ov001 @ 0x02162F8C; symbol: func_ov001_02162f8c; size: 0x7C.
extern "C" int Script_TestPendingSceneQueueKind(void* p) {
 GameResources* res=GameResources_GetInstance();
 if(GameResources_GetMaskedPrimaryFlags(res,16)) { Script_WriteIntegerReferenceOutput(p,0); return 1; }
 int flag=LinkedQueue_GetFrontKindOrInvalid(*(char***)((char*)res+0x3700))!=19;
 Script_WriteIntegerReferenceOutput(p,!flag);
 if(flag) GameResources_SetPrimaryFlags((unsigned*)res,16);
 return 1;
}

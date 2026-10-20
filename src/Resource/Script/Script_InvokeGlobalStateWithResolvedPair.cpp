#include <globaldefs.h>
extern "C" void* GameState_GetSerializedProgressState();extern "C" int Script_ReadParameterAsInteger(void*);extern "C" void Script_SetRemappedProgressFlag(void*,int,int);
// Original: arm9/main @ 0x0209D48C; symbol: func_0209d48c; size: 0x44.
extern "C" ARM int Script_InvokeGlobalStateWithResolvedPair(char* p){void* state=GameState_GetSerializedProgressState();if(!state)return 0;int first=Script_ReadParameterAsInteger(p);int second=Script_ReadParameterAsInteger(p+8);Script_SetRemappedProgressFlag(state,first,second);return 1;}

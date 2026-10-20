#include <globaldefs.h>
extern "C" char* GameState_GetSerializedProgressState();extern "C" void BitArray_SetIndexedBoolean(void*,void*,int,int);extern "C" char* GameResources_GetInstance();extern "C" void Field_QueueIndexedProgressBoolean(int,int,int,int);
// Original: arm9/main @ 0x020AE4EC; symbol: func_020ae4ec; size: 0x50.
extern "C" ARM void GameState_SetIndexedFlagAndNotifyOverlay(int index,int flag){char* state=GameState_GetSerializedProgressState();BitArray_SetIndexedBoolean(state,state+0x8c,index+0x33e,flag);state=GameResources_GetInstance();if(!*(int*)(state+0x4458))return;Field_QueueIndexedProgressBoolean(7,index,flag,-1);}

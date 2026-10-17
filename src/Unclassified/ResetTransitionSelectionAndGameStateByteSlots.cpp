#include <globaldefs.h>
ARM
extern "C" void* Object_ReadGlobalDisplayContextWord();extern "C" void BackgroundLoader_CancelEightTasksAndResetState(void*);extern "C" void* ReadWordFieldAtOffset1C();extern "C" void ResetGlobalOwnerAndEmbeddedSelectionState(void*);extern "C" void* _ZN9GameState11GetInstanceEv();extern "C" void GameState_ClearByteSlots(void*);
// Original: arm9/main @ 0x020936B0; symbol: func_020936b0; size: 0x48.
extern "C" void ResetTransitionSelectionAndGameStateByteSlots(unsigned char* p){BackgroundLoader_CancelEightTasksAndResetState(Object_ReadGlobalDisplayContextWord());p[0x37]&=~4;ResetGlobalOwnerAndEmbeddedSelectionState(ReadWordFieldAtOffset1C());*(short*)(p+0x30)=-1;p[0x34]=4;p[0x35]=0;GameState_ClearByteSlots(_ZN9GameState11GetInstanceEv());}

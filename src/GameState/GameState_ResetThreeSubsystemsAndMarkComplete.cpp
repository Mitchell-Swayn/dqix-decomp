#include <globaldefs.h>
#include <Resource/Script.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();extern "C" void* ReadWordFieldAtOffset1C();extern "C" void ResetGlobalOwnerAndEmbeddedSelectionState(void*);extern "C" void* Object_ReadGlobalDisplayContextWord();extern "C" void BackgroundLoader_CancelEightTasksAndResetState(void*);extern "C" void* GameState_GetField3B0ObjectWithFlag4(void*);extern "C" void Object_SetWordAtOffset23CTo1(void*);
// Original: arm9/main @ 0x020D9AB0; symbol: func_020d9ab0; size: 0x38.
extern "C" void GameState_ResetThreeSubsystemsAndMarkComplete(int* p){void* state=_ZN9GameState11GetInstanceEv();ResetGlobalOwnerAndEmbeddedSelectionState(ReadWordFieldAtOffset1C());BackgroundLoader_CancelEightTasksAndResetState(Object_ReadGlobalDisplayContextWord());Object_SetWordAtOffset23CTo1(GameState_GetField3B0ObjectWithFlag4(state));((unsigned char*)p)[1]=1;}

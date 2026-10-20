#include <globaldefs.h>
#include <Resource/Script.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();extern "C" void* TextContext_GetSharedInstance();extern "C" void TextWindow_ResetGlyphBuffersAndFrameContexts(void*);extern "C" void* DisplayContext_GetGlobalInstance();extern "C" void BackgroundLoader_CancelEightTasksAndResetState(void*);extern "C" void* GameState_GetFieldOrbitCamera(void*);extern "C" void Camera_EnableOrbitInput(void*);
// Original: arm9/main @ 0x020D9AB0; symbol: func_020d9ab0; size: 0x38.
extern "C" void GameState_ResetThreeSubsystemsAndMarkComplete(int* p){void* state=_ZN9GameState11GetInstanceEv();TextWindow_ResetGlyphBuffersAndFrameContexts(TextContext_GetSharedInstance());BackgroundLoader_CancelEightTasksAndResetState(DisplayContext_GetGlobalInstance());Camera_EnableOrbitInput(GameState_GetFieldOrbitCamera(state));((unsigned char*)p)[1]=1;}

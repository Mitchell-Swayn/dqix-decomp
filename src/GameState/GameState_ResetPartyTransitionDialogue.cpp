#include <globaldefs.h>
ARM
extern "C" void* DisplayContext_GetGlobalInstance();extern "C" void BackgroundLoader_CancelEightTasksAndResetState(void*);extern "C" void* TextContext_GetSharedInstance();extern "C" void TextWindow_ResetGlyphBuffersAndFrameContexts(void*);extern "C" void* _ZN9GameState11GetInstanceEv();extern "C" void GameState_ClearByteSlots(void*);
// Original: arm9/main @ 0x020936B0; symbol: func_020936b0; size: 0x48.
extern "C" void GameState_ResetPartyTransitionDialogue(unsigned char* p){BackgroundLoader_CancelEightTasksAndResetState(DisplayContext_GetGlobalInstance());p[0x37]&=~4;TextWindow_ResetGlyphBuffersAndFrameContexts(TextContext_GetSharedInstance());*(short*)(p+0x30)=-1;p[0x34]=4;p[0x35]=0;GameState_ClearByteSlots(_ZN9GameState11GetInstanceEv());}

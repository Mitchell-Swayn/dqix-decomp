#include <globaldefs.h>
ARM
struct GameResources;
extern "C" unsigned int TextContext_GetSharedInstance(void);
extern "C" void TextWindow_ResetGlyphBuffersAndFrameContexts(void*);
extern "C" void Graphics_ClearAndStageSharedBuffers(char*);
extern "C" void* ColorAnimation_GetGlobalInstance(void);
extern "C" void ColorAnimation_StartTimedTransition(void*, unsigned);
extern "C" GameResources* GameResources_GetInstance(void);
extern "C" void _Z13SetBrightnessP13GameResourcesii(void*, int, int);
// Original: arm9/ov001 @ 0x02154DA0; symbol: func_ov001_02154da0; size: 0x44.
extern "C" void Graphics_ResetSharedSceneState(void) {
    unsigned char* owner = (unsigned char*)TextContext_GetSharedInstance();
    TextWindow_ResetGlyphBuffersAndFrameContexts(owner);
    Graphics_ClearAndStageSharedBuffers((char*)owner);
    owner[0x19be] = 0;
    ColorAnimation_StartTimedTransition(ColorAnimation_GetGlobalInstance(), 0);
    _Z13SetBrightnessP13GameResourcesii(GameResources_GetInstance(), -16, 0);
}

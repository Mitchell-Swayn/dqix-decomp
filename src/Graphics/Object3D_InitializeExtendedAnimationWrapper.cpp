#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" {
    void TextEntry_ResetGlyphRenderRecord(void *);
// Original: arm9/main @ 0x020416C0; symbol: func_020416c0; size: 0xC.
    void Object3D_InitializeExtendedAnimationWrapper(void *p){
        TextEntry_ResetGlyphRenderRecord(p);
    }
}

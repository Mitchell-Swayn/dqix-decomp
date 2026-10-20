#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" void Object3D_InitializeExtendedAnimationWrapper(void *);
ARM
// Original: arm9/main @ 0x02043040; symbol: func_02043040; size: 0x70.
extern "C" void TextWindow_ResetGlyphPoolAndParserState(char *p) {
    memset(p + 0x2cc, 0, 4); *(unsigned int *)(p + 0x9b4) = 0;
    int i; for (i = 0; i < 0x80; ++i) { Object3D_InitializeExtendedAnimationWrapper(p + 0x9b8 + i * 0x1c); char *flag = p + i; flag += 0x1000; flag[0x7b8] = 0; }
    *(unsigned int *)(p + 0x1868) = 0; *(unsigned int *)(p + 0x9a0) = 0;
    p[0x19b2] = 0; p[0x19b4] = 0;
}

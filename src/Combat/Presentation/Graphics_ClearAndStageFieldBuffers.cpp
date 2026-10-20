#include <globaldefs.h>
ARM
extern "C" unsigned int TextContext_GetSharedInstance(void *);
extern "C" void Graphics_ClearAndStageSharedBuffers(char *);
// Original: arm9/ov025 @ 0x021E5F40; symbol: func_ov025_021e5f40; size: 0x14.
extern "C" int Graphics_ClearAndStageFieldBuffers(void *p) {
    Graphics_ClearAndStageSharedBuffers((char *)TextContext_GetSharedInstance(p));
    return 1;
}

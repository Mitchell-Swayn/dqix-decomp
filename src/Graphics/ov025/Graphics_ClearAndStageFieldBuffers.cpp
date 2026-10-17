#include <globaldefs.h>
ARM
extern "C" unsigned int ReadWordFieldAtOffset1C(void *);
extern "C" void ClearAndStageSharedGraphicsBuffers(char *);
// Original: arm9/ov025 @ 0x021E5F40; symbol: func_ov025_021e5f40; size: 0x14.
extern "C" int Graphics_ClearAndStageFieldBuffers(void *p) {
    ClearAndStageSharedGraphicsBuffers((char *)ReadWordFieldAtOffset1C(p));
    return 1;
}

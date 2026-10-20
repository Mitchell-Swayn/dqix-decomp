#include <globaldefs.h>
ARM
extern "C" bool BackgroundLoader_RemoveTaskAndResetLoadState(void *state);
extern "C" void *memset(void *dst, int value, unsigned int length);
// Original: arm9/ov023 @ 0x021F52C8; symbol: func_ov023_021f52c8; size: 0x30.
extern "C" void ExperienceAdjustment_ResetLoad(void *state) {
    BackgroundLoader_RemoveTaskAndResetLoadState(state);
    memset(state, 0, 0xC);
    *(unsigned int *)((unsigned char *)state + 0x10) = 0xFFFFFFFF;
    BackgroundLoader_RemoveTaskAndResetLoadState(state);
}

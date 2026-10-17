#include <globaldefs.h>
extern "C" void InitializeFourWordsWithInvalidIndex(signed char *p);
extern "C" void _ZN13SafeAllocator21ResetAllocatorPointerEv(void *p);
ARM
// Original: arm9/ov017 @ 0x021AE800; symbol: func_ov017_021ae800; size: 0x5C.
extern "C" void Graphics_InitializeSubEngineState(unsigned char *state) {
    InitializeFourWordsWithInvalidIndex((signed char *)state);
    state[0] = 0x23;
    state[8] = 0;
    *(unsigned short *)(state + 0x0a) = 0;
    *(unsigned short *)(state + 0x0c) = 0;
    _ZN13SafeAllocator21ResetAllocatorPointerEv(state + 0x2c);
    volatile unsigned int *display = (volatile unsigned int *)0x04000000;
    unsigned int mode = (*display & 0x1f00) >> 8;
    unsigned int control = *display;
    *display = (control & ~0x1f00u) | ((mode | 0x10) << 8);
    state[9] = 0;
}

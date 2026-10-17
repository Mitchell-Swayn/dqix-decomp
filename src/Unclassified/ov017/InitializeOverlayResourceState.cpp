#include <globaldefs.h>
#include <System/Memory.h>
ARM
extern "C" void InitializeFourWordsWithInvalidIndex(signed char *);
extern "C" void _ZN13SafeAllocator21ResetAllocatorPointerEv(void *);
extern "C" void InitializeSelectionControlsAndTextBuffers(unsigned char *);
// Original: arm9/ov017 @ 0x021ACD7C; symbol: func_ov017_021acd7c; size: 0x78.
extern "C" void InitializeOverlayResourceState(void *state) {
    InitializeFourWordsWithInvalidIndex((signed char *)state);
    *((unsigned char *)state) = 1;
    _ZN13SafeAllocator21ResetAllocatorPointerEv((char *)state + 8);
    unsigned char *b = (unsigned char *)state;
    b[0x1c] = 0;
    b[0x1d] = 0;
    b[0x27c] = 0;
    b[0x27d] = 0;
    b[0x27e] = 0;
    b[0x1e] = 0;
    b[0x1f] = 0;
    b[0x280] = 0;
    b[0x27f] = 0;
    *(short *)(b + 0x40) = -1;
    b[0x281] = 0;
    b[0x282] = 0;
    *(unsigned int *)(b + 0x20) = 0;
    *(unsigned int *)(b + 0x24) = 0;
    *(unsigned int *)(b + 0x28) = 0;
    VectorizedMemset(b + 0x2c, 0, 0x14);
    InitializeSelectionControlsAndTextBuffers(b + 0x44);
}

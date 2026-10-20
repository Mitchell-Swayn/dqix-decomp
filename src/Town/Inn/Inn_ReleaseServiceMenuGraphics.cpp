#include <globaldefs.h>
ARM
extern "C" void *_ZNK13SafeAllocator18GetSignedAllocatorEv(void *);
extern "C" void _ZN13SafeAllocator7DestroyEv(void *);
extern "C" void Graphics_FinalizeSpriteResourceBuffers(void *);
// Original: arm9/ov003 @ 0x0216D77C; symbol: func_ov003_0216d77c; size: 0x70.
extern "C" void Inn_ReleaseServiceMenuGraphics(void *state) {
    volatile char *base = (volatile char *)state;
    if (_ZNK13SafeAllocator18GetSignedAllocatorEv((void *)(base + 0x2fc + 0x1000)) != 0) _ZN13SafeAllocator7DestroyEv((void *)(base + 0x2fc + 0x1000));
    if (_ZNK13SafeAllocator18GetSignedAllocatorEv((void *)(base + 0x310 + 0x1000)) != 0) _ZN13SafeAllocator7DestroyEv((void *)(base + 0x310 + 0x1000));
    Graphics_FinalizeSpriteResourceBuffers((void *)(base + 0x26c + 0x1000));
    volatile unsigned int *display = (volatile unsigned int *)0x04000000;
    *display = (*display & ~0x1f00) | (*(volatile unsigned int *)base << 8);
}

#include <globaldefs.h>
ARM
extern "C" void *ReadPrimaryOrFallbackPointerAt64(void *);
extern "C" void System_SendMessageWithOverlayFallback(void *, int);
// Original: arm9/ov031 @ 0x022051F4; symbol: func_ov031_022051f4; size: 0x18.
extern "C" void func_ov031_022051f4(void *p, int value) {
    System_SendMessageWithOverlayFallback(ReadPrimaryOrFallbackPointerAt64(p), value);
}

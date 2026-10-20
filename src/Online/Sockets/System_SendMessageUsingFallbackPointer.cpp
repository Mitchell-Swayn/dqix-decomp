#include <globaldefs.h>
ARM
extern "C" void *Network_GetPrimarySocketCommandContext(void *);
extern "C" void System_SendMessageWithOverlayFallback(void *, int);
// Original: arm9/ov031 @ 0x022051F4; symbol: func_ov031_022051f4; size: 0x18.
extern "C" void System_SendMessageUsingFallbackPointer(void *p, int value) {
    System_SendMessageWithOverlayFallback(Network_GetPrimarySocketCommandContext(p), value);
}

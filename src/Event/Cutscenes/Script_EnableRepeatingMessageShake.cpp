#include <globaldefs.h>
ARM
extern "C" unsigned int TextContext_GetSharedInstance(void);
// Original: arm9/ov001 @ 0x0215E920; symbol: func_ov001_0215e920; size: 0x18.
extern "C" void Script_EnableRepeatingMessageShake(void) {
    volatile unsigned char *address = (volatile unsigned char *)(TextContext_GetSharedInstance() + 0x1000);
    address[0x9c1] = 1;
}

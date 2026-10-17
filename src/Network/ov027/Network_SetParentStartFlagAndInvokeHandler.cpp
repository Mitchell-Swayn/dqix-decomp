#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov027_021e33e0[];
extern "C" void func_ov027_021dca40(void *);
// Original: arm9/ov027 @ 0x021DCC24; symbol: func_ov027_021dcc24; size: 0x24.
extern "C" void Network_SetParentStartFlagAndInvokeHandler(void *argument) {
    *(unsigned int *)((unsigned char *)*(void **)(data_ov027_021e33e0 + 0xC) + 0x1320) = 1;
    func_ov027_021dca40(argument);
}

#include <globaldefs.h>
ARM
extern unsigned char data_ov031_02290d18[];
extern "C" void SetStateWithTransitionCallbacks(int);
extern "C" ARM unsigned WirelessCommand_InvokeRequestWithFullMaskAndModeTwo(unsigned, unsigned);
extern "C" void SetSharedObjectWord54UnlessStateNineOrTen(unsigned);
// Original: arm9/ov031 @ 0x022398E8; symbol: func_ov031_022398e8; size: 0x3C.
extern "C" int System_SendWirelessRequest13AndApplyResult(void) {
    SetStateWithTransitionCallbacks(6);
    void *base = *(void **)(data_ov031_02290d18 + 4);
    unsigned result = WirelessCommand_InvokeRequestWithFullMaskAndModeTwo((unsigned)((char *)base + 0x1E00), 0xD);
    if (result == 2) return 1;
    SetSharedObjectWord54UnlessStateNineOrTen(result);
    return 0;
}

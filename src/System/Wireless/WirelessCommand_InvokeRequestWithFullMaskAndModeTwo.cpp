#include <globaldefs.h>

extern "C" void WM_StartDataSharing(unsigned, unsigned, unsigned, unsigned, unsigned);

// Original: arm9/main @ 0x020D68B4; symbol: func_020d68b4; size: 0x1C.
extern "C" ARM void WirelessCommand_InvokeRequestWithFullMaskAndModeTwo(unsigned a, unsigned b) {
    WM_StartDataSharing(a, b, 0xffff, 2, 1);
}

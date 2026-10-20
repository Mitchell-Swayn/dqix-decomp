#include <globaldefs.h>
THUMB
extern "C" void WirelessSetup_EnqueueEvent(void *, int);
// Original: arm9/ov031 @ 0x0221FA88; symbol: func_ov031_0221fa88; size: 0xC.
extern "C" void WirelessSetup_EnqueueTimeoutEvent(void *p) {
    WirelessSetup_EnqueueEvent(p, 0);
}

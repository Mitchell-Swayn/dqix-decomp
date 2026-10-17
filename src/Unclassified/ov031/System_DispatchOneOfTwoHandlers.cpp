#include <globaldefs.h>
ARM
extern "C" void Network_RequestExtendedScan(void);
extern "C" void Network_RequestSharedStateSeven(void);
// Original: arm9/ov031 @ 0x0220CDD4; symbol: func_ov031_0220cdd4; size: 0x20.
extern "C" void System_DispatchOneOfTwoHandlers(void *first, void *second) {
    if (!first || !second)
        Network_RequestSharedStateSeven();
    else
        Network_RequestExtendedScan();
}

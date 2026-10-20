#include <globaldefs.h>
THUMB
extern "C" void WirelessSetup_SendToSharedEndpoint(int a, int b, int c);
// Original: arm9/ov031 @ 0x022201CC; symbol: func_ov031_022201cc; size: 0xC.
extern "C" void WirelessSetup_SendToSharedEndpointIgnoringArgument(int a, int ignored, int b, int c) {
    WirelessSetup_SendToSharedEndpoint(a, b, c);
}

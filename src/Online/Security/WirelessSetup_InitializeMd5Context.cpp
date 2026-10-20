#include <globaldefs.h>
THUMB
// Original: arm9/ov031 @ 0x02221E84; symbol: func_ov031_02221e84; size: 0x28.
extern "C" void WirelessSetup_InitializeMd5Context(unsigned int *context) {
    context[5] = 0;
    context[4] = 0;
    context[0] = 0x67452301;
    context[1] = 0xefcdab89;
    context[2] = 0x98badcfe;
    context[3] = 0x10325476;
}

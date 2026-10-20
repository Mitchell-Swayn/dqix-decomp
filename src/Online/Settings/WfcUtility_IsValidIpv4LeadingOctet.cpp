#include <globaldefs.h>
// Accepts byte values from 1 through 0xDF except 0x7F.
// Original: arm9/ov031 @ 0x0221B258; symbol: func_ov031_0221b258; size: 0x2C.
extern "C" ARM int WfcUtility_IsValidIpv4LeadingOctet(const unsigned char* value)
{
    unsigned char byte = *value;
    if (byte == 0x7F) return 0;
    if (byte < 1) return 0;
    if (byte <= 0xDF) return 1;
    return 0;
}

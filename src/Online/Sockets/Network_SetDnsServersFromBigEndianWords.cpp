#include <globaldefs.h>
ARM
#pragma force_active on
extern "C" int Network_SetDnsServers(unsigned, unsigned);
// Original: arm9/ov031 @ 0x02207538; symbol: func_ov031_02207538; size: 0x6c.
// Reverses byte order in both supplied IPv4 words before storing the DNS pair.
extern "C" int Network_SetDnsServersFromBigEndianWords(const unsigned* primary, const unsigned* secondary)
{
    unsigned second = *secondary;
    unsigned first = *primary;
    first = ((first >> 24) & 255) | ((first >> 8) & 0xff00) | ((first << 8) & 0xff0000) | ((first << 24) & 0xff000000);
    second = ((second >> 24) & 255) | ((second >> 8) & 0xff00) | ((second << 8) & 0xff0000) | ((second << 24) & 0xff000000);
    return Network_SetDnsServers(first, second);
}

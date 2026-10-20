#include <globaldefs.h>
ARM
// Original: arm9/ov031 @ 0x02204878; symbol: func_ov031_02204878; size: 0x30.
extern "C" unsigned char *Network_SkipDnsEncodedName(unsigned char *data) {
    unsigned int value = *data++;
    if (value == 0)
        return data;
    do {
        if ((value & 0xC0) == 0xC0)
            return data + 1;
        data += value;
        value = *data++;
    } while (value != 0);
    return data;
}

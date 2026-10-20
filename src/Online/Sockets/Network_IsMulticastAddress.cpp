#include <globaldefs.h>
ARM
// Original: arm9/ov031 @ 0x02200790; symbol: func_ov031_02200790; size: 0x14.
extern "C" unsigned Network_IsMulticastAddress(unsigned value) {
    return (value & 0xf0000000) == 0xe0000000;
}

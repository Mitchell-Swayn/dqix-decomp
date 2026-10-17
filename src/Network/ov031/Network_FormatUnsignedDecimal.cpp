#include <globaldefs.h>
ARM
struct Powers { unsigned values[9]; };
extern "C" Powers data_ov031_0224954c;
// Original: arm9/ov031 @ 0x02242DD4; symbol: func_ov031_02242dd4; size: 0xBC.
extern "C" unsigned Network_FormatUnsignedDecimal(char *out, unsigned value) {
    Powers powers = data_ov031_0224954c;
    int i;
    int written = 0;
    i = 0;
    bool started = false;
    const char zero = '0';
    for (; i < 9; ++i) {
        unsigned power = powers.values[i];
        if (value >= power) {
            unsigned digit = value / power;
            unsigned used = digit * power;
            started = true;
            if (out) out[written] = digit + '0';
            value -= used;
            ++written;
        } else if (started) {
            if (out) out[written] = zero;
            ++written;
        }
    }
    if (out) out[written] = value + '0';
    return written + 1;
}

#include <globaldefs.h>
ARM
struct Powers { unsigned values[9]; };
// Original data: arm9/ov031 @ 0x224954c; symbol: data_ov031_0224954c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00ca9a3b00e1f5058096980040420f00a086010010270000e8030000640000000a000000040000001400000000f00000.
// Observed span: 48 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" Powers NetworkFormatUnsignedDecimal_UnknownRoleInitializedBytes;
// Original: arm9/ov031 @ 0x02242DD4; symbol: func_ov031_02242dd4; size: 0xBC.
extern "C" unsigned Network_FormatUnsignedDecimal(char *out, unsigned value) {
    Powers powers = NetworkFormatUnsignedDecimal_UnknownRoleInitializedBytes;
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

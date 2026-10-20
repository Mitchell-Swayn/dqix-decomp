#include "System/Matrix.h"

#pragma optimize_for_size off

// Original data: arm9/main @ 0x20ed450; symbol: data_020ed450.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00002000400060008000a000c000e000000120013f015f017f019f01be01de01fd011d023c025c027b029a02b902d802f70216033503540372039103af03cd03 ...; full span in module reference.
// Observed span: 260 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" const int16_t Fix32Atan2_UnknownRoleInitializedBytes[];
// Original data: arm9/main @ 0x20ed554; symbol: data_020ed554.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00005100a300f40046019701e9013a028b02dc022d037e03cf0320047004c10411056105b10501065106a006ef063e078d07dc072a087808c60814096109ae09 ...; full span in module reference.
// Observed span: 260 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" const int16_t Fix32Atan2Rescaled_UnknownRoleInitializedBytes[];

// Original: arm9/main @ 0x020C338C; symbol: fix32_Atan2; size: 0x1B8.
fix32_t fix32_Atan2(fix32_t y, fix32_t x)
{
    fix32_t numerator;
    int base;
    bool add;
    // Reduce the ratio to the first octant, retaining the original axis cases.
    if (y > 0) {
        if (x > 0) {
            if (x > y) {
                numerator = y;
                base = 0;
                add = true;
            }
            else if (x < y) {
                numerator = x;
                x = y;
                base = 0x1922;
                add = false;
            }
            else return 0xc91;
        } else if (x < 0) {
            x = -x;
            if (x < y) {
                numerator = x;
                x = y;
                base = 0x1922;
                add = true;
            }
            else if (x > y) {
                numerator = y;
                base = 0x3244;
                add = false;
            }
            else return 0x25b3;
        } else return 0x1922;
    } else if (y < 0) {
        y = -y;
        if (x < 0) {
            x = -x;
            if (x > y) {
                numerator = y;
                base = -0x3244;
                add = true;
            }
            else if (x < y) {
                numerator = x;
                x = y;
                base = -0x1922;
                add = false;
            }
            else return -0x25b3;
        } else if (x > 0) {
            if (x < y) {
                numerator = x;
                x = y;
                base = -0x1922;
                add = true;
            }
            else if (x > y) {
                numerator = y;
                base = 0;
                add = false;
            }
            else return -0xc91;
        } else return -0x1922;
    } else {
        if (x >= 0) return 0;
        return 0x3244;
    }
    if (x == 0) return 0;
    if (add)
        return (int16_t)(base + Fix32Atan2_UnknownRoleInitializedBytes[fix32_Divide(numerator, x) >> 5]);
    return (int16_t)(base - Fix32Atan2_UnknownRoleInitializedBytes[fix32_Divide(numerator, x) >> 5]);
}

// Original: arm9/main @ 0x020C3544; symbol: fix32_Atan2_Rescaled; size: 0x1A8.
fix32_t fix32_Atan2_Rescaled(fix32_t y, fix32_t x)
{
    fix32_t numerator;
    int base;
    bool add;
    // Reduce the ratio to the first octant, retaining the original axis cases.
    if (y > 0) {
        if (x > 0) {
            if (x > y) {
                numerator = y;
                base = 0;
                add = true;
            }
            else if (x < y) {
                numerator = x;
                x = y;
                base = 0x4000;
                add = false;
            }
            else return 0x2000;
        } else if (x < 0) {
            x = -x;
            if (x < y) {
                numerator = x;
                x = y;
                base = 0x4000;
                add = true;
            }
            else if (x > y) {
                numerator = y;
                base = 0x8000;
                add = false;
            }
            else return 0x6000;
        } else return 0x4000;
    } else if (y < 0) {
        y = -y;
        if (x < 0) {
            x = -x;
            if (x > y) {
                numerator = y;
                base = -0x8000;
                add = true;
            }
            else if (x < y) {
                numerator = x;
                x = y;
                base = -0x4000;
                add = false;
            }
            else return 0xa000;
        } else if (x > 0) {
            if (x < y) {
                numerator = x;
                x = y;
                base = -0x4000;
                add = true;
            }
            else if (x > y) {
                numerator = y;
                base = 0;
                add = false;
            }
            else return 0xe000;
        } else return 0xc000;
    } else {
        if (x >= 0) return 0;
        return 0x8000;
    }
    if (x == 0) return 0;
    if (add)
        return (uint16_t)(base + Fix32Atan2Rescaled_UnknownRoleInitializedBytes[fix32_Divide(numerator, x) >> 5]);
    return (uint16_t)(base - Fix32Atan2Rescaled_UnknownRoleInitializedBytes[fix32_Divide(numerator, x) >> 5]);
}

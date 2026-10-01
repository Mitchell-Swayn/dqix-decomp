#include "System/Matrix.h"

#pragma optimize_for_size off

extern "C" const int16_t data_020ed450[];
extern "C" const int16_t data_020ed554[];

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
        return (int16_t)(base + data_020ed450[fix32_Divide(numerator, x) >> 5]);
    return (int16_t)(base - data_020ed450[fix32_Divide(numerator, x) >> 5]);
}

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
        return (uint16_t)(base + data_020ed554[fix32_Divide(numerator, x) >> 5]);
    return (uint16_t)(base - data_020ed554[fix32_Divide(numerator, x) >> 5]);
}

#pragma optimize_for_size off

extern "C" double Runtime_ComputeDoubleArctangent(double);
extern "C" double Runtime_ComputeDoubleAbsoluteValue(double);

// atan2 reduction for the pinned little-endian binary64 runtime ABI.
// Preserve signed-zero quadrants, NaN propagation and compensated pi reduction.
// The word casts are pinned-MWCC type punning, not portable C++ aliasing.
// Actual union copies and memcpy word views change the matching instructions;
// see docs/workflow/sol61-runtime-math.md for the compiler evidence.
// Original: arm9/main @ 0x02005AC4; symbol: func_02005ac4; size: 0x3DC.
extern "C" double Runtime_ComputeDoubleArctangent2(double y, double x)
{
    int hx, hy, iy, lx, ix, ly;
    hx = ((int*)&x)[1];
    lx = ((int*)&x)[0];
    hy = ((int*)&y)[1];
    ly = ((int*)&y)[0];
    ix = hx & 0x7fffffff;
    iy = hy & 0x7fffffff;
    if ((ix | (((unsigned int)lx | (0u - lx)) >> 31)) > 0x7ff00000 ||
        (iy | (((unsigned int)ly | (0u - ly)) >> 31)) > 0x7ff00000)
        return x + y;
    if ((((unsigned int)hx - 0x3ff00000u) | lx) == 0)
        return Runtime_ComputeDoubleArctangent(y);
    int quadrant = ((hy >> 31) & 1) | ((hx >> 30) & 2);
    if ((iy | ly) == 0) {
        switch (quadrant) {
        case 0:
        case 1:
            return y;
        case 2:
            return 3.141592653589793;
        case 3:
            return -3.141592653589793;
        }
    }
    if ((ix | lx) == 0)
        return hy < 0 ? -1.5707963267948966 : 1.5707963267948966;
    if (ix == 0x7ff00000) {
        if (iy == 0x7ff00000) {
            switch (quadrant) {
            case 0:
                return 0.7853981633974483;
            case 1:
                return -0.7853981633974483;
            case 2:
                return 2.356194490192345;
            case 3:
                return -2.356194490192345;
            }
        } else {
            switch (quadrant) {
            case 0:
                return 0.0;
            case 1:
                return -0.0;
            case 2:
                return 3.141592653589793;
            case 3:
                return -3.141592653589793;
            }
        }
    }
    if (iy == 0x7ff00000)
        return hy < 0 ? -1.5707963267948966 : 1.5707963267948966;
    int exponentDifference = (iy - ix) >> 20;
    double angle;
    if (exponentDifference > 60)
        angle = 1.5707963267948966;
    else if (hx < 0 && exponentDifference < -60)
        angle = 0.0;
    else
        angle = Runtime_ComputeDoubleArctangent(Runtime_ComputeDoubleAbsoluteValue(y / x));
    switch (quadrant) {
    case 0:
        return angle;
    case 1:
        // Flip the stored binary64 sign without changing the fraction bits.
        ((unsigned int*)&angle)[1] ^= 0x80000000;
        return angle;
    case 2:
        return 3.141592653589793 - (angle - 1.2246467991473532e-16);
    default:
        return (angle - 1.2246467991473532e-16) - 3.141592653589793;
    }
}

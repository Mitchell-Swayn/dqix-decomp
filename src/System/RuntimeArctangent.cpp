#include "System/RuntimeArctangent.h"

#pragma optimize_for_size off
extern const RuntimeArctangentAngles gRuntimeArctangentAngles = {{
    2.2698777452961687e-17, 3.061616997868383e-17, 1.3903311031230998e-17, 6.123233995736766e-17
}, {
    0.4636476090008061, 0.7853981633974483, 0.982793723247329, 1.5707963267948966
}};
extern "C" double func_02008f3c(double);
// Preserve the binary64 reduction intervals and compensated polynomial order.
extern "C" double func_02008848(double x)
{
    int high = ((int*)&x)[1];
    int magnitude = high & 0x7fffffff;
    int id;
    if (magnitude >= 0x44100000) {
        if (magnitude > 0x7ff00000 || (magnitude == 0x7ff00000 && ((int*)&x)[0] != 0))
            return x + x;
        if (high > 0)
            return gRuntimeArctangentAngles.high[3] + gRuntimeArctangentAngles.low[3];
        return -gRuntimeArctangentAngles.high[3] - gRuntimeArctangentAngles.low[3];
    }
    if (magnitude < 0x3fdc0000) {
        if (magnitude < 0x3e200000 && 1.0e300 + x > 1.0)
            return x;
        id = -1;
    } else {
        x = func_02008f3c(x);
        if (magnitude < 0x3ff30000) {
            if (magnitude < 0x3fe60000) {
                id = 0;
                x = (2.0 * x - 1.0) / (2.0 + x);
            } else {
                id = 1;
                x = (x - 1.0) / (1.0 + x);
            }
        } else if (magnitude < 0x40038000) {
            id = 2;
            x = (x - 1.5) / (1.0 + 1.5 * x);
        } else {
            id = 3;
            x = -1.0 / x;
        }
    }
    double z = x * x;
    double w = z * z;
    double s1 = z * (gRuntimeArctangentCoefficients[0]
        + w * (gRuntimeArctangentCoefficients[2]
        + w * (gRuntimeArctangentCoefficients[4]
        + w * (gRuntimeArctangentCoefficients[6]
        + w * (gRuntimeArctangentCoefficients[8] + w * gRuntimeArctangentCoefficients[10])))));
    double s2 = w * (gRuntimeArctangentCoefficients[1]
        + w * (gRuntimeArctangentCoefficients[3]
        + w * (gRuntimeArctangentCoefficients[5]
        + w * (gRuntimeArctangentCoefficients[7] + w * gRuntimeArctangentCoefficients[9]))));
    if (id < 0)
        return x - x * (s1 + s2);
    double result = gRuntimeArctangentAngles.high[id] - ((x * (s1 + s2) - gRuntimeArctangentAngles.low[id]) - x);
    return high < 0 ? -result : result;
}

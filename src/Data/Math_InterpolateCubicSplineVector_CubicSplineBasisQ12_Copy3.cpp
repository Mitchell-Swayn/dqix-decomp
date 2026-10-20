// Original data: arm9/ov025 @ 0x21ef100; symbol: data_ov025_021ef100.
// Q12 cubic interpolation basis/control template. Consumer021ee488 copies4x4 matrices and multiplies signed values with rounding then shift12; basis output scaled by one-half. Referenced by Math_InterpolateCubicSplineVector.
// Observed values: hex 000000000000000000000000000000000010000000e0ffff001000000000000000f0ffff00000000001000000000000000000000002000000000000000000000.
// Span: 64 bytes to next configured symbol; logical object size may differ.
#include <globaldefs.h>
// Q12 cubic interpolation basis/control template. Consumer021ee488 copies4x4 matrices and multiplies signed values with rounding then shift12; basis output scaled by one-half.
// Referenced by Math_InterpolateCubicSplineVector.
extern "C" {
extern const signed int Math_InterpolateCubicSplineVector_CubicSplineBasisQ12_Copy3[4][4] = {
    {0, 0, 0, 0},
    {4096, -8192, 4096, 0},
    {-4096, 0, 4096, 0},
    {0, 8192, 0, 0},
};
}

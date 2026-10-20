// Original data: arm9/ov025 @ 0x21ef080; symbol: data_ov025_021ef080.
// Q12 cubic interpolation basis/control template. Consumer021ee488 copies4x4 matrices and multiplies signed values with rounding then shift12; basis output scaled by one-half. Referenced by Math_InterpolateCubicSplineVector.
// Observed values: hex 00f0ffff0030000000d0ffff001000000020000000b0ffff0040000000f0ffff00f0ffff00000000001000000000000000000000002000000000000000000000.
// Span: 64 bytes to next configured symbol; logical object size may differ.
#include <globaldefs.h>
// Q12 cubic interpolation basis/control template. Consumer021ee488 copies4x4 matrices and multiplies signed values with rounding then shift12; basis output scaled by one-half.
// Referenced by Math_InterpolateCubicSplineVector.
extern "C" {
extern const signed int Math_InterpolateCubicSplineVector_CubicSplineBasisQ12[4][4] = {
    {-4096, 12288, -12288, 4096},
    {8192, -20480, 16384, -4096},
    {-4096, 0, 4096, 0},
    {0, 8192, 0, 0},
};
}

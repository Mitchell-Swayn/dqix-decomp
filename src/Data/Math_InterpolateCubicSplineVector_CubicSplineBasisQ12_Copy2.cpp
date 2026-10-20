// Original data: arm9/ov025 @ 0x21ef0c0; symbol: data_ov025_021ef0c0.
// Q12 cubic interpolation basis/control template. Consumer021ee488 copies4x4 matrices and multiplies signed values with rounding then shift12; basis output scaled by one-half. Referenced by Math_InterpolateCubicSplineVector.
// Observed values: hex 00000000000000000000000000100000000000000000000000000000001000000000000000000000000000000010000000000000000000000000000000100000.
// Span: 64 bytes to next configured symbol; logical object size may differ.
#include <globaldefs.h>
// Q12 cubic interpolation basis/control template. Consumer021ee488 copies4x4 matrices and multiplies signed values with rounding then shift12; basis output scaled by one-half.
// Referenced by Math_InterpolateCubicSplineVector.
extern "C" {
extern const signed int Math_InterpolateCubicSplineVector_CubicSplineBasisQ12_Copy2[4][4] = {
    {0, 0, 0, 4096},
    {0, 0, 0, 4096},
    {0, 0, 0, 4096},
    {0, 0, 0, 4096},
};
}

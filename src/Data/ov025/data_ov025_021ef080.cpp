#include <globaldefs.h>
// Q12 cubic interpolation basis/control template. Consumer021ee488 copies4x4 matrices and multiplies signed values with rounding then shift12; basis output scaled by one-half.
// Referenced by Math_InterpolateCubicSplineVector.
extern "C" {
extern const signed int data_ov025_021ef080[4][4] = {
    {-4096, 12288, -12288, 4096},
    {8192, -20480, 16384, -4096},
    {-4096, 0, 4096, 0},
    {0, 8192, 0, 0},
};
}

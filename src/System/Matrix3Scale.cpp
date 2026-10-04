#include "System/Matrix.h"

void Mat3x3_ApplyScale(const Matrix3x3* in, Matrix3x3* out, fix32_t x, fix32_t y, fix32_t z)
{
    out->entries[0] = FIX32_MULTIPLY_SIMPLE(x, in->entries[0]);
    out->entries[1] = FIX32_MULTIPLY_SIMPLE(x, in->entries[1]);
    out->entries[2] = FIX32_MULTIPLY_SIMPLE(x, in->entries[2]);
    out->entries[3] = FIX32_MULTIPLY_SIMPLE(y, in->entries[3]);
    out->entries[4] = FIX32_MULTIPLY_SIMPLE(y, in->entries[4]);
    out->entries[5] = FIX32_MULTIPLY_SIMPLE(y, in->entries[5]);
    out->entries[6] = FIX32_MULTIPLY_SIMPLE(z, in->entries[6]);
    out->entries[7] = FIX32_MULTIPLY_SIMPLE(z, in->entries[7]);
    out->entries[8] = FIX32_MULTIPLY_SIMPLE(z, in->entries[8]);
}

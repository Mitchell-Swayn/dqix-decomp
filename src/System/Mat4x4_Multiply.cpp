#include "System/Matrix.h"
#pragma thumb off
// SDK optimization profile: O4 with speed optimization reproduces the 64-bit accumulators.
#pragma optimization_level 4
#pragma optimize_for_size off
// Original: arm9/main @ 0x020C223C; symbol: Mat4x4_Multiply; size: 0x664.
// NitroSDK MTX_Concat44 family: 20.12 fixed-point matrix product with alias-safe output.
// Reference: pret/pokediamond@b623abef1b4dfe204ca50aab42447ac00c134290 arm9/lib/NitroSDK/src/FX_mtx44.c
// The column write order captures input rows/columns before overwriting aliases.
void Mat4x4_Multiply(const Matrix4x4* a, const Matrix4x4* b, Matrix4x4* c){
    Matrix4x4 temp;
    Matrix4x4 *dst;
    fix32_t a0, a1, a2, a3;
    fix32_t b0, b1, b2, b3;

    if (c == b)
        dst = &temp;
    else
        dst = c;

    a0 = a->entries[0];
    a1 = a->entries[1];
    a2 = a->entries[2];
    a3 = a->entries[3];
    dst->entries[0] =  (fix32_t)(((int64_t)a0  * b->entries[0] + (int64_t)a1  * b->entries[4] + (int64_t)a2  * b->entries[8]  + (int64_t)a3  * b->entries[12]) >> 12);
    dst->entries[1] =  (fix32_t)(((int64_t)a0  * b->entries[1] + (int64_t)a1  * b->entries[5] + (int64_t)a2  * b->entries[9]  + (int64_t)a3  * b->entries[13]) >> 12);
    dst->entries[3] =  (fix32_t)(((int64_t)a0  * b->entries[3] + (int64_t)a1  * b->entries[7] + (int64_t)a2  * b->entries[11] + (int64_t)a3  * b->entries[15]) >> 12);
    b0 = b->entries[2];
    b1 = b->entries[6];
    b2 = b->entries[10];
    b3 = b->entries[14];
    dst->entries[2] =  (fix32_t)(((int64_t)a0  * b0 + (int64_t)a1  * b1 + (int64_t)a2  * b2 + (int64_t)a3  * b3) >> 12);
    a0 = a->entries[4];
    a1 = a->entries[5];
    a2 = a->entries[6];
    a3 = a->entries[7];
    dst->entries[6] =  (fix32_t)(((int64_t)a0  * b0 + (int64_t)a1  * b1 + (int64_t)a2  * b2 + (int64_t)a3  * b3) >> 12);
    dst->entries[5] =  (fix32_t)(((int64_t)a0  * b->entries[1] + (int64_t)a1  * b->entries[5] + (int64_t)a2  * b->entries[9]  + (int64_t)a3  * b->entries[13]) >> 12);
    dst->entries[7] =  (fix32_t)(((int64_t)a0  * b->entries[3] + (int64_t)a1  * b->entries[7] + (int64_t)a2  * b->entries[11] + (int64_t)a3  * b->entries[15]) >> 12);
    b0 = b->entries[0];
    b1 = b->entries[4];
    b2 = b->entries[8];
    b3 = b->entries[12];
    dst->entries[4] =  (fix32_t)(((int64_t)a0  * b0 + (int64_t)a1  * b1 + (int64_t)a2  * b2  + (int64_t)a3  * b3) >> 12);
    a0 = a->entries[8];
    a1 = a->entries[9];
    a2 = a->entries[10];
    a3 = a->entries[11];
    dst->entries[8] =  (fix32_t)(((int64_t)a0  * b0 + (int64_t)a1  * b1 + (int64_t)a2 * b2  + (int64_t)a3 * b3) >> 12);
    dst->entries[9] =  (fix32_t)(((int64_t)a0  * b->entries[1] + (int64_t)a1  * b->entries[5] + (int64_t)a2 * b->entries[9]  + (int64_t)a3 * b->entries[13]) >> 12);
    dst->entries[11] = (fix32_t)(((int64_t)a0  * b->entries[3] + (int64_t)a1  * b->entries[7] + (int64_t)a2 * b->entries[11] + (int64_t)a3 * b->entries[15]) >> 12);
    b0 = b->entries[2];
    b1 = b->entries[6];
    b2 = b->entries[10];
    b3 = b->entries[14];
    dst->entries[10] = (fix32_t)(((int64_t)a0  * b0 + (int64_t)a1  * b1 + (int64_t)a2 * b2 + (int64_t)a3 * b3) >> 12);
    a0 = a->entries[12];
    a1 = a->entries[13];
    a2 = a->entries[14];
    a3 = a->entries[15];
    dst->entries[14] = (fix32_t)(((int64_t)a0 * b0 + (int64_t)a1 * b1 + (int64_t)a2 * b2 + (int64_t)a3 * b3) >> 12);
    dst->entries[13] = (fix32_t)(((int64_t)a0 * b->entries[1] + (int64_t)a1 * b->entries[5] + (int64_t)a2 * b->entries[9]  + (int64_t)a3 * b->entries[13]) >> 12);
    dst->entries[12] = (fix32_t)(((int64_t)a0 * b->entries[0] + (int64_t)a1 * b->entries[4] + (int64_t)a2 * b->entries[8]  + (int64_t)a3 * b->entries[12]) >> 12);
    dst->entries[15] = (fix32_t)(((int64_t)a0 * b->entries[3] + (int64_t)a1 * b->entries[7] + (int64_t)a2 * b->entries[11] + (int64_t)a3 * b->entries[15]) >> 12);
    if (dst == &temp)
        *c = temp;
}

#include <System/Matrix.h>
// Original: arm9/main @ 0x020C15A4; symbol: Mat3x3_Multiply; size: 0x220.
// NitroSDK MTX_Concat33, pinned pret/pokediamond 4c44373472ce77ac6462d7e082f2611ac56320e9.
// Multiplies row-major signed 20.12 matrices with a 64-bit sum per entry.
// Row caching permits output == a; a temporary preserves b when output == b.
extern "C" void Mat3x3_Multiply(const Matrix3x3 *a, const Matrix3x3 *b, Matrix3x3 *c){
    Matrix3x3 temp;
    Matrix3x3 *dst;
    fix32_t a0, a1, a2;
    fix32_t b0, b1, b2;

    if (c == b)
        dst = &temp;
    else
        dst = c;

    a0 = a->entries[0];
    a1 = a->entries[1];
    a2 = a->entries[2];
    dst->entries[0] =  (fix32_t)(((int64_t)a0  * b->entries[0] + (int64_t)a1  * b->entries[3] + (int64_t)a2  * b->entries[6] ) >> 12);
    dst->entries[1] =  (fix32_t)(((int64_t)a0  * b->entries[1] + (int64_t)a1  * b->entries[4] + (int64_t)a2  * b->entries[7] ) >> 12);
    b0 = b->entries[2];
    b1 = b->entries[5];
    b2 = b->entries[8];
    dst->entries[2] =  (fix32_t)(((int64_t)a0  * b0 + (int64_t)a1  * b1 + (int64_t)a2  * b2) >> 12);
    a0 = a->entries[3];
    a1 = a->entries[4];
    a2 = a->entries[5];
    dst->entries[5] =  (fix32_t)(((int64_t)a0  * b0 + (int64_t)a1  * b1 + (int64_t)a2  * b2) >> 12);
    dst->entries[4] =  (fix32_t)(((int64_t)a0  * b->entries[1] + (int64_t)a1  * b->entries[4] + (int64_t)a2  * b->entries[7] ) >> 12);
    b0 = b->entries[0];
    b1 = b->entries[3];
    b2 = b->entries[6];
    dst->entries[3] =  (fix32_t)(((int64_t)a0  * b0 + (int64_t)a1  * b1 + (int64_t)a2  * b2) >> 12);
    a0 = a->entries[6];
    a1 = a->entries[7];
    a2 = a->entries[8];
    dst->entries[6] =  (fix32_t)(((int64_t)a0  * b0 + (int64_t)a1  * b1 + (int64_t)a2 * b2) >> 12);
    dst->entries[7] =  (fix32_t)(((int64_t)a0  * b->entries[1] + (int64_t)a1  * b->entries[4] + (int64_t)a2 * b->entries[7] ) >> 12);
    b0 = b->entries[2];
    b1 = b->entries[5];
    b2 = b->entries[8];
    dst->entries[8] = (fix32_t)(((int64_t)a0  * b0 + (int64_t)a1  * b1 + (int64_t)a2 * b2) >> 12);
    if (dst == &temp)
        *c = temp;
}

#include "System/Matrix.h"

#define SQRT_CONTROL (*(volatile uint16_t*)0x040002b0)
#define SQRT_RESULT (*(volatile int32_t*)0x040002b4)
#define SQRT_PARAMETER (*(volatile uint64_t*)0x040002b8)

void Vector3fix_Add(const Vector3fix* a, const Vector3fix* b, Vector3fix* out)
{
    out->x = a->x + b->x;
    out->y = a->y + b->y;
    out->z = a->z + b->z;
}

void Vector3fix_Subtract(const Vector3fix* a, const Vector3fix* b, Vector3fix* out)
{
    out->x = a->x - b->x;
    out->y = a->y - b->y;
    out->z = a->z - b->z;
}

fix32_t Vector3fix_InnerProduct(const Vector3fix* a, const Vector3fix* b)
{
    // Round the combined product, rather than each component independently.
    return (fix32_t)(((int64_t)a->x * b->x + (int64_t)a->y * b->y
                     + (int64_t)a->z * b->z + 0x800) >> 12);
}

void Vector3fix_CrossProduct(const Vector3fix* a, const Vector3fix* b, Vector3fix* out)
{
    // Capture every component before writing so out may alias either input.
    // Local declaration order preserves the matching compiler's register allocation.
    fix32_t bz = b->z;
    fix32_t ax = a->x;
    fix32_t az = a->z;
    fix32_t bx = b->x;
    fix32_t ay = a->y;
    fix32_t by = b->y;
    out->x = (fix32_t)(((int64_t)ay * bz - (int64_t)az * by + 0x800) >> 12);
    out->y = (fix32_t)(((int64_t)az * bx - (int64_t)ax * bz + 0x800) >> 12);
    out->z = (fix32_t)(((int64_t)ax * by - (int64_t)ay * bx + 0x800) >> 12);
}

fix32_t Vector3fix_Length(const Vector3fix* vec)
{
    fix32_t x = vec->x;
    fix32_t y = vec->y;
    fix32_t z = vec->z;
    int64_t squared = (int64_t)x * x + (int64_t)y * y + (int64_t)z * z;
    // Retain one extra bit through the hardware square root, then round it.
    squared <<= 2;
    SQRT_CONTROL = 1; // 64-bit operand
    SQRT_PARAMETER = squared;
    while (SQRT_CONTROL & 0x8000) {}
    return (SQRT_RESULT + 1) >> 1;
}

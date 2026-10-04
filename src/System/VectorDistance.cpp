#include "System/Matrix.h"

#define SQRT_CONTROL (*(volatile uint16_t*)0x040002b0)
#define SQRT_RESULT (*(volatile int32_t*)0x040002b4)
#define SQRT_PARAMETER (*(volatile uint64_t*)0x040002b8)

inline int64_t SquareComponent(fix32_t value)
{
    return (int64_t)value * value;
}

fix32_t Vector3fix_Distance(const Vector3fix* a, const Vector3fix* b)
{
    fix32_t x = a->x - b->x;
    int64_t squared = SquareComponent(x) + SquareComponent((a->y - b->y)) + SquareComponent((a->z - b->z));
    SQRT_CONTROL = 1;
    SQRT_PARAMETER = squared << 2;
    while (SQRT_CONTROL & 0x8000) {}
    return (SQRT_RESULT + 1) >> 1;
}

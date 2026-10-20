#include "System/Matrix.h"

// Hardware divider/square-root registers. Only the result registers and the
// busy-flag polls are volatile; the setup writes are plain stores in the original.
#define DIV_CONTROL (*(uint16_t*)0x04000280)
#define DIV_NUMERATOR (*(uint64_t*)0x04000290)
#define DIV_DENOMINATOR (*(uint64_t*)0x04000298)
#define DIV_RESULT (*(volatile int64_t*)0x040002a0)
#define SQRT_CONTROL (*(uint16_t*)0x040002b0)
#define SQRT_RESULT (*(volatile uint32_t*)0x040002b4)
#define SQRT_PARAMETER (*(uint64_t*)0x040002b8)
#define DIV_BUSY (*(volatile uint16_t*)0x04000280)
#define SQRT_BUSY (*(volatile uint16_t*)0x040002b0)

// Original: arm9/main @ 0x020C2F18; symbol: Vector3fix_Normalize; size: 0x118.
extern "C" void Vector3fix_Normalize(const Vector3fix* in, Vector3fix* out)
{
    fix32_t x = in->x;
    fix32_t y = in->y;
    fix32_t z = in->z;
    int64_t sum = (int64_t)x * x;
    sum += (int64_t)y * y;
    sum += (int64_t)z * z;

    // 1.0 / |v|^2 on the divider, |v| (with one extra bit) on the square root unit.
    DIV_CONTROL = 2;
    DIV_NUMERATOR = (uint64_t)0x1000000 << 32;
    DIV_DENOMINATOR = sum;
    SQRT_CONTROL = 1;
    SQRT_PARAMETER = (uint64_t)sum << 2;

    while (SQRT_BUSY & 0x8000) {}
    int32_t root = SQRT_RESULT;
    while (DIV_BUSY & 0x8000) {}
    int64_t scale = (int64_t)DIV_RESULT * root;

    out->x = (int32_t)((scale * in->x + ((int64_t)1 << 44)) >> 45);
    out->y = (int32_t)((scale * in->y + ((int64_t)1 << 44)) >> 45);
    out->z = (int32_t)((scale * in->z + ((int64_t)1 << 44)) >> 45);
}

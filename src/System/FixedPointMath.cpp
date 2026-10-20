#include "System/Matrix.h"

#define DIV_CONTROL (*(volatile uint16_t*)0x04000280)
#define DIV_NUMERATOR (*(volatile uint64_t*)0x04000290)
#define DIV_NUMERATOR_LOW (*(volatile int32_t*)0x04000290)
#define DIV_DENOMINATOR (*(volatile uint64_t*)0x04000298)
#define DIV_RESULT (*(volatile int64_t*)0x040002a0)
#define DIV_RESULT_LOW (*(volatile int32_t*)0x040002a0)
#define DIV_REMAINDER_LOW (*(volatile int32_t*)0x040002a8)
#define SQRT_CONTROL (*(volatile uint16_t*)0x040002b0)
#define SQRT_RESULT (*(volatile uint32_t*)0x040002b4)
#define SQRT_PARAMETER (*(volatile uint64_t*)0x040002b8)

// Original: arm9/main @ 0x020C2BF4; symbol: fix32_Divide; size: 0x10.
fix32_t fix32_Divide(fix32_t num, fix32_t denom)
{
    fix32_QueueComputeQuotient(num, denom);
    return fix32_GetDivisionResult();
}

// Original: arm9/main @ 0x020C2C04; symbol: fix32_Sqrt; size: 0x34.
fix32_t fix32_Sqrt(fix32_t x)
{
    if (x <= 0)
        return 0;
    SQRT_CONTROL = 1;
    SQRT_PARAMETER = (uint64_t)(uint32_t)x << 32;
    return fix32_GetSqrtResult();
}

// Original: arm9/main @ 0x020C2C38; symbol: GetHardwareDividerResult; size: 0x24.
int64_t GetHardwareDividerResult()
{
    while (DIV_CONTROL & 0x8000) {}
    // The completed result is read as one register pair (LDM in the original).
    return *(const int64_t*)0x040002a0;
}

// Original: arm9/main @ 0x020C2C5C; symbol: fix32_GetDivisionResult; size: 0x38.
fix32_t fix32_GetDivisionResult()
{
    while (DIV_CONTROL & 0x8000) {}
    return (fix32_t)((DIV_RESULT + 0x80000) >> 20);
}

// Original: arm9/main @ 0x020C2C94; symbol: fix32_QueueComputeReciprocal; size: 0x30.
void fix32_QueueComputeReciprocal(fix32_t x)
{
    DIV_CONTROL = 1;
    DIV_NUMERATOR = (uint64_t)1 << 44;
    DIV_DENOMINATOR = (uint32_t)x;
}

// Original: arm9/main @ 0x020C2CC4; symbol: fix32_GetSqrtResult; size: 0x2C.
fix32_t fix32_GetSqrtResult()
{
    while (SQRT_CONTROL & 0x8000) {}
    return (SQRT_RESULT + 0x200) >> 10;
}

// Original: arm9/main @ 0x020C2CF0; symbol: fix32_QueueComputeQuotient; size: 0x28.
void fix32_QueueComputeQuotient(fix32_t num, fix32_t denom)
{
    DIV_CONTROL = 1;
    DIV_NUMERATOR = (uint64_t)(uint32_t)num << 32;
    DIV_DENOMINATOR = (uint32_t)denom;
}

// Original: arm9/main @ 0x020C2D18; symbol: FastIntDivide; size: 0x3C.
int32_t FastIntDivide(int32_t a, int32_t b)
{
    DIV_CONTROL = 0;
    DIV_NUMERATOR_LOW = a;
    DIV_DENOMINATOR = (uint32_t)b;
    while (DIV_CONTROL & 0x8000) {}
    return DIV_RESULT_LOW;
}

// Original: arm9/main @ 0x020C2D54; symbol: FastIntModulus; size: 0x3C.
int32_t FastIntModulus(int32_t a, int32_t b)
{
    DIV_CONTROL = 0;
    DIV_NUMERATOR_LOW = a;
    DIV_DENOMINATOR = (uint32_t)b;
    while (DIV_CONTROL & 0x8000) {}
    return DIV_REMAINDER_LOW;
}

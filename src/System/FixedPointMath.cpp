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

fix32_t fix32_Divide(fix32_t num, fix32_t denom)
{
    fix32_QueueComputeQuotient(num, denom);
    return fix32_GetDivisionResult();
}

fix32_t fix32_Sqrt(fix32_t x)
{
    if (x <= 0)
        return 0;
    SQRT_CONTROL = 1;
    SQRT_PARAMETER = (uint64_t)(uint32_t)x << 32;
    return fix32_GetSqrtResult();
}

int64_t GetHardwareDividerResult()
{
    while (DIV_CONTROL & 0x8000) {}
    // The completed result is read as one register pair (LDM in the original).
    return *(const int64_t*)0x040002a0;
}

fix32_t fix32_GetDivisionResult()
{
    while (DIV_CONTROL & 0x8000) {}
    return (fix32_t)((DIV_RESULT + 0x80000) >> 20);
}

void fix32_QueueComputeReciprocal(fix32_t x)
{
    DIV_CONTROL = 1;
    DIV_NUMERATOR = (uint64_t)1 << 44;
    DIV_DENOMINATOR = (uint32_t)x;
}

fix32_t fix32_GetSqrtResult()
{
    while (SQRT_CONTROL & 0x8000) {}
    return (SQRT_RESULT + 0x200) >> 10;
}

void fix32_QueueComputeQuotient(fix32_t num, fix32_t denom)
{
    DIV_CONTROL = 1;
    DIV_NUMERATOR = (uint64_t)(uint32_t)num << 32;
    DIV_DENOMINATOR = (uint32_t)denom;
}

int32_t FastIntDivide(int32_t a, int32_t b)
{
    DIV_CONTROL = 0;
    DIV_NUMERATOR_LOW = a;
    DIV_DENOMINATOR = (uint32_t)b;
    while (DIV_CONTROL & 0x8000) {}
    return DIV_RESULT_LOW;
}

int32_t FastIntModulus(int32_t a, int32_t b)
{
    DIV_CONTROL = 0;
    DIV_NUMERATOR_LOW = a;
    DIV_DENOMINATOR = (uint32_t)b;
    while (DIV_CONTROL & 0x8000) {}
    return DIV_REMAINDER_LOW;
}

#include "System/Matrix.h"

#pragma optimize_for_size off

void Mat4x4_MaybeWriteFrustum(fix32_t sine, fix32_t cosine, fix32_t aspect, fix32_t near, fix32_t far, fix32_t scale, Matrix4x4* out)
{
    fix32_t cotangent = fix32_Divide(cosine, sine);
    *(volatile uint64_t*)0x04000290 = 1ULL << 44;
    *(volatile uint64_t*)0x04000298 = (uint32_t)(near - far);
    if (scale != 0x1000)
        cotangent = (cotangent * scale) / 0x1000;
    out->entries[1] = 0;
    out->entries[2] = 0;
    out->entries[3] = 0;
    out->entries[4] = 0;
    out->entries[5] = cotangent;
    out->entries[6] = 0;
    out->entries[7] = 0;
    out->entries[8] = 0;
    out->entries[9] = 0;
    out->entries[11] = -scale;
    out->entries[12] = 0;
    out->entries[13] = 0;
    out->entries[15] = 0;
    int64_t reciprocal = GetHardwareDividerResult();
    // These paired writes preserve the original STM sequence before result polling.
    *(uint64_t*)0x04000290 = (uint64_t)(uint32_t)cotangent << 32;
    *(uint64_t*)0x04000298 = (uint32_t)aspect;
    if (scale != 0x1000)
        reciprocal = reciprocal * scale / 0x1000;
    fix32_t depth = FIX32_MULTIPLY(near << 1, far);
    out->entries[10] = (fix32_t)((reciprocal * (far + near) + 0x80000000LL) >> 32);
    out->entries[14] = (fix32_t)((reciprocal * depth + 0x80000000LL) >> 32);
    out->entries[0] = fix32_GetDivisionResult();
}

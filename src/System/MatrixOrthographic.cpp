#include "System/Matrix.h"

#pragma optimize_for_size off

void Mat4x4_WriteProjectionUnknown(fix32_t top, fix32_t bottom, fix32_t left, fix32_t right, fix32_t near, fix32_t far, fix32_t scale, Matrix4x4* out)
{
    fix32_QueueComputeReciprocal(right - left);
    out->entries[1] = 0;
    out->entries[2] = 0;
    out->entries[3] = 0;
    out->entries[4] = 0;
    out->entries[6] = 0;
    out->entries[7] = 0;
    out->entries[8] = 0;
    out->entries[9] = 0;
    out->entries[11] = 0;
    out->entries[15] = scale;
    int64_t width = GetHardwareDividerResult();
    *(volatile uint64_t*)0x04000290 = 1ULL << 44;
    *(volatile uint64_t*)0x04000298 = (uint32_t)(top - bottom);
    if (scale != 0x1000)
        width = width * scale / 0x1000;
    out->entries[0] = (fix32_t)(((width << 13) + 0x80000000LL) >> 32);
    int64_t height = GetHardwareDividerResult();
    *(volatile uint64_t*)0x04000290 = 1ULL << 44;
    *(volatile uint64_t*)0x04000298 = (uint32_t)(near - far);
    if (scale != 0x1000)
        height = height * scale / 0x1000;
    out->entries[5] = (fix32_t)(((height << 13) + 0x80000000LL) >> 32);
    int64_t depth = GetHardwareDividerResult();
    if (scale != 0x1000)
        depth = depth * scale / 0x1000;
    out->entries[10] = (fix32_t)(((depth << 13) + 0x80000000LL) >> 32);
    out->entries[12] = (fix32_t)((width * -(right + left) + 0x80000000LL) >> 32);
    out->entries[13] = (fix32_t)((height * -(top + bottom) + 0x80000000LL) >> 32);
    out->entries[14] = (fix32_t)((depth * (far + near) + 0x80000000LL) >> 32);
}

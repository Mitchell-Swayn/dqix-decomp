#include "System/Matrix.h"

// Existing binary helper copies the 36-byte rotation block.
extern "C" void func_020ca528(const void*, void*);

void Mat4x3_ApplyTranslation(const Matrix4x3* in, Matrix4x3* out, fix32_t x, fix32_t y, fix32_t z)
{
    if (in != out)
        func_020ca528(in, out);
    out->translation.x = in->translation.x + (fix32_t)(((int64_t)x * in->entries[0]
        + (int64_t)y * in->entries[3] + (int64_t)z * in->entries[6]) >> 12);
    out->translation.y = in->translation.y + (fix32_t)(((int64_t)x * in->entries[1]
        + (int64_t)y * in->entries[4] + (int64_t)z * in->entries[7]) >> 12);
    out->translation.z = in->translation.z + (fix32_t)(((int64_t)x * in->entries[2]
        + (int64_t)y * in->entries[5] + (int64_t)z * in->entries[8]) >> 12);
}

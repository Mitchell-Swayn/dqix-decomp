#include "System/Matrix.h"

void Mat4x3_ApplyScale(const Matrix4x3* in, Matrix4x3* out, fix32_t x, fix32_t y, fix32_t z)
{
    Mat3x3_ApplyScale(&in->rotation, &out->rotation, x, y, z);
    out->translation.x = in->translation.x;
    out->translation.y = in->translation.y;
    out->translation.z = in->translation.z;
}

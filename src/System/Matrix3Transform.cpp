#include "System/Matrix.h"

void Mat3x3_ApplyToVector(const Vector3fix* inVec, const Matrix3x3* inMat, Vector3fix* out)
{
    // Capture inputs before writing output; declaration order preserves register allocation.
    fix32_t y = inVec->y;
    fix32_t x = inVec->x;
    fix32_t z = inVec->z;
    out->x = (fix32_t)(((int64_t)x * inMat->entries[0] + (int64_t)y * inMat->entries[3]
                       + (int64_t)z * inMat->entries[6]) >> 12);
    out->y = (fix32_t)(((int64_t)x * inMat->entries[1] + (int64_t)y * inMat->entries[4]
                       + (int64_t)z * inMat->entries[7]) >> 12);
    out->z = (fix32_t)(((int64_t)x * inMat->entries[2] + (int64_t)y * inMat->entries[5]
                       + (int64_t)z * inMat->entries[8]) >> 12);
}

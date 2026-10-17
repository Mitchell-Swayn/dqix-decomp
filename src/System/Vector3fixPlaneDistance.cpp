#include "System/Matrix.h"

// Original: arm9/main @ 0x02032124; symbol: func_02032124; size: 0x24.
extern "C" fix32_t Vector_ComputeSignedPlaneDistance(const Vector3fix* vector,
                                 const Vector4fix* plane)
{
    return Vector3fix_InnerProduct(&plane->xyz, vector) - plane->w;
}

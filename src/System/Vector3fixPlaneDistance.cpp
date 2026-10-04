#include "System/Matrix.h"

extern "C" fix32_t func_02032124(const Vector3fix* vector,
                                 const Vector4fix* plane)
{
    return Vector3fix_InnerProduct(&plane->xyz, vector) - plane->w;
}

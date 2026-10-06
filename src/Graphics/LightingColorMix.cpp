#include "Graphics/LightingManager.h"

extern "C" void func_0207ba28(Vector3float* colors, int index,
                               float* red, float* green, float* blue)
{
    const Vector3float& color = colors[index];
    *red = color.x;
    *green = color.y;
    *blue = color.z;
}

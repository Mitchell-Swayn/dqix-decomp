#include <System/Matrix.h>
#include <Graphics/Vector.h>

// Original: arm9/main @ 0x0202EA4C; symbol: func_0202ea4c; size: 0x6C.
extern "C" void Object_ComputeHeadingHeightDifferenceAndDistance(int object, int, int, int) {
    Vector3fix difference;
    Vector3fix_Subtract((Vector3fix *)(object + 4),
                        (Vector3fix *)(object + 0x10), &difference);
    difference.y = 0;
    Vector3fix_Normalize(&difference, &difference);
    fix32_t angle = fix32_Atan2(difference.x, difference.z);
    *(fix32_t *)(object + 0x70) = fix32ReduceAngle0To2Pi(angle);
    *(fix32_t *)(object + 0x74) = *(fix32_t *)(object + 8) -
                                  *(fix32_t *)(object + 0x14);
    *(fix32_t *)(object + 0x78) = Vector3fix_Distance(
        (Vector3fix *)(object + 4), (Vector3fix *)(object + 0x10));
}

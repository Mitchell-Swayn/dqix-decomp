#include <globaldefs.h>
#include <System/Matrix.h>
ARM
// Original: arm9/ov017 @ 0x021C3F68; symbol: Vector3i_StoreComponents; size: 0x8.
// Stores the three integer components of a Vector3i; callers populate vectors from object position fields and coordinate values.
extern "C" void Vector3i_StoreComponents(Vector3i* vector, int x, int y, int z) {
    vector->x = x;
    vector->y = y;
    vector->z = z;
}

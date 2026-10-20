#include <globaldefs.h>
#include <System/Matrix.h>
extern "C" void ComputeRotatedEndpointFromAngleHeightAndLength(void*, int, int, int);
// Original: arm9/main @ 0x0202EC5C; symbol: func_0202ec5c; size: 0x28.
extern "C" void Camera_SetTargetPreservingOrbit(void* object, const Vector3i* value) {
    *(Vector3i*)((char*)object + 0x10) = *value;
    ComputeRotatedEndpointFromAngleHeightAndLength(object, *(int*)((char*)object + 0x70), *(int*)((char*)object + 0x74), *(int*)((char*)object + 0x78));
}

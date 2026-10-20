#include <globaldefs.h>

extern "C" void Camera_ApplyManualInput(void*);
extern "C" void Camera_UpdateOrDeferTargetFollowing(void*);

// Original: arm9/main @ 0x020A20D8; symbol: func_020a20d8; size: 0x18.
extern "C" ARM void Camera_UpdateManualInputAndTargetFollowing(void* object) {
    Camera_ApplyManualInput(object);
    Camera_UpdateOrDeferTargetFollowing(object);
}

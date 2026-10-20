#include <globaldefs.h>
ARM
extern "C" void Camera_InitializeTargetFollowingState(char *);
extern "C" void Camera_InitializeManualControlState(int);
extern "C" void Object_InitializeTransformAndEmbeddedStateDefaults(unsigned int *);
// Original: arm9/ov004 @ 0x02163408; symbol: func_ov004_02163408; size: 0x24.
extern "C" void *InitializeObjectVectorsStateAndTransform(void *object) {
    Camera_InitializeTargetFollowingState((char *)object);
    Camera_InitializeManualControlState((int)object);
    Object_InitializeTransformAndEmbeddedStateDefaults((unsigned int *)object);
    return object;
}

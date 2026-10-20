#include <globaldefs.h>
extern "C" void Object_InitializeTransformAndEmbeddedStateDefaults(void);
extern "C" void Camera_SetObjectFlags(int, int);
// Original: arm9/main @ 0x020A2CF0; symbol: func_020a2cf0; size: 0x24.
extern "C" void Camera_InitializeManualControlState(int object) {
    Object_InitializeTransformAndEmbeddedStateDefaults();
    Camera_SetObjectFlags(object,2);
    *(int*)(object+0x218)=0;
}

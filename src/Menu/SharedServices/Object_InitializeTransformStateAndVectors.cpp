#include <globaldefs.h>
ARM
extern "C" void Object_InitializeTransformAndEmbeddedStateDefaults(unsigned*);
extern "C" void Camera_InitializeManualControlState(int);
extern "C" void Camera_InitializeTargetFollowingState(char*);
// Original: arm9/ov004 @ 0x021633E4; symbol: func_ov004_021633e4; size: 0x24.
extern "C" void* Object_InitializeTransformStateAndVectors(unsigned int* p) { Object_InitializeTransformAndEmbeddedStateDefaults(p); Camera_InitializeManualControlState((int)p); Camera_InitializeTargetFollowingState((char*)p); return p; }

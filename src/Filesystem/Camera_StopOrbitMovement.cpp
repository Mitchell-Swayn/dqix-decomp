#include <globaldefs.h>
#include <Filesystem/CardReadManager.h>
#include <Filesystem/FileAccessor.h>
ARM
#pragma optimization_level 4
extern "C" void Camera_ResetInterpolationRecord(void*);
// Original callee argument/return behavior and named SDK declaration reviewed.
// Original: arm9/main @ 0x0202EEA4; symbol: func_0202eea4; size: 0x10.
extern "C" void Camera_StopOrbitMovement(char* a){Camera_ResetInterpolationRecord(a+444);}

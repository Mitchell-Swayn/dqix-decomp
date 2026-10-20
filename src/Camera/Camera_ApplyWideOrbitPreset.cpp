#include <globaldefs.h>
#pragma optimization_level 4
#pragma optimize_for_size off
extern "C" void Camera_SetOrbitParameters(int, int);
extern "C" void Camera_SetProjectionAngle(int, int);
// Original: arm9/main @ 0x020A2830; symbol: func_020a2830; size: 0x38.
extern "C" void Camera_ApplyWideOrbitPreset(int param_1) {
    *(unsigned int *)(param_1 + 0x224) = 0x8b33;
    *(unsigned int *)(param_1 + 0x228) = 0xe666;
    Camera_SetOrbitParameters(param_1, param_1 + 0x220);
    Camera_SetProjectionAngle(param_1, 0x19000);
}

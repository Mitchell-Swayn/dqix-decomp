#include <globaldefs.h>
ARM
extern "C" int Script_ReadParameterAsInteger(void *);
extern "C" void *SystemState_GetGlobalFlags();
extern "C" void *GameResources_GetInstance();
extern "C" void SystemState_ClearFlags(unsigned int *, unsigned int);
extern "C" void SystemState_SetFlags(unsigned int *, unsigned int);
extern "C" void ComputeGrottoAndContextDependentStateFlags(int);
// Original: arm9/ov001 @ 0x0215AEF0; symbol: func_ov001_0215aef0; size: 0x44.
extern "C" int UpdateGlobalStateFlagBit0FromParameter(void *parameter) {
    int enabled = Script_ReadParameterAsInteger(parameter);
    unsigned int *state = (unsigned int *)SystemState_GetGlobalFlags();
    GameResources_GetInstance();
    if (enabled != 0) {
        SystemState_ClearFlags(state, 1);
        ComputeGrottoAndContextDependentStateFlags(0);
    } else {
        SystemState_SetFlags(state, 1);
    }
    return 1;
}

#include <globaldefs.h>
ARM
extern "C" int ReadScriptParameterAsInteger(void *);
extern "C" void *GetGlobalStatePointer();
extern "C" void *GameResources_GetInstance();
extern "C" void RecordFlags_ClearWordMask(unsigned int *, unsigned int);
extern "C" void SetWordMaskBits_Main020466E4(unsigned int *, unsigned int);
extern "C" void ComputeGrottoAndContextDependentStateFlags(int);
// Original: arm9/ov001 @ 0x0215AEF0; symbol: func_ov001_0215aef0; size: 0x44.
extern "C" int func_ov001_0215aef0(void *parameter) {
    int enabled = ReadScriptParameterAsInteger(parameter);
    unsigned int *state = (unsigned int *)GetGlobalStatePointer();
    GameResources_GetInstance();
    if (enabled != 0) {
        RecordFlags_ClearWordMask(state, 1);
        ComputeGrottoAndContextDependentStateFlags(0);
    } else {
        SetWordMaskBits_Main020466E4(state, 1);
    }
    return 1;
}

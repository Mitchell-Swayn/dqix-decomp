#include <globaldefs.h>
ARM
extern "C" void *Zone3D_GetMainInstance(void);
extern "C" int Script_ReadParameterAsInteger(void *);
// Original: arm9/ov001 @ 0x02161F3C; symbol: func_ov001_02161f3c; size: 0x28.
extern "C" int Zone3D_ScriptSetUnknownTransitionOptionAt2750(void *parameter) {
    void *base = Zone3D_GetMainInstance();
    int value = Script_ReadParameterAsInteger(parameter);
    *(int *)((char *)base + 0x2750) = value;
    return 1;
}

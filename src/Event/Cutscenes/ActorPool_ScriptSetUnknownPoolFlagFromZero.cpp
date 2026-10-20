#include <globaldefs.h>
ARM
struct IntegerParameterView;
extern "C" void *ActorPool_GetGlobalInstance();
extern "C" int Script_ReadParameterAsInteger(IntegerParameterView* parameter);
// Original: arm9/ov001 @ 0x0216184C; symbol: func_ov001_0216184c; size: 0x34.
extern "C" int ActorPool_ScriptSetUnknownPoolFlagFromZero(IntegerParameterView* parameter) {
    char* object = (char*)ActorPool_GetGlobalInstance();
    if (Script_ReadParameterAsInteger(parameter) == 0)
        *(unsigned int*)(object + 0x98) |= 2;
    else
        *(unsigned int*)(object + 0x98) &= ~2;
    return 1;
}

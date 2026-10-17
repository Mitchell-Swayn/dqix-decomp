#include <globaldefs.h>
ARM
struct IntegerParameterView;
extern "C" void *Object_GetGlobalThirtyTwoEntryContainer();
extern "C" int ReadScriptParameterAsInteger(IntegerParameterView* parameter);
// Original: arm9/ov001 @ 0x0216184C; symbol: func_ov001_0216184c; size: 0x34.
extern "C" int Script_SetGlobalContainerFlag2(IntegerParameterView* parameter) {
    char* object = (char*)Object_GetGlobalThirtyTwoEntryContainer();
    if (ReadScriptParameterAsInteger(parameter) == 0)
        *(unsigned int*)(object + 0x98) |= 2;
    else
        *(unsigned int*)(object + 0x98) &= ~2;
    return 1;
}

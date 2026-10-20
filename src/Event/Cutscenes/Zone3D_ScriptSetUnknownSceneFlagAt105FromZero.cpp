#include <globaldefs.h>
ARM
struct IntegerParameterView;
extern "C" void* Zone3D_GetMainInstance();
extern "C" ARM int Script_ReadParameterAsInteger(IntegerParameterView* parameter);
// Original: arm9/ov001 @ 0x02161988; symbol: func_ov001_02161988; size: 0x34.
// Sets global byte 0x105 bit zero when the script integer parameter is zero.
extern "C" int Zone3D_ScriptSetUnknownSceneFlagAt105FromZero(IntegerParameterView* parameter) {
    unsigned char *state = (unsigned char *)Zone3D_GetMainInstance();
    if (Script_ReadParameterAsInteger(parameter) != 0) state[0x105] &= ~1;
    else state[0x105] |= 1;
    return 1;
}

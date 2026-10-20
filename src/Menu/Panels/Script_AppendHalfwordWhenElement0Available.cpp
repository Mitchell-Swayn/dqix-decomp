#include <globaldefs.h>
ARM
struct IntegerParameterView;
extern "C" unsigned int ScriptListContext_GetActiveInstance();
extern "C" void ScriptListContext_AppendResultId(short *p, short v);
extern "C" int Script_ReadParameterAsInteger(IntegerParameterView* parameter);
// Original: arm9/ov023 @ 0x021E915C; symbol: func_ov023_021e915c; size: 0x34.
extern "C" int Script_AppendHalfwordWhenElement0Available(IntegerParameterView* parameter) {
    unsigned int* list = (unsigned int*)ScriptListContext_GetActiveInstance();
    if (list != 0) {
        int value = Script_ReadParameterAsInteger(parameter);
        ScriptListContext_AppendResultId((short*)list, (short)value);
    }
    return 1;
}

#include <globaldefs.h>
ARM
extern "C" unsigned int ScriptListContext_GetActiveInstance();
extern "C" int Script_ReadParameterAsInteger(void *parameter);
extern "C" void ScriptListContext_AppendResultId(short *p, short v);
// Original: arm9/ov023 @ 0x021E9244; symbol: func_ov023_021e9244; size: 0x34.
extern "C" int Script_TryAppendHalfwordParameter(void *parameter) {
    short *entries = (short *)ScriptListContext_GetActiveInstance();
    if (entries != 0) {
        int value = Script_ReadParameterAsInteger(parameter);
        ScriptListContext_AppendResultId(entries, (short)value);
    }
    return 1;
}

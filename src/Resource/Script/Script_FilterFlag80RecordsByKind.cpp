#include <globaldefs.h>
#pragma optimize_for_size off
extern "C" int ScriptQueryContext_GetActiveInstance(void);
extern "C" int Script_ReadParameterAsInteger(int);
extern "C" void ScriptQueryContext_FilterByFlaggedPackedKind(int, int, int);
// Original: arm9/main @ 0x0209D510; symbol: func_0209d510; size: 0x44.
extern "C" int Script_FilterFlag80RecordsByKind(int param) {
    int object = ScriptQueryContext_GetActiveInstance();
    if (object == 0) {
        return 0;
    }
    int first = Script_ReadParameterAsInteger(param);
    int second = Script_ReadParameterAsInteger(param + 8);
    ScriptQueryContext_FilterByFlaggedPackedKind(object, first, second);
    return 1;
}

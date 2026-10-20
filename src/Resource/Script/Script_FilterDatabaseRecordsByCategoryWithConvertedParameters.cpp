#include <globaldefs.h>
#pragma optimization_level 4
#pragma optimize_for_size off
extern "C" int ScriptQueryContext_GetActiveInstance(void);
extern "C" int Script_ReadParameterAsInteger(int);
extern "C" void ScriptQueryContext_FilterByCategory(int, int, int);
// Original: arm9/main @ 0x0209D408; symbol: func_0209d408; size: 0x44.
extern "C" int Script_FilterDatabaseRecordsByCategoryWithConvertedParameters(int param_1) {
    int found = ScriptQueryContext_GetActiveInstance();
    if (found == 0) return 0;
    int first = Script_ReadParameterAsInteger(param_1);
    int second = Script_ReadParameterAsInteger(param_1 + 8);
    ScriptQueryContext_FilterByCategory(found, first, second);
    return 1;
}

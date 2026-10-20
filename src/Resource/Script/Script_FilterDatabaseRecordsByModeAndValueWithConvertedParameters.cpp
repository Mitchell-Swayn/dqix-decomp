#include <globaldefs.h>

extern "C" int ScriptQueryContext_GetActiveInstance();
extern "C" int Script_ReadParameterAsInteger(int value);
extern "C" void ScriptQueryContext_FilterByAlternateCategoryConditions(int object, int first, int second);

// Original: arm9/main @ 0x0209D054; symbol: func_0209d054; size: 0x44.
extern "C" int Script_FilterDatabaseRecordsByModeAndValueWithConvertedParameters(int parameter)
{
    int object = ScriptQueryContext_GetActiveInstance();
    if (object == 0) {
        return 0;
    }
    int first = Script_ReadParameterAsInteger(parameter);
    int second = Script_ReadParameterAsInteger(parameter + 8);
    ScriptQueryContext_FilterByAlternateCategoryConditions(object, first, second);
    return 1;
}

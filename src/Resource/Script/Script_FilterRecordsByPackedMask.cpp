#include <globaldefs.h>
#pragma optimization_level 4
extern "C" int ScriptQueryContext_GetActiveInstance();
extern "C" unsigned int Script_ReadParameterAsInteger(int);
extern "C" void ScriptQueryContext_FilterByClassificationMask(int, unsigned int, unsigned int);
// Original: arm9/main @ 0x0209D098; symbol: func_0209d098; size: 0x44.
extern "C" int Script_FilterRecordsByPackedMask(int argument) {
    int object = ScriptQueryContext_GetActiveInstance();
    if (object == 0) return 0;
    unsigned int value = Script_ReadParameterAsInteger(argument);
    unsigned int value2 = Script_ReadParameterAsInteger(argument + 8);
    ScriptQueryContext_FilterByClassificationMask(object, value, value2);
    return 1;
}

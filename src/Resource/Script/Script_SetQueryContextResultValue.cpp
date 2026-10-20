#include <globaldefs.h>
#pragma optimization_level 4
extern "C" int ScriptQueryContext_GetActiveInstance();
extern "C" unsigned int Script_ReadParameterAsInteger(int);
extern "C" void ScriptQueryContext_SetResultValue(int, unsigned int);
// Original: arm9/main @ 0x0209DB28; symbol: func_0209db28; size: 0x34.
extern "C" int Script_SetQueryContextResultValue(int argument) {
    int object = ScriptQueryContext_GetActiveInstance();
    if (object == 0) return 0;
    unsigned int value = Script_ReadParameterAsInteger(argument);
    ScriptQueryContext_SetResultValue(object, value);
    return 1;
}

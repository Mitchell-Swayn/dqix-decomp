#include <globaldefs.h>

extern "C" int ScriptQueryContext_GetActiveInstance(void);
extern "C" int Script_ReadParameterAsInteger(void*);
extern "C" int Script_ReadParameterAsFloat(void*);
extern "C" void ScriptQueryContext_FilterByFloatValueThreshold(int, int, int, int);

// Original: arm9/main @ 0x0209D554; symbol: func_0209d554; size: 0x54.
extern "C" int Script_InvokeStateWithMixedResolvedTriple(void* object, int, int, int arg3)
{
    int target = ScriptQueryContext_GetActiveInstance();
    if (target == 0) return 0;
    int value0 = Script_ReadParameterAsInteger(object);
    int value1 = Script_ReadParameterAsFloat((char*)object + 8);
    int value2 = Script_ReadParameterAsInteger((char*)object + 16);
    ScriptQueryContext_FilterByFloatValueThreshold(target, value0, value1, value2);
    return 1;
}

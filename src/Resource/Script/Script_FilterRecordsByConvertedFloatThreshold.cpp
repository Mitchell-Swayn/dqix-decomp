#include <globaldefs.h>
extern "C" int ScriptQueryContext_GetActiveInstance();
extern "C" int Script_ReadParameterAsInteger(void* state);
extern "C" void Script_ReadParameterAsFloat(void* state);
extern "C" int _ffix();
extern "C" void ScriptQueryContext_FilterByCategoryExcludingReservedKinds(int state, int value, int fixed);
// Original: arm9/main @ 0x0209D5DC; symbol: func_0209d5dc; size: 0x48.
extern "C" int Script_FilterRecordsByConvertedFloatThreshold(void* state)
{
    int result = ScriptQueryContext_GetActiveInstance();
    if (result == 0) return 0;
    int value = Script_ReadParameterAsInteger(state);
    Script_ReadParameterAsFloat(static_cast<unsigned char*>(state) + 8);
    int fixed = _ffix();
    ScriptQueryContext_FilterByCategoryExcludingReservedKinds(result, value, fixed);
    return 1;
}

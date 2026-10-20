#include <globaldefs.h>
ARM
extern "C" void* ScriptQueryContext_GetActiveInstance();extern "C" int Script_ReadParameterAsInteger(void*);extern "C" void ScriptQueryContext_FilterByClearClassificationFlags(void*,int);
// Original: arm9/main @ 0x0209D710; symbol: func_0209d710; size: 0x34.
extern "C" int Script_FilterSixtyFourByteRecordsWithFlags36ClearWithConvertedParameters(void* p){void* e=ScriptQueryContext_GetActiveInstance();if(!e)return 0;int value=Script_ReadParameterAsInteger(p);ScriptQueryContext_FilterByClearClassificationFlags(e,value);return 1;}

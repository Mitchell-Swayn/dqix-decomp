#include <globaldefs.h>
ARM
extern "C" void* ScriptQueryContext_GetActiveInstance();extern "C" unsigned Script_ReadParameterAsInteger(void*);extern "C" void ScriptQueryContext_FilterByPrimaryAttributeConditions(void*,unsigned,unsigned);
// Original: arm9/main @ 0x0209CF00; symbol: func_0209cf00; size: 0x44.
extern "C" int Script_FilterRecordsByPredicateModeZero(unsigned char* param){void* object=ScriptQueryContext_GetActiveInstance();if(!object)return 0;unsigned a=Script_ReadParameterAsInteger(param);unsigned b=Script_ReadParameterAsInteger(param+8);ScriptQueryContext_FilterByPrimaryAttributeConditions(object,a,b);return 1;}

#include <globaldefs.h>
ARM
extern "C" unsigned ScriptQueryContext_GetActiveInstance(); extern "C" unsigned Script_ReadParameterAsInteger(char*); extern "C" void ScriptQueryContext_FilterByPrimaryCategoryConditions(unsigned,unsigned,unsigned);
// Original: arm9/main @ 0x0209CF44; symbol: func_0209cf44; size: 0x44.
 extern "C" int Script_FilterSixtyFourByteRecordsByValuePredicateWithConvertedParameters(char* p){unsigned state=ScriptQueryContext_GetActiveInstance();if(!state)return 0;unsigned a=Script_ReadParameterAsInteger(p);unsigned b=Script_ReadParameterAsInteger(p+8);ScriptQueryContext_FilterByPrimaryCategoryConditions(state,a,b);return 1;}

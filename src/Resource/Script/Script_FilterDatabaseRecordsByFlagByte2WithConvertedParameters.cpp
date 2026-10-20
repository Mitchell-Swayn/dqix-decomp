#include <globaldefs.h>
extern "C" void* ScriptQueryContext_GetActiveInstance();extern "C" int Script_ReadParameterAsInteger(void*);extern "C" void ScriptQueryContext_FilterByThirdFlagWordMask(void*,int,int);
// Original: arm9/main @ 0x0209CF88; symbol: func_0209cf88; size: 0x44.
extern "C" ARM int Script_FilterDatabaseRecordsByFlagByte2WithConvertedParameters(char* p){void* state=ScriptQueryContext_GetActiveInstance();if(!state)return 0;int first=Script_ReadParameterAsInteger(p);int second=Script_ReadParameterAsInteger(p+8);ScriptQueryContext_FilterByThirdFlagWordMask(state,first,second);return 1;}

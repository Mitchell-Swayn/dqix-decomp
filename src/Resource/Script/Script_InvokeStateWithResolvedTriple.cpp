#include <globaldefs.h>
extern "C" void* ScriptQueryContext_GetActiveInstance();extern "C" int Script_ReadParameterAsInteger(void*);extern "C" void FilterSixtyFourByteRecordsByMinimumGroupSize(void*,int,int,int);
// Original: arm9/main @ 0x0209D6BC; symbol: func_0209d6bc; size: 0x54.
extern "C" ARM int Script_InvokeStateWithResolvedTriple(char* p){void* owner=ScriptQueryContext_GetActiveInstance();if(!owner)return 0;int a=Script_ReadParameterAsInteger(p);int b=Script_ReadParameterAsInteger(p+8);int c=Script_ReadParameterAsInteger(p+16);FilterSixtyFourByteRecordsByMinimumGroupSize(owner,a,b,c);return 1;}

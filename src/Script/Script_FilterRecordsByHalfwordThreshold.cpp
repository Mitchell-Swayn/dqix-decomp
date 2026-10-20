#include <globaldefs.h>
ARM
extern "C" void* ScriptQueryContext_GetActiveInstance();extern "C" int Script_ReadParameterAsInteger(void*);extern "C" void ScriptQueryContext_FilterByUnsignedValueThreshold(void*,int,int,int);
// Original: arm9/main @ 0x0209D150; symbol: func_0209d150; size: 0x54.
extern "C" int Script_FilterRecordsByHalfwordThreshold(char* p){void* e=ScriptQueryContext_GetActiveInstance();if(!e)return 0;int a=Script_ReadParameterAsInteger(p);int b=Script_ReadParameterAsInteger(p+8);int c=Script_ReadParameterAsInteger(p+16);ScriptQueryContext_FilterByUnsignedValueThreshold(e,a,b,c);return 1;}

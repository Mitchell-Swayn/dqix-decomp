#include <globaldefs.h>
#include <Resource/Script.h>
extern "C" void* ScriptQueryContext_GetActiveInstance();extern "C" int Script_ReadParameterAsInteger(Script::Parameter*);extern "C" void ScriptQueryContext_FilterByIndexedSignedValue(void*,int,int,int);
#pragma optimization_level 4
// Original: arm9/main @ 0x0209D0DC; symbol: func_0209d0dc; size: 0x74.
extern "C" ARM int Script_InvokeStateForParameterPairs(Script::Parameter* p,int count){void* target=ScriptQueryContext_GetActiveInstance();if(!target)return 0;int first=Script_ReadParameterAsInteger(p);++p;for(int i=1;i<count;i+=2){int a=Script_ReadParameterAsInteger(p);Script::Parameter* next=p+1;p+=2;int b=Script_ReadParameterAsInteger(next);ScriptQueryContext_FilterByIndexedSignedValue(target,first,a,b);}return 1;}

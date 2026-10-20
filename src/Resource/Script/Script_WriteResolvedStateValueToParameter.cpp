#include <globaldefs.h>
extern "C" void* ScriptQueryContext_GetActiveInstance();extern "C" int Script_ReadParameterAsInteger(void*);extern "C" void Script_WriteIntegerReferenceOutput(void*,int);extern "C" int ScriptQueryContext_GetIndexedSourceCounter(void*,int);
// Original: arm9/main @ 0x0209DA08; symbol: func_0209da08; size: 0x40.
extern "C" ARM int Script_WriteResolvedStateValueToParameter(char* p){void* state=ScriptQueryContext_GetActiveInstance();if(!state)return 0;int id=Script_ReadParameterAsInteger(p);int value=ScriptQueryContext_GetIndexedSourceCounter(state,id);Script_WriteIntegerReferenceOutput(p+8,value);return 1;}

#include <globaldefs.h>
extern "C" void* ScriptQueryContext_GetActiveInstance();extern "C" int Script_ReadParameterAsInteger(void*);extern "C" void Script_WriteIntegerReferenceOutput(void*,int);extern "C" int ScriptQueryContext_GetSourceOrFilteredEntryCount(void*,int);
// Original: arm9/main @ 0x0209D38C; symbol: func_0209d38c; size: 0x40.
extern "C" ARM int Script_WriteSourceOrFilteredEntryCount(char* p){void* state=ScriptQueryContext_GetActiveInstance();if(!state)return 0;int id=Script_ReadParameterAsInteger(p);int value=ScriptQueryContext_GetSourceOrFilteredEntryCount(state,id);Script_WriteIntegerReferenceOutput(p+8,value);return 1;}

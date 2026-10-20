#include <globaldefs.h>
extern "C" void* ScriptQueryContext_GetActiveInstance(void*); extern "C" unsigned Script_ReadParameterAsInteger(void*); extern "C" void ScriptQueryContext_SetRequestResultTriple(void*,unsigned,unsigned,unsigned);
// Original: arm9/main @ 0x0209DAA4; symbol: func_0209daa4; size: 0x54.
extern "C" int Script_SetGlobalRecordWords84And88And6C(char* input) { void* state=ScriptQueryContext_GetActiveInstance(input); if(!state)return 0; unsigned a=Script_ReadParameterAsInteger(input); unsigned b=Script_ReadParameterAsInteger(input+8); unsigned c=Script_ReadParameterAsInteger(input+16); ScriptQueryContext_SetRequestResultTriple(state,a,b,c); return 1; }

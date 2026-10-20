#include <globaldefs.h>
ARM
extern "C" void* Quest_GetGlobalOrderState();extern "C" int ScriptQueryContext_GetActiveInstance(void*);extern "C" int Script_ReadParameterAsInteger(void*);extern "C" char* Quest_FindActiveEntryById(void*,int);
// Original: arm9/main @ 0x0209D83C; symbol: func_0209d83c; size: 0x6C.
extern "C" int Script_WriteClampedResolvedHalfword0A(char* args){void* list=Quest_GetGlobalOrderState();if(!list)return 0;if(!ScriptQueryContext_GetActiveInstance(list))return 0;char* entry=Quest_FindActiveEntryById(list,Script_ReadParameterAsInteger(args));if(!entry)return 0;int value=Script_ReadParameterAsInteger(args+8);if(value>65535)value=65535;*(unsigned short*)(entry+10)=value;return 1;}

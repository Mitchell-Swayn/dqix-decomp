#include <globaldefs.h>
ARM
extern "C" void* Object_GetGlobalRequestQueue();extern "C" int ReadWordAtOffset0(void*);extern "C" int ReadScriptParameterAsInteger(void*);extern "C" char* Object_FindBoundedIdEntryThrough204(void*,int);
// Original: arm9/main @ 0x0209D83C; symbol: func_0209d83c; size: 0x6C.
extern "C" int Script_WriteClampedResolvedHalfword0A(char* args){void* list=Object_GetGlobalRequestQueue();if(!list)return 0;if(!ReadWordAtOffset0(list))return 0;char* entry=Object_FindBoundedIdEntryThrough204(list,ReadScriptParameterAsInteger(args));if(!entry)return 0;int value=ReadScriptParameterAsInteger(args+8);if(value>65535)value=65535;*(unsigned short*)(entry+10)=value;return 1;}

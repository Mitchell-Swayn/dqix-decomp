#include <globaldefs.h>
extern "C" void* Object_GetGlobalRequestQueue();
extern "C" unsigned ReadScriptParameterAsInteger(unsigned);
extern "C" unsigned* Object_FindBoundedIdEntryThrough204(void*,unsigned);
// Original: arm9/main @ 0x0209D260; symbol: func_0209d260; size: 0x48.
extern "C" bool Script_SetResolvedRecordFlag4000(unsigned value) {void* p=Object_GetGlobalRequestQueue();if(!p)return false;unsigned* result=Object_FindBoundedIdEntryThrough204(p,ReadScriptParameterAsInteger(value));if(!result)return false;*result|=0x4000;return true;}

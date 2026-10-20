#include <globaldefs.h>
extern "C" void* ScriptQueryContext_GetActiveInstance(unsigned);extern "C" unsigned Script_ReadParameterAsInteger(unsigned);extern "C" void ScriptQueryContext_FilterByActiveMarker(void*,unsigned);
// Original: arm9/main @ 0x0209D624; symbol: func_0209d624; size: 0x34.
extern "C" ARM int Script_InvokeStateWithResolvedValue(unsigned value){void* p=ScriptQueryContext_GetActiveInstance(value);if(!p)return 0;ScriptQueryContext_FilterByActiveMarker(p,Script_ReadParameterAsInteger(value));return 1;}

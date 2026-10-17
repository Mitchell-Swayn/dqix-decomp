#include <globaldefs.h>
extern "C" void* ReadWordAtOffset0(unsigned);extern "C" unsigned ReadScriptParameterAsInteger(unsigned);extern "C" void CopyOrCompactActiveDatabaseRecords(void*,unsigned);
// Original: arm9/main @ 0x0209D624; symbol: func_0209d624; size: 0x34.
extern "C" ARM int Script_InvokeStateWithResolvedValue(unsigned value){void* p=ReadWordAtOffset0(value);if(!p)return 0;CopyOrCompactActiveDatabaseRecords(p,ReadScriptParameterAsInteger(value));return 1;}

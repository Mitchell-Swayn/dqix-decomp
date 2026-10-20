#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void* memset(void*,int,unsigned);
// Original: arm9/main @ 0x02099FF0; symbol: func_02099ff0; size: 0x14.
extern "C" void* ScriptRecordTable_ResetView(void* p){return memset(p,0,12);}

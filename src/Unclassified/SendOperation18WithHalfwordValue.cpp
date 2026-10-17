#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" unsigned PowerManagement_ExecuteCommandSynchronously(unsigned,unsigned,unsigned);
// Original: arm9/main @ 0x020CEDFC; symbol: func_020cedfc; size: 0x1C.
extern "C" unsigned SendOperation18WithHalfwordValue(unsigned value){return PowerManagement_ExecuteCommandSynchronously(18,(unsigned short)value,0);}

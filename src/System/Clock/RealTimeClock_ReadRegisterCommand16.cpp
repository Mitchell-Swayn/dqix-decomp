#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" bool SendPackedArm7CommandFive(unsigned);
// Original: arm9/main @ 0x020CF87C; symbol: func_020cf87c; size: 0x10.
extern "C" bool RealTimeClock_ReadRegisterCommand16(){return SendPackedArm7CommandFive(16);}

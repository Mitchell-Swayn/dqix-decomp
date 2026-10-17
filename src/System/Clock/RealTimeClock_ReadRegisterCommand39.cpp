#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" bool SendPackedArm7CommandFive(unsigned);
// Original: arm9/main @ 0x020CF8AC; symbol: func_020cf8ac; size: 0x10.
extern "C" bool RealTimeClock_ReadRegisterCommand39(){return SendPackedArm7CommandFive(39);}

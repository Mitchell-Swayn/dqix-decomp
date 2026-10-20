#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" unsigned char WaitForStateThreeThenProcessOwnerWithTimeout(unsigned char*);
// Original: arm9/main @ 0x0202AFF4; symbol: func_0202aff4; size: 0xC.
extern "C" unsigned char Network_StopSessionAndResetConnectionManager(unsigned char* object){return WaitForStateThreeThenProcessOwnerWithTimeout(object);}

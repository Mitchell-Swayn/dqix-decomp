#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" {
    bool System_SendPackedArm7CommandFive(int);
// Original: arm9/main @ 0x020CF88C; symbol: func_020cf88c; size: 0x10.
    bool RealTimeClock_SendReadDateRequest(){
        return System_SendPackedArm7CommandFive(17);
    }
}

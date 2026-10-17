#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" {
    bool SendPackedArm7CommandFive(int);
// Original: arm9/main @ 0x020CF88C; symbol: func_020cf88c; size: 0x10.
    bool InvokeOperationCode17(){
        return SendPackedArm7CommandFive(17);
    }
}

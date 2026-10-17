#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" {
    void DispatchCommandSixWithFourValues(int,int,int,int);
// Original: arm9/main @ 0x020D1E70; symbol: func_020d1e70; size: 0x18.
    void SoundCommand_SubmitOpcodeSixWithModeTwo(int a,int b){
        DispatchCommandSixWithFourValues(a,6,b,2);
    }
}

#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" {
    void SoundCommand_SubmitOpcodeTwentyThree(int);
// Original: arm9/main @ 0x020BBDCC; symbol: func_020bbdcc; size: 0xC.
    void Sound_SetMasterVolumeForPowerTransition(int value){
        SoundCommand_SubmitOpcodeTwentyThree(value);
    }
}

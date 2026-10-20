#include <globaldefs.h>
ARM
extern "C" void SoundCommand_EnqueueOpcodeAndFourArguments(int,unsigned,unsigned,unsigned,unsigned);
// Original: arm9/main @ 0x020D1FB0; symbol: func_020d1fb0; size: 0x20.
extern "C" void SoundCommand_SubmitOpcodeTwentySix(unsigned a,unsigned b) {
    SoundCommand_EnqueueOpcodeAndFourArguments(26,a,b,0,0);
}

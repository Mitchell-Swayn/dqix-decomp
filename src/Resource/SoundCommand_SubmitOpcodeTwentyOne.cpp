#include <globaldefs.h>
ARM
extern "C" void SoundCommand_EnqueueOpcodeAndFourArguments(int,unsigned,unsigned,unsigned,unsigned);
// Original: arm9/main @ 0x020D2018; symbol: func_020d2018; size: 0x20.
extern "C" void SoundCommand_SubmitOpcodeTwentyOne(unsigned a,unsigned b) {
    SoundCommand_EnqueueOpcodeAndFourArguments(21,a,b,0,0);
}

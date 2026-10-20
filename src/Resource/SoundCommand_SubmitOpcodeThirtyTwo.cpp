#include <globaldefs.h>
ARM
extern "C" void SoundCommand_EnqueueOpcodeAndFourArguments(int,unsigned,unsigned,unsigned,unsigned);
// Original: arm9/main @ 0x020D20C4; symbol: func_020d20c4; size: 0x20.
extern "C" void SoundCommand_SubmitOpcodeThirtyTwo(unsigned a,unsigned b) {
    SoundCommand_EnqueueOpcodeAndFourArguments(32,a,b,0,0);
}

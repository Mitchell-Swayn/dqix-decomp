#include <globaldefs.h>
ARM
extern "C" void SoundCommand_EnqueueOpcodeAndFourArguments(int,unsigned,unsigned,unsigned,unsigned);
// Original: arm9/main @ 0x020D20A4; symbol: func_020d20a4; size: 0x20.
extern "C" void SoundCommand_SubmitOpcodeThirtyOne(unsigned a,unsigned b) {
    SoundCommand_EnqueueOpcodeAndFourArguments(31,a,b,0,0);
}

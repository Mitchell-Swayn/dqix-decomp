#include <globaldefs.h>
ARM
extern "C" void SoundCommand_EnqueueOpcodeAndFourArguments(int,unsigned,unsigned,unsigned,unsigned);
// Original: arm9/main @ 0x020D1E30; symbol: func_020d1e30; size: 0x20.
extern "C" void SoundCommand_SubmitOpcodeThree(unsigned a) {
    SoundCommand_EnqueueOpcodeAndFourArguments(3,a,0,0,0);
}

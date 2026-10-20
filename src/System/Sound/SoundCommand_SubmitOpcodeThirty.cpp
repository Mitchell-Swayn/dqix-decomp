#include <globaldefs.h>
ARM
extern "C" void SoundCommand_EnqueueOpcodeAndFourArguments(int,unsigned,unsigned,unsigned,unsigned);
// Original: arm9/main @ 0x020D2084; symbol: func_020d2084; size: 0x20.
extern "C" void SoundCommand_SubmitOpcodeThirty(unsigned a,unsigned b) {
    SoundCommand_EnqueueOpcodeAndFourArguments(30,a,b,0,0);
}

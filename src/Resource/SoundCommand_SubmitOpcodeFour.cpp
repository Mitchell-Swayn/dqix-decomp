#include <globaldefs.h>
ARM
extern "C" void SoundCommand_EnqueueOpcodeAndFourArguments(int,unsigned,unsigned,unsigned,unsigned);
// Original: arm9/main @ 0x020D1E50; symbol: func_020d1e50; size: 0x20.
extern "C" void SoundCommand_SubmitOpcodeFour(unsigned a,unsigned b) {
    SoundCommand_EnqueueOpcodeAndFourArguments(4,a,b,0,0);
}

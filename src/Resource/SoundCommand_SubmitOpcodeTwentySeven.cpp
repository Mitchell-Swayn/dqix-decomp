#include <globaldefs.h>
ARM
extern "C" void SoundCommand_EnqueueOpcodeAndFourArguments(int,unsigned,unsigned,unsigned,unsigned);
// Original: arm9/main @ 0x020D1FD0; symbol: func_020d1fd0; size: 0x20.
extern "C" void SoundCommand_SubmitOpcodeTwentySeven(unsigned a,unsigned b) {
    SoundCommand_EnqueueOpcodeAndFourArguments(27,a,b,0,0);
}

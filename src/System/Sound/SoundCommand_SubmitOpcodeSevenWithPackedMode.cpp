#include <globaldefs.h>
extern "C" void SoundCommand_EnqueueOpcodeAndFourArguments(unsigned,unsigned,unsigned,unsigned,unsigned);
// Original: arm9/main @ 0x020D2154; symbol: func_020d2154; size: 0x28.
extern "C" ARM void SoundCommand_SubmitOpcodeSevenWithPackedMode(unsigned a,unsigned b,unsigned c,unsigned d,unsigned mode){SoundCommand_EnqueueOpcodeAndFourArguments(7,a|(mode<<24),b,c,d);}

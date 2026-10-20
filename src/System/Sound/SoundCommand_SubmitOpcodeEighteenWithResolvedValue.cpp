#include <globaldefs.h>
ARM
extern "C" unsigned SoundCommand_RegisterCompletionCallback(unsigned,unsigned,unsigned); extern "C" void SoundCommand_EnqueueOpcodeAndFourArguments(unsigned,unsigned,unsigned,unsigned,unsigned);
// Original: arm9/main @ 0x020D1F70; symbol: func_020d1f70; size: 0x40.
 extern "C" void SoundCommand_SubmitOpcodeEighteenWithResolvedValue(unsigned a,unsigned b,unsigned c,unsigned d,unsigned e){unsigned v=SoundCommand_RegisterCompletionCallback(a,d,e);SoundCommand_EnqueueOpcodeAndFourArguments(18,a,b,c,v);}

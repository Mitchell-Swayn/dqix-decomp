#include <globaldefs.h>
ARM
#pragma optimize_for_size off
extern "C" void SoundCommand_SubmitOpcodeTwentyOne(unsigned,unsigned);
// Original: arm9/main @ 0x020BCC4C; symbol: func_020bcc4c; size: 0x30.
extern "C" void NNS_SndStrmSetChannelPan(char* p,int index,unsigned value){if(index>*(int*)(p+72)-1)return;SoundCommand_SubmitOpcodeTwentyOne(1u<<((unsigned char*)(p+index))[76],value);}

#include <globaldefs.h>
struct State {char pad[0x2e];unsigned char value;char pad2[13];unsigned char channel;};extern "C" void SoundCommand_SubmitOpcodeFour(unsigned);
// Original: arm9/main @ 0x020BC594; symbol: func_020bc594; size: 0x28.
extern "C" void NNSi_SndPlayerPause(State* self,unsigned value) {if(self && value!=self->value){SoundCommand_SubmitOpcodeFour(self->channel);self->value=value;}}

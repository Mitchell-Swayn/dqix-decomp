#include <globaldefs.h>
ARM
extern "C" void SoundCommand_SubmitOpcodeSixWithModeFour(unsigned char,int a);
struct Record {char pad[60];unsigned char id;};
// Original: arm9/main @ 0x020BC1AC; symbol: func_020bc1ac; size: 0x20.
extern "C" void NNS_SndPlayerSetChannelPriority(Record* volatile* p,int a) {
    if(!*p)return;
    SoundCommand_SubmitOpcodeSixWithModeFour((*p)->id,a);
}

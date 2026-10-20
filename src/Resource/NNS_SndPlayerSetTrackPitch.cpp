#include <globaldefs.h>
ARM
extern "C" void SoundCommand_SubmitOpcodeSevenWithSubcommandTwelve(unsigned char,int a,int b);
struct Record {char pad[60];unsigned char id;};
// Original: arm9/main @ 0x020BC1CC; symbol: func_020bc1cc; size: 0x20.
extern "C" void NNS_SndPlayerSetTrackPitch(Record* volatile* p,int a,int b) {
    if(!*p)return;
    SoundCommand_SubmitOpcodeSevenWithSubcommandTwelve((*p)->id,a,b);
}

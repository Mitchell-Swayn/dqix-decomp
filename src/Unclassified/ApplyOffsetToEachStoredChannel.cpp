#include <globaldefs.h>
ARM
struct Entry{unsigned pad;volatile int offset;};extern "C" int data_0210fcf4[];extern "C" int SoundVolume_EncodeClampedDecibelAttenuation(int);extern "C" void SoundCommand_SubmitOpcodeTwenty(unsigned,unsigned,int);struct Sound {char pad[0x3c];int offset;char pad40[8];int count;unsigned char channels[1];};
// Original: arm9/main @ 0x020BCBE0; symbol: func_020bcbe0; size: 0x6C.
extern "C" void ApplyOffsetToEachStoredChannel(Sound* p,int offset){p->offset=offset;unsigned channel;int i=0;if(p->count>0){do{channel=p->channels[i];int value=SoundVolume_EncodeClampedDecibelAttenuation(p->offset+((int*)((char*)data_0210fcf4+channel*8))[1]);SoundCommand_SubmitOpcodeTwenty(1u<<channel,(unsigned)value&255,value>>8);++i;}while(i<p->count);}}

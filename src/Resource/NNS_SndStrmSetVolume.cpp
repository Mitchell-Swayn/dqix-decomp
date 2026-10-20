#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x210fcf4; symbol: data_0210fcf4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 128 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct Entry{unsigned pad;volatile int offset;};extern "C" int NNSSndStrmSetup_UnknownRoleZeroInitializedStorage_Variant2[];extern "C" int SoundVolume_EncodeClampedDecibelAttenuation(int);extern "C" void SoundCommand_SubmitOpcodeTwenty(unsigned,unsigned,int);struct Sound {char pad[0x3c];int offset;char pad40[8];int count;unsigned char channels[1];};
// Original: arm9/main @ 0x020BCBE0; symbol: func_020bcbe0; size: 0x6C.
extern "C" void NNS_SndStrmSetVolume(Sound* p,int offset){p->offset=offset;unsigned channel;int i=0;if(p->count>0){do{channel=p->channels[i];int value=SoundVolume_EncodeClampedDecibelAttenuation(p->offset+((int*)((char*)NNSSndStrmSetup_UnknownRoleZeroInitializedStorage_Variant2+channel*8))[1]);SoundCommand_SubmitOpcodeTwenty(1u<<channel,(unsigned)value&255,value>>8);++i;}while(i<p->count);}}

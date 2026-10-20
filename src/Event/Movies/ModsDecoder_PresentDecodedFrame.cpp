#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void* Memory_AllocateSafe(unsigned);
extern "C" void* ModsDecoder_GetSampleClampTable();
extern "C" void func_ov016_0219c514_unk(void*);
extern "C" void ModsVideo_ConvertPlanarFrameToRgb555(void*);
struct State { unsigned f[50]; };
// Original: arm9/ov016 @ 0x0218F16C; symbol: func_ov016_0218f16c; size: 0x184.
// Selects or converts a ring-buffer pair and queues it with a destination and length.
extern "C" unsigned ModsDecoder_PresentDecodedFrame(State* s,unsigned destination,unsigned count,unsigned mode) {
 if(s->f[39]>=s->f[40])return 0;
 if(mode) {
 if(!s->f[26]) {s->f[26]=(unsigned)Memory_AllocateSafe(s->f[5]<<8);if(!s->f[26])return 0;}
 if(!s->f[27]) {s->f[27]=(unsigned)Memory_AllocateSafe((s->f[5]>>1)<<8);if(!s->f[27])return 0;}
 unsigned args[9];
 args[0]=((unsigned*)s->f[23])[s->f[49]];
 args[1]=((unsigned*)s->f[24])[s->f[49]];
 args[2]=s->f[26];args[3]=s->f[27];args[4]=s->f[4];args[5]=s->f[5];
 args[6]=((unsigned*)s->f[25])[s->f[49]];
 args[7]=(unsigned)ModsDecoder_GetSampleClampTable();if(mode==2)args[8]=0;else args[8]=1;
 func_ov016_0219c514_unk(args);
 s->f[15]=s->f[26];s->f[16]=s->f[27];
 }else {s->f[15]=((unsigned*)s->f[23])[s->f[49]];s->f[16]=((unsigned*)s->f[24])[s->f[49]];}
 s->f[17]=destination;s->f[18]=count<<1;
 ModsVideo_ConvertPlanarFrameToRgb555(s->f+15);
 ++s->f[39];if(++s->f[49]==s->f[42])s->f[49]=0;
 return 1;
}

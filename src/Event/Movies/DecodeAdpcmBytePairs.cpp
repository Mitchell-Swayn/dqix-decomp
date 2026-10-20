#include <globaldefs.h>
ARM
#pragma optimize_for_size off
#pragma always_inline on
// Original data: arm9/ov016 @ 0x219cef0; symbol: data_ov016_0219cef0.
// IMA ADPCM step sizes indexed 0..88; final halfword is original alignment padding.
// Initial values: hex 0700080009000a000b000c000d000e001000110013001500170019001c001f002200250029002d00320037003c00420049005000580061006b00760082008f00 ...; full span in module reference.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov016.md.
extern "C" const short DecodeAdpcmBytePairs_IMAADPCMStepSizesIndexed088[];
// Original data: arm9/ov016 @ 0x219cee0; symbol: data_ov016_0219cee0.
// IMA ADPCM index adjustment for 3-bit magnitude, repeated for sign bit.
// Initial values: hex ffffffff02040608ffffffff02040608.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov016.md.
extern "C" const signed char DecodeAdpcmBytePairs_IMAADPCMIndexAdjustmentFor3BitMagnitudeRepeatedForSignBit[];
struct State { int sample,index; };
inline void Decode(State* s,int code) {
 int step=DecodeAdpcmBytePairs_IMAADPCMStepSizesIndexed088[s->index];
 s->index+=DecodeAdpcmBytePairs_IMAADPCMIndexAdjustmentFor3BitMagnitudeRepeatedForSignBit[code&7];
 if(s->index<0)s->index=0;
 if(s->index>88)s->index=88;
 int diff=step>>3;
 if(code&4)diff+=step;
 if(code&2)diff+=step>>1;
 if(code&1)diff+=step>>2;
 if(code&8)s->sample-=diff;else s->sample+=diff;
 if(s->sample < -32768)s->sample=-32768;
 if(s->sample > 32767)s->sample=32767;
}
// Original: arm9/ov016 @ 0x0218FEB4; symbol: func_ov016_0218feb4; size: 0x158.
// Decodes low then high IMA ADPCM nibbles and packs two clamped PCM samples per word.
extern "C" void DecodeAdpcmBytePairs(State* s,unsigned char* input,int count,unsigned* output) {
 int i=0;
 if(i<count) do {
  int code=input[i];
  Decode(s,code);
  int first=s->sample;
  code>>=4;
  Decode(s,code);
  *output++=(unsigned short)first | ((unsigned)s->sample<<16);
 ++i;
 }while(i<count);
}

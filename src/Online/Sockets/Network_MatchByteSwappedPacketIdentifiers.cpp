#include <globaldefs.h>
ARM
#pragma always_inline on
inline unsigned short SwapHalfword(int value) { return (value>>8)|(value<<8); }
// Original: arm9/ov031 @ 0x02201D58; symbol: func_ov031_02201d58; size: 0xB4.
extern "C" int Network_MatchByteSwappedPacketIdentifiers(unsigned char* header,unsigned char* keys,unsigned char* packet) {
 int result=0;
 int allowed=0;
 int second=0,first=0;
 if(packet[8]!=10 && packet[8]!=11) allowed=1;
 if(allowed) {
  if(*(unsigned short*)(packet+10)==SwapHalfword(*(unsigned short*)(keys+2))) first=1;
 }
 if(first) {
  if(*(unsigned short*)(packet+24)==SwapHalfword(*(unsigned short*)keys)) second=1;
 }
 if(second) {
  int low=*(unsigned short*)(header+14);
  int high=*(unsigned short*)(header+12);
  unsigned value=((unsigned)SwapHalfword(high)<<16)|SwapHalfword(low);
  if(*(unsigned*)(packet+28)==value) result=1;
 }
 return result;
}

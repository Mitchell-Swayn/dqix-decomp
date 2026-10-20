#include <globaldefs.h>
ARM
// Original: arm9/ov031 @ 0x02201E70; symbol: func_ov031_02201e70; size: 0x84.
extern "C" void Network_ParseTcpMaximumSegmentSize(unsigned char* packet,unsigned char* connection) {
 *(unsigned short*)(connection+0x2e)=536;
 unsigned char* p=packet+20;
 int remaining=(packet[12]&0xf0)/4-20;
 while(remaining--) {
  int kind=*p++;
  if(kind==0) return;
  if(kind==1) continue;
  if(kind==2) {
   *(unsigned short*)(connection+0x2e)=(p[1]<<8)|p[2];
   p+=3;
   remaining-=3;
  } else {
   int skip=*p-1;
   remaining-=skip;
   p+=skip;
  }
 }
}

#include <globaldefs.h>
THUMB
ARM
struct Rate { unsigned short mask; unsigned char value,pad; };
extern "C" { extern Rate data_ov031_0224b0e4[]; void MIi_CpuCopy16(const void*,volatile void*,int); }
THUMB
// Original: arm9/ov031 @ 0x0221E6E8; symbol: func_ov031_0221e6e8; size: 0x8C.
extern "C" void Network_ExpandWirelessScanRecord(unsigned char* source,unsigned char* destination) {
 *(unsigned*)destination=*(unsigned short*)(source+10);
 MIi_CpuCopy16(source+12,destination+4,32);
 *(unsigned*)(destination+0x24)=*(unsigned short*)(source+0x36);
 MIi_CpuCopy16(source+4,destination+0x30,6);
 int i;
 int count=0;
 Rate* rate=data_ov031_0224b0e4;
 for(i=0;i<12;++i,++rate) {
  if(*(unsigned short*)(source+0x30)&rate->mask) {
   (destination+count)[0x3c]=rate->value;
   if(*(unsigned short*)(source+0x2e)&rate->mask) (destination+count)[0x3c]|=0x80;
   ++count;
  }
 }
 *(int*)(destination+0x38)=count;
 *(unsigned*)(destination+0x4c)=*(unsigned short*)(source+0x32);
 int mode=*(unsigned short*)(source+0x2c)&3;
 if(mode==1) *(int*)(destination+0x50)=1;
 else if(mode==2) *(int*)(destination+0x50)=2;
 else *(int*)(destination+0x50)=0;
}

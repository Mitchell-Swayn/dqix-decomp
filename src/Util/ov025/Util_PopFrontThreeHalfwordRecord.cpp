#include <globaldefs.h>
ARM
extern "C" void CopyThreeHalfwordValues(unsigned short* d,const unsigned short* s);
struct Record { unsigned short words[3]; };
// Original: arm9/ov025 @ 0x021DEDA0; symbol: func_ov025_021deda0; size: 0x80.
extern "C" int Util_PopFrontThreeHalfwordRecord(unsigned char* p,unsigned short* out) {
 if (*(unsigned short*)(p+0x770a)) {
  CopyThreeHalfwordValues(out,(unsigned short*)(p+0x76ec));
  --*(unsigned short*)(p+0x770a);
  for(int i=0;i<*(unsigned short*)(p+0x770a);++i)
   CopyThreeHalfwordValues((unsigned short*)(&((Record*)(p+0x76ec))[i]),(unsigned short*)(&((Record*)(p+0x76ec))[i+1]));
  return 1;
 }
 return 0;
}

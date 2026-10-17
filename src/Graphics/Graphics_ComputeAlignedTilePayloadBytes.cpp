#include <globaldefs.h>
#include <std_library_functions.h>
ARM
#pragma always_inline on
static inline unsigned tileLength(unsigned width,unsigned height,int format) { unsigned length=(8<<width)*(8<<height); if(format==3)length>>=1; return length; }
// Original: arm9/main @ 0x02076738; symbol: func_02076738; size: 0x1F0.
extern "C" int Graphics_ComputeAlignedTilePayloadBytes(unsigned char* self,char* data) {
 int mode;
 if(self[0x5e]==0)mode=*(volatile unsigned*)0x04000000&0x300010;
 else mode=*(volatile unsigned*)0x04001000&0x300010;
 unsigned mask; int alignment;
 switch(mode) {case 0:return 0;case 0x10:alignment=5;break;case 0x100010:alignment=6;break;case 0x200010:alignment=7;break;case 0x300010:alignment=8;break;default:return 0;}
 unsigned short count=0;int format=0;
 unsigned short itemA,itemB,coordinateA,coordinateB,width,height;
 unsigned entries;
 memcpy(&count,data,2);memcpy(&format,data+2,2);int total=0; unsigned short item=0; data+=4;
 for(;item<count;++item) {
 memcpy(&itemA,data,2);memcpy(&itemB,data+2,2);memcpy(&entries,data+4,4);data+=8;
 mask=(1<<alignment)-1;
 for(unsigned index=0;index<entries;++index) {
 memcpy(&coordinateA,data,2);memcpy(&coordinateB,data+2,2);memcpy(&width,data+4,2);memcpy(&height,data+6,2);
 data+=8;
 unsigned length=tileLength(width,height,format);
 data+=length;total+=(length+mask)&~mask;
 }
 }
 return total;
}

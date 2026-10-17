#include <globaldefs.h>
ARM
struct Record;struct Owner;
extern "C" Record* FindReadyRecordByIdBeforeStopIndex(Owner*,unsigned);
extern "C" int data_02114e54[];
// Original: arm9/ov023 @ 0x021E63BC; symbol: func_ov023_021e63bc; size: 0x8C.
extern "C" int Util_ClassifyCoordinateInRecordRegions(unsigned char* p){
 unsigned char* r=(unsigned char*)FindReadyRecordByIdBeforeStopIndex((Owner*)(p+0xac),p[0x1371]);
 short a=*(short*)(r+0xac);short b=*(short*)(r+0xae);
 a*=8;b*=8;
 int x=a+10;int y=b+16;
 int cx=data_02114e54[14];int cy=data_02114e54[15];
 if(x<=cx && cx<=x+16 && y<=cy && cy<=y+8)return 1;
 if(x<=cx && cx<=x+16 && y+12<=cy && cy<=y+20)return -1;
 return 0;
}

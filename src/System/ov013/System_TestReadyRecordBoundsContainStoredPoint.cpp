#include <globaldefs.h>
ARM
struct Owner; struct Record;
extern "C" unsigned char data_02114e54[];
extern "C" int TestStoredPointInsideRectangle(char*,int,int,int,int);
extern "C" void ReadFourBoundedHalfwordArrays(unsigned char*,int,short*,short*,short*,short*);
extern "C" Record* FindReadyRecordByIdBeforeStopIndex(Owner*,unsigned);
// Original: arm9/ov013 @ 0x021842A0; symbol: func_ov013_021842a0; size: 0x98.
extern "C" int System_TestReadyRecordBoundsContainStoredPoint(Owner* owner,int index) {
 if(data_02114e54[0x5c]) {
  unsigned char* record=(unsigned char*)FindReadyRecordByIdBeforeStopIndex(owner,0);
  if(record) {
   short x=*(short*)(record+0xac),y=*(short*)(record+0xae);
   short a,b,c,d;
   ReadFourBoundedHalfwordArrays(record,(short)index,&a,&b,&c,&d);
   return TestStoredPointInsideRectangle((char*)data_02114e54,a+(short)(x*8),b+(short)(y*8),c,d);
  }
 }
 return 0;
}

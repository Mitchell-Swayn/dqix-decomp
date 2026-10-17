#include <globaldefs.h>
ARM
extern "C" void Object_SetUnsignedShortAtOffsetCEAndSetUnsignedCharAtOffsetC9To1(int self,unsigned short value);
extern "C" bool TestNonnegativeIdentifierWithByteOverride(char* p);
extern "C" char data_02109bf4[];
// Original: arm9/ov005 @ 0x0215CB4C; symbol: func_ov005_0215cb4c; size: 0x88.
extern "C" int Object_PollIdentifierRequest61(unsigned char* p) {
if(!(*(unsigned int*)(p+0x3dcc)&0x10000))return 0;
unsigned char state=p[0x3df3];
if(state==0){Object_SetUnsignedShortAtOffsetCEAndSetUnsignedCharAtOffsetC9To1((int)data_02109bf4,0x3d);++p[0x3df3];}
if(state==1){
if(TestNonnegativeIdentifierWithByteOverride(data_02109bf4))return 1;
*(unsigned int*)(p+0x3dcc)&=~0x10000;
p[0x3df3]=0;
return 0;
}
return 1;
}

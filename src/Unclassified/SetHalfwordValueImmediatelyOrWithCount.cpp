#include <globaldefs.h>
ARM
extern "C" void Object_ClearThreeHalfwordsAtOffset212(void*);
// Original: arm9/main @ 0x0202E95C; symbol: func_0202e95c; size: 0x30.
extern "C" void SetHalfwordValueImmediatelyOrWithCount(unsigned char* p,short value,int count) { if(count) { *(short*)(p+0x214)=value;*(short*)(p+0x216)=count;return; } Object_ClearThreeHalfwordsAtOffset212(p);*(short*)(p+0x212)=value; }

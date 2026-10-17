#include <globaldefs.h>
ARM
struct Flags{unsigned low:20;unsigned value:7;unsigned high:5;};
// Original: arm9/main @ 0x02085038; symbol: func_02085038; size: 0x40.
extern "C" unsigned Object_SumElevenPositiveEntryPackedFlags(unsigned char* p){unsigned total=0;for(int i=0;i<11;){unsigned char* q=p+i*32;short count=*(short*)(q+0x1ac);++i;if(count>0){unsigned char* obj=*(unsigned char**)(q+0x194);total+=((Flags*)(obj+4))->value;}}return total;}

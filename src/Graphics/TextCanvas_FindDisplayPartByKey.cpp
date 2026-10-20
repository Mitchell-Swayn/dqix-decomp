#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x02081DA8; symbol: func_02081da8; size: 0x38.
extern "C" unsigned char* TextCanvas_FindDisplayPartByKey(unsigned char* p,unsigned int value) { unsigned char count=p[0x39];unsigned char* entry=*(unsigned char**)(p+0x30);unsigned char i=0;while(i<count) { if(value==entry[0xc4])return entry;unsigned int next=i+1;entry+=0xe0;i=(unsigned char)next; }return 0; }

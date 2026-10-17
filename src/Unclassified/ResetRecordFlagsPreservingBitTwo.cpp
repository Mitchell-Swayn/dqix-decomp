#include <globaldefs.h>
ARM
#include <std_library_functions.h>
// Original: arm9/main @ 0x02088E80; symbol: func_02088e80; size: 0xE8.
extern "C" void ResetRecordFlagsPreservingBitTwo(unsigned char* p){bool keep=false;if(*(unsigned int*)(p+0x14)&4)keep=true;*(unsigned int*)(p+0x14)=1;*(int*)(p+0x18)=0;p[0x21]=0;*(unsigned short*)(p+0x22)&=~3;*(unsigned short*)(p+0x22)&=~0x3c;*(unsigned short*)(p+0x22)&=~0x1c0;*(unsigned short*)(p+0x22)&=~0xe00;*(unsigned short*)(p+0x22)&=~0x3000;p[0x24]=0;*(unsigned short*)(p+0x22)&=~0x4000;p[0x3b]&=~8;p[0x3b]&=~0xf0;p[0x3b]&=~4;*(short*)(p+0x32)=-1;*(short*)(p+0x34)=-1;if(keep)*(unsigned int*)(p+0x14)|=4;memset(p+0x58,0,4);memset(p+0x5c,0,0x23);memset(p+0x7f,0,0x23);}

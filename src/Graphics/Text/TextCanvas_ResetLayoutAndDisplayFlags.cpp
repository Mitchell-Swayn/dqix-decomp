#include <globaldefs.h>
ARM
#pragma optimization_level 4
#pragma optimize_for_size off
extern "C" void* memset(void*,int,unsigned);struct Flags {unsigned char a:1,b:1,c:1,rest:5;};
// Original: arm9/main @ 0x0204C804; symbol: func_0204c804; size: 0x78.
extern "C" void TextCanvas_ResetLayoutAndDisplayFlags(char* p) { *(int*)(p+0x9c)=0;*(short*)(p+0xac)=0;*(short*)(p+0xae)=0;*(short*)(p+0xa8)=0;*(short*)(p+0xaa)=0;*(short*)(p+0xb0)=4;*(short*)(p+0xb2)=4;*(short*)(p+0xb8)=0;*(short*)(p+0xba)=0;*(short*)(p+0xc0)=0;unsigned char* b=(unsigned char*)p;b[0xc5]&=~8;Flags* flags=(Flags*)(p+0xd8);flags->a=0;flags->b=0;flags->c=0;b[0xc4]=255;b[0xc5]=0;memset(p+0xdb,0,4); }

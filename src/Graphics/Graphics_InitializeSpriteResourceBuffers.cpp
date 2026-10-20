#include <globaldefs.h>
ARM
extern "C" void* memset(void*,int,unsigned int);
// Original: arm9/main @ 0x0205A444; symbol: func_0205a444; size: 0x50.
extern "C" void Graphics_InitializeSpriteResourceBuffers(unsigned char* p) { memset(p,0,36);memset(p+36,0,20);*(unsigned int*)(p+56)=0;*(unsigned int*)(p+64)=0;*(unsigned int*)(p+68)=0;*(unsigned int*)(p+72)=0;*(short*)(p+76)=0;*(short*)(p+78)=0;*(unsigned int*)(p+60)=0;p[80]=1; }

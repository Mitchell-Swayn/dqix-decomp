#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x0203FC84; symbol: func_0203fc84; size: 0x1C.
extern "C" void ActorSprite_SetAlpha(unsigned char* p,int value) { if (value>31) value=31; else if (value<0) value=0; *(short*)(p+0x2c)=value; }

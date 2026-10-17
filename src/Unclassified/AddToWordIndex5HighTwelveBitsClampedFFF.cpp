#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x020A01B8; symbol: func_020a01b8; size: 0x34.
extern "C" void AddToWordIndex5HighTwelveBitsClampedFFF(volatile unsigned* p,unsigned n){unsigned v=n+(p[5]>>20);if(v>4095)v=4095;p[5]=(p[5]&0xfffff)|(v<<20);}

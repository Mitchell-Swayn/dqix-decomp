#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x020A03F8; symbol: func_020a03f8; size: 0x3C.
extern "C" void Object_AddPackedNineBitCounterClampedTo9999(volatile unsigned* p,unsigned n){unsigned v=((p[4]<<9)>>18)+n;if(v>9999)v=9999;p[4]=(p[4]&0xff8001ff)|((v<<18)>>9);}

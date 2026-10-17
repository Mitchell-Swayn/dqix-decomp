#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x020A0434; symbol: func_020a0434; size: 0x2C.
extern "C" void AddToWordIndex4HighBitsClamped500(volatile unsigned* p,unsigned n){unsigned v=n+(p[4]>>23);if(v>500)v=500;p[4]=(p[4]&0x7fffff)|(v<<23);}

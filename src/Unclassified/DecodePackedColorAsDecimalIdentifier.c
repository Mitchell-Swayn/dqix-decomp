#include <globaldefs.h>
// Original: arm9/main @ 0x0204BEA0; symbol: func_0204bea0; size: 0x3C.
ARM int DecodePackedColorAsDecimalIdentifier(unsigned short* color){unsigned short value=*color;return (short)(value&31)*100+20000+(unsigned short)((value&0x3e0)>>5)*10+(unsigned short)((value&0x7c00)>>10);}

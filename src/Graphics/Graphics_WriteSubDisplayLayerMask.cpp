#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x020DAF20; symbol: func_020daf20; size: 0x1C.
extern "C" void Graphics_WriteSubDisplayLayerMask(unsigned value){volatile unsigned* p=(volatile unsigned*)0x04001000;*p=(*p&~0x1f00U)|(value<<8);}

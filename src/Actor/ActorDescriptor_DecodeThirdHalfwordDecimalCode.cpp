#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x0204BE3C; symbol: func_0204be3c; size: 0x3C.
extern "C" unsigned short ActorDescriptor_DecodeThirdHalfwordDecimalCode(unsigned short* p){unsigned bits=p[2];unsigned ten=(unsigned short)((bits&0x3e0)>>5);unsigned hundred=bits&31;unsigned one=(unsigned short)((bits&0x7c00)>>10);return hundred*100+ten*10+one;}

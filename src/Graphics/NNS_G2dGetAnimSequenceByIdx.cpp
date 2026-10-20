#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x020B005C; symbol: func_020b005c; size: 0x18.
extern "C" unsigned char* NNS_G2dGetAnimSequenceByIdx(unsigned char* p,unsigned int i) { if (*(unsigned short*)p > i) return *(unsigned char**)(p+4)+i*16; return 0; }

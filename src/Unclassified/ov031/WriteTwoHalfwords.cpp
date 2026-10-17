#include <globaldefs.h>
// Original: arm9/ov031 @ 0x0223CB10; symbol: func_ov031_0223cb10; size: 0xC.
extern "C" ARM void WriteTwoHalfwords(unsigned short a, unsigned short b, void* output) { ((unsigned short*)output)[0]=a; ((unsigned short*)output)[1]=b; }

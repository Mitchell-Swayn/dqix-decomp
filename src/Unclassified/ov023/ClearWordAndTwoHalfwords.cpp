#include <globaldefs.h>
// Original: arm9/ov023 @ 0x021dad78; symbol: func_ov023_021dad78; size: 0x14.
extern "C" void ClearWordAndTwoHalfwords(unsigned int* p) { p[0]=0; *(unsigned short*)((char*)p+4)=0; *(unsigned short*)((char*)p+6)=0; }

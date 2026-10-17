#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x02027D94; symbol: func_02027d94; size: 0x1C.
extern "C" void ClearFourLeadingBytesAndWordAtOffsetC(unsigned char* p) { p[0]=0;p[1]=0;p[2]=0;*(unsigned int*)(p+0xc)=0;p[3]=0; }

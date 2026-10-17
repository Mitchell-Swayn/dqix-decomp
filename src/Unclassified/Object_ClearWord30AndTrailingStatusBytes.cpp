#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x0205BF3C; symbol: func_0205bf3c; size: 0x1C.
extern "C" void Object_ClearWord30AndTrailingStatusBytes(unsigned char* p) { *(unsigned int*)(p+0x30)=0;*(unsigned short*)(p+0x34)=0;p[0x36]=0;p[0x37]=0;p[0x38]=0; }

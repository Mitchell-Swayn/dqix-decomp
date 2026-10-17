#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x0205C6E4; symbol: func_0205c6e4; size: 0x2C.
extern "C" unsigned int ReadFlagSelectedValueField(unsigned char* p) { unsigned int value=0; if (p[0x94] && p[0x50]) value=*(unsigned int*)(p+8); if (p[0x95]) value=*(unsigned int*)(p+0x58);return value; }

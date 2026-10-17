#include <globaldefs.h>
// Original: arm9/ov017 @ 0x021BBBF8; symbol: func_ov017_021bbbf8; size: 0xC.
extern "C" ARM void Field_WriteNestedHalfword(void* object,unsigned short value) { *(unsigned short*)((unsigned char*)object+0x11c)=value; }

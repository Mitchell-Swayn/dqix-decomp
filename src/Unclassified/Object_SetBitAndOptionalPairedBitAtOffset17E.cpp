#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x02079710; symbol: func_02079710; size: 0x2C.
extern "C" void Object_SetBitAndOptionalPairedBitAtOffset17E(unsigned char* p,unsigned int bit,int paired) { p[0x17e]|=1U<<bit; if (paired) p[0x17e]|=1U<<(bit+4); }

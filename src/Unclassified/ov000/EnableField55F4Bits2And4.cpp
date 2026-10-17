#include <globaldefs.h>
ARM
extern "C" void EnableField55F4Bits(unsigned char* p, unsigned int bits);
// Original: arm9/ov000 @ 0x02166E3C; symbol: func_ov000_02166e3c; size: 0x20.
extern "C" void EnableField55F4Bits2And4(unsigned char* p) { EnableField55F4Bits(p, 2); EnableField55F4Bits(p, 4); }

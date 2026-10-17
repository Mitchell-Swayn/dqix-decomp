#include <globaldefs.h>

// Original: arm9/ov017 @ 0x021BD3A4; symbol: func_ov017_021bd3a4; size: 0x30.
extern "C" ARM int TestPrimaryOrPairedByteFlags(unsigned char* self) { if(self[3] || (self[2] && self[0x9a])) return 1; return 0; }

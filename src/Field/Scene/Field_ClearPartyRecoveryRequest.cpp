#include <globaldefs.h>
// Clears two bytes, one halfword, and two trailing bytes.
// Original: arm9/ov017 @ 0x0218d7fc; symbol: func_ov017_0218d7fc; size: 0x1c.
extern "C" void Field_ClearPartyRecoveryRequest(unsigned char* p) { p[0] = 0; p[1] = 0; *(unsigned short*)(p + 2) = 0; p[4] = 0; p[5] = 0; }

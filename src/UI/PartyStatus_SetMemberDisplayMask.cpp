#include <globaldefs.h>

// Original: arm9/main @ 0x020263B0; symbol: func_020263b0; size: 0x18.
extern "C" ARM void PartyStatus_SetMemberDisplayMask (unsigned char* p, unsigned int n) { if (n < 4) p[0x75d] |= 1 << n; }

#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x020A35E0; symbol: func_020a35e0; size: 0x18.
extern "C" unsigned int PartySelection_GetMemberMask(unsigned char* p,unsigned int bit) { if (bit>=4) return 0; return p[0x34] & (1U<<bit); }

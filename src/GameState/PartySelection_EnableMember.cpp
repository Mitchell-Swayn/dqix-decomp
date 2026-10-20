#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x020A35CC; symbol: func_020a35cc; size: 0x14.
extern "C" void PartySelection_EnableMember(unsigned char* p,unsigned int bit) { p[0x34] |= 1U << bit; }

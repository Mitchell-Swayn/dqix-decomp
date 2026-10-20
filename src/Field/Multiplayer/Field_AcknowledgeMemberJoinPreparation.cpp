#include <globaldefs.h>
ARM
// Original: arm9/ov017 @ 0x021AFAFC; symbol: func_ov017_021afafc; size: 0x14.
extern "C" void Field_AcknowledgeMemberJoinPreparation(unsigned char *p, unsigned int bit) { p[0x20] |= 1u << bit; }

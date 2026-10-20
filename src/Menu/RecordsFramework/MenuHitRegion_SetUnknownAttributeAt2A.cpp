#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021FD45C; symbol: Unclassified_SetHalfwordAtOffset2A; size: 0x8.
// Stores the low halfword at byte offset 0x2A.
extern "C" void MenuHitRegion_SetUnknownAttributeAt2A(void *self, unsigned int value) { *(unsigned short *)((unsigned char *)self + 0x2a) = value; }

#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021FD464; symbol: Unclassified_ReadHalfwordAtOffset2A; size: 0x8.
// Returns the unsigned halfword at byte offset 0x2A.
extern "C" unsigned int MenuHitRegion_GetUnknownAttributeAt2A(void *self) { return *(unsigned short *)((unsigned char *)self + 0x2a); }

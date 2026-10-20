#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021FB8D4; symbol: ReadHalfwordAtOffsetA4; size: 0x8.
// Accesses the halfword at object offset 0xA4; field meaning is not established.
extern "C" unsigned short MenuSprite_GetUnknownParameterAtA4(void *object) { return *(unsigned short *)((unsigned char *)object + 0xa4); }

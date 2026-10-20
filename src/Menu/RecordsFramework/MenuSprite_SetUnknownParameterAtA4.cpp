#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021FB8CC; symbol: WriteHalfwordAtOffsetA4; size: 0x8.
// Accesses the halfword at object offset 0xA4; field meaning is not established.
extern "C" void MenuSprite_SetUnknownParameterAtA4(void *object, unsigned short value) { *(unsigned short *)((unsigned char *)object + 0xa4) = value; }

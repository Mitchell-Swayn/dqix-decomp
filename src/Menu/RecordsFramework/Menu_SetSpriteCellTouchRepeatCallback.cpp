#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021FB24C; symbol: WriteHalfwordAtOffset42; size: 0x8.
// Accesses the halfword at object offset 0x42; field meaning is not established.
extern "C" void Menu_SetSpriteCellTouchRepeatCallback(void *object, unsigned short value) { *(unsigned short *)((unsigned char *)object + 0x42) = value; }

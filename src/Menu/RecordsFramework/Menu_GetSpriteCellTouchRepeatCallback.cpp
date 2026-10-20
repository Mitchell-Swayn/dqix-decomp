#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021FB254; symbol: ReadHalfwordAtOffset42; size: 0x8.
// Accesses the halfword at object offset 0x42; field meaning is not established.
extern "C" unsigned short Menu_GetSpriteCellTouchRepeatCallback(void *object) { return *(unsigned short *)((unsigned char *)object + 0x42); }

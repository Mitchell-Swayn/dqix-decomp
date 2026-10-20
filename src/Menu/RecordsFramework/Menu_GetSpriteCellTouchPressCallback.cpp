#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021FB234; symbol: ReadHalfwordAtOffset3C; size: 0x8.
// Accesses the halfword at object offset 0x3C; field meaning is not established.
extern "C" unsigned short Menu_GetSpriteCellTouchPressCallback(void *object) { return *(unsigned short *)((unsigned char *)object + 0x3c); }

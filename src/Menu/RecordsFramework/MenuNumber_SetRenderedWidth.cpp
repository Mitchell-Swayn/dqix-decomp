#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021FBCB0; symbol: Object_WriteHalfwordAtOffset36; size: 0x8.
// Stores a halfword at object offset 0x36; field meaning is unknown.
extern "C" void MenuNumber_SetRenderedWidth(void* self, unsigned short value) { *(unsigned short*)((unsigned char*)self + 0x36) = value; }

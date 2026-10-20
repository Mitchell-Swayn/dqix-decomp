#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021FBCB8; symbol: Object_WriteHalfwordAtOffset38; size: 0x8.
// Stores a halfword at object offset 0x38; field meaning is unknown.
extern "C" void MenuNumber_SetRenderedHeight(void* self, unsigned short value) { *(unsigned short*)((unsigned char*)self + 0x38) = value; }

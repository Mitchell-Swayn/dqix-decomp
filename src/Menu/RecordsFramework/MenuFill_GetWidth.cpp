#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021FC4FC; symbol: Object_ReadHalfwordAtOffset2A; size: 0x8.
// Reads the halfword at object offset 0x2a; field meaning is unknown.
extern "C" unsigned short MenuFill_GetWidth(void* self) { return *(unsigned short*)((unsigned char*)self + 0x2a); }

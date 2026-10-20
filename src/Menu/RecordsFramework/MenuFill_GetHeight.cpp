#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021FC504; symbol: Object_ReadHalfwordAtOffset2C; size: 0x8.
// Reads the halfword at object offset 0x2c; field meaning is unknown.
extern "C" unsigned short MenuFill_GetHeight(void* self) { return *(unsigned short*)((unsigned char*)self + 0x2c); }

#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021FC50C; symbol: Object_WriteByteAtOffset2E; size: 0x8.
// Stores the supplied byte at object offset 0x2e; field meaning is unknown.
extern "C" void MenuFill_SetUnknownRenderParameterAt2E(void* self, unsigned char value) { *((unsigned char*)self + 0x2e) = value; }

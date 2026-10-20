#include <globaldefs.h>
ARM
// Original: arm9/ov003 @ 0x021685C4; symbol: Object_ReadWordAtOffsetE0; size: 0x8.
// Reads the 32-bit word at object offset 0xe0. The field meaning is not established.
extern "C" unsigned int Bank_GetSavedMainDisplayLayers(void* self) { return *(unsigned int*)((unsigned char*)self + 0xe0); }

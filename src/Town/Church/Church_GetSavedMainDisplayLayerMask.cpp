#include <globaldefs.h>
ARM
// Original: arm9/ov003 @ 0x0215916C; symbol: Object_ReadWordAtOffset94; size: 0x8.
// Reads the 32-bit word at object offset 0x94. The field meaning is not established.
extern "C" unsigned int Church_GetSavedMainDisplayLayerMask(void* self) { return *(unsigned int*)((unsigned char*)self + 0x94); }

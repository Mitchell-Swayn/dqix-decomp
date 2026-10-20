#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021FC1E4; symbol: Object_ReadWordAtOffset1C_021fc1e4; size: 0x8.
// Reads the word at object offset 0x1c. The object role is unresolved; the address suffix temporarily distinguishes equivalent offset-1c accessors.
extern "C" unsigned int MenuZone_GetLoadPhase(void* self) { return *(unsigned int*)((unsigned char*)self + 0x1c); }

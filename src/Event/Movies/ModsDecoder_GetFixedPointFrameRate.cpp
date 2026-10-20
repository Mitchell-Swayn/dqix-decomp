#include <globaldefs.h>
ARM
// Original: arm9/ov016 @ 0x0218EF1C; symbol: Object_ReadWordAtOffset18; size: 0x8.
// Reads the 32-bit word at object offset 0x18. The field meaning is not established.
extern "C" unsigned int ModsDecoder_GetFixedPointFrameRate(void* self) { return *(unsigned int*)((unsigned char*)self + 0x18); }

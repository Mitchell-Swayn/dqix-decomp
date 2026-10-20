#include <globaldefs.h>
ARM
// Original: arm9/ov016 @ 0x0218EF24; symbol: Object_ReadWordAtOffsetC_Ov016; size: 0x8.
// Reads the 32-bit word at object offset 0x0c. The object type remains unclear; module suffix temporarily disambiguates an equivalent getter in ov003.
extern "C" unsigned int ModsDecoder_GetFrameCount(void* self) { return *(unsigned int*)((unsigned char*)self + 0x0c); }

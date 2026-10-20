#include <globaldefs.h>
ARM
// Original: arm9/ov016 @ 0x0218EF14; symbol: Object_ReadWordAtOffset20; size: 0x8.
// Reads the 32-bit word at object offset 0x20. The field meaning is not established.
extern "C" unsigned int ModsDecoder_GetAudioSampleRate(void* self) { return *(unsigned int*)((unsigned char*)self + 0x20); }

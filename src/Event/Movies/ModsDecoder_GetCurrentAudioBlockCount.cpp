#include <globaldefs.h>
ARM
// Original: arm9/ov016 @ 0x0218F330; symbol: func_ov016_0218f330; size: 0x10.
extern "C" unsigned int ModsDecoder_GetCurrentAudioBlockCount(void* p) { unsigned int i = *(unsigned int*)((char*)p + 0x90); return *(unsigned int*)((char*)p + 0x88 + i * 4); }

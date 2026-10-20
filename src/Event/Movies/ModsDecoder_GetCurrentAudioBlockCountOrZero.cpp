#include <globaldefs.h>
ARM
extern "C" unsigned ModsDecoder_GetCurrentAudioBlockCount(void *p);
// Original: arm9/ov016 @ 0x0218E750; symbol: func_ov016_0218e750; size: 0x18.
extern "C" unsigned ModsDecoder_GetCurrentAudioBlockCountOrZero(void *p) {
    if (p == 0)
        return 0;
    return ModsDecoder_GetCurrentAudioBlockCount(p);
}

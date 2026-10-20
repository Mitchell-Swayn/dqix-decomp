#include <globaldefs.h>
ARM
extern "C" int ModsDecoder_GetAudioSampleRate(void *object);
// Original: arm9/ov016 @ 0x0218E660; symbol: func_ov016_0218e660; size: 0x18.
extern "C" int ModsDecoder_GetAudioSampleRateOrZero(void *object) {
    if (!object)
        return 0;
    return ModsDecoder_GetAudioSampleRate(object);
}

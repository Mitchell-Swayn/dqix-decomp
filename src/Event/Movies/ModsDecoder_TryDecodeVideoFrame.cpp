#include <globaldefs.h>
ARM
extern "C" int ModsDecoder_DecodeVideoFrame(unsigned int);
// Original: arm9/ov016 @ 0x0218E6E4; symbol: CheckCallbackResultEqualsOneWhenPresent; size: 0x24.
// Returns whether a nonnull context's callback result equals exactly one.
extern "C" int ModsDecoder_TryDecodeVideoFrame(unsigned int value) {
    if (value == 0) return 0;
    return ModsDecoder_DecodeVideoFrame(value) == 1;
}

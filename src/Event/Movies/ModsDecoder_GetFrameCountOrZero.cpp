#include <globaldefs.h>
ARM
extern "C" int ModsDecoder_GetFrameCount(unsigned int);
// Original: arm9/ov016 @ 0x0218E690; symbol: Overlay_ReadObjectField0COrZero; size: 0x18.
// Returns zero for a null object; otherwise returns its word at offset +0x0C.
extern "C" int ModsDecoder_GetFrameCountOrZero(unsigned int value) {
    if (value == 0) return 0;
    return ModsDecoder_GetFrameCount(value);
}

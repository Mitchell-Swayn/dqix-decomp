#include <globaldefs.h>
ARM
// Original: arm9/ov031 @ 0x0223FF7C; symbol: func_ov031_0223ff7c; size: 0x34.
extern "C" char MapThreePunctuationCodesToAlphanumericBytes(int value) {
    unsigned int c = (value + 1) & 0xff;
    if (c == 0x7b) c = 0x30;
    else if (c == 0x5b) c = 0x61;
    else if (c == 0x3a) c = 0x41;
    return (char)c;
}

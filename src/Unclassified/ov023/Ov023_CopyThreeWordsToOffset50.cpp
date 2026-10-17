#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021E60C4; symbol: func_ov023_021e60c4; size: 0x1C.
extern "C" void Ov023_CopyThreeWordsToOffset50(void *destination, const void *source) {
    *(unsigned int *)((char *)destination + 0x50) = *(const unsigned int *)source;
    *(unsigned int *)((char *)destination + 0x54) = *(const unsigned int *)((const char *)source + 4);
    *(unsigned int *)((char *)destination + 0x58) = *(const unsigned int *)((const char *)source + 8);
}

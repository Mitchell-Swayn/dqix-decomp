#include <globaldefs.h>
ARM
extern "C" unsigned int String_CountBytesUntilTerminator(const signed char *str);
// Original: arm9/ov031 @ 0x022415A8; symbol: func_ov031_022415a8; size: 0xC.
extern "C" unsigned int Ov031_CountBytesUntilTerminator(const signed char *str) {
    return String_CountBytesUntilTerminator(str);
}

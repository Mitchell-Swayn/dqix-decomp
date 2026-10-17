#include <globaldefs.h>
ARM
extern "C" void Ov023_CopyThreeWordsToOffset50(void *, unsigned);
// Original: arm9/ov023 @ 0x021E6088; symbol: func_ov023_021e6088; size: 0x3C.
extern "C" void func_ov023_021e6088(void *obj, unsigned value) {
    Ov023_CopyThreeWordsToOffset50(obj, value);
    Ov023_CopyThreeWordsToOffset50((char *)obj + 0x408, value);
    Ov023_CopyThreeWordsToOffset50((char *)obj + 0xac, value);
    Ov023_CopyThreeWordsToOffset50((char *)obj + 0x35c, value);
}

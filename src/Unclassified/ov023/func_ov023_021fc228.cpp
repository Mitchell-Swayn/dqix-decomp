#include <globaldefs.h>
ARM
extern "C" void ForwardInitializeTwoWordsAndTwoHalfwords(void *object);
// Original: arm9/ov023 @ 0x021FC228; symbol: func_ov023_021fc228; size: 0x10.
extern "C" void func_ov023_021fc228(void *object) {
    ForwardInitializeTwoWordsAndTwoHalfwords((char *)object + 0x20);
}

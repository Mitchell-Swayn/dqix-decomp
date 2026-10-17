#include <globaldefs.h>
ARM
extern "C" void InitializeFourWordsWithInvalidIndex(signed char *p);
extern "C" unsigned int data_ov017_021d83ac;
// Original: arm9/ov017 @ 0x021A5568; symbol: func_ov017_021a5568; size: 0x3C.
extern "C" void func_ov017_021a5568(signed char *p) {
    InitializeFourWordsWithInvalidIndex(p);
    p[0] = 12;
    *(unsigned int *)(p + 8) = 0;
    data_ov017_021d83ac = 0;
    p[0x20] = 0;
    p[0x21] = 0;
    *(short *)(p + 0x22) = -1;
}

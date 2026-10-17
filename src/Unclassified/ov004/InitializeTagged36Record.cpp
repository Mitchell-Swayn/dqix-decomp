#include <globaldefs.h>
ARM
extern "C" void InitializeFourWordsWithInvalidIndex(signed char *p);
// Original: arm9/ov004 @ 0x0216FA08; symbol: func_ov004_0216fa08; size: 0x34.
// Initializes a sixteen-byte record with tag 0x36 and an invalid halfword index at 0xC.
extern "C" void InitializeTagged36Record(signed char *p) {
    InitializeFourWordsWithInvalidIndex(p);
    p[0] = 0x36;
    *(short *)(p + 8) = 0;
    p[10] = 0;
    *(short *)(p + 12) = -1;
    p[14] = 0;
    p[15] = 0;
}

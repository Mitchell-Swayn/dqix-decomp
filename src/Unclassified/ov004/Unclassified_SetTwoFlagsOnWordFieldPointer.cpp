#include <globaldefs.h>
ARM
extern "C" unsigned int ReadWordFieldAtOffset1C(void);
// Original: arm9/ov004 @ 0x0216E894; symbol: func_ov004_0216e894; size: 0x20.
extern "C" int Unclassified_SetTwoFlagsOnWordFieldPointer(void) {
    unsigned char *pointer = (unsigned char *)ReadWordFieldAtOffset1C();
    pointer += 0x1000;
    *(unsigned char *)(pointer + 0x9CA) = 1;
    *(unsigned char *)(pointer + 0x9AF) = 1;
    return 0;
}

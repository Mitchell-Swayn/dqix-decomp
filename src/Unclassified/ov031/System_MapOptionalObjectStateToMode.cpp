#include <globaldefs.h>
ARM
extern "C" unsigned int ReadOptionalObjectByteNine(void);
extern "C" int func_ov031_02214358(void);
// Original: arm9/ov031 @ 0x02212FB8; symbol: func_ov031_02212fb8; size: 0x6C.
extern "C" int System_MapOptionalObjectStateToMode(void) {
    unsigned int value = ReadOptionalObjectByteNine();
    if (value <= 1) return 0;
    if (value < 7) return 1;
    if (value == 9) return 4;
    if (value < 10) return 2;
    if (value == 0xb) return 4;
    if (value < 0x10) return 3;
    if (value == 0x10) return 5;
    if (value == 0x11) return 4;
    return func_ov031_02214358();
}

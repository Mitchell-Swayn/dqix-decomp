#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov031_0224e6a0[];
extern "C" int func_ov031_0221b6f0(void *, int, int);
// Original: arm9/ov031 @ 0x0221AFF8; symbol: func_ov031_0221aff8; size: 0x2C.
extern "C" unsigned int Unclassified_TestGlobalRecordField400(int value) {
    return func_ov031_0221b6f0(*(void **)(data_ov031_0224e6a0 + 8), 0x400, value) != 0;
}

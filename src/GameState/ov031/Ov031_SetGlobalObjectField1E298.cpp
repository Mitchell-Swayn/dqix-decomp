#include <globaldefs.h>
ARM
extern "C" unsigned char *data_ov031_02290c44;
// Original: arm9/ov031 @ 0x0222785C; symbol: func_ov031_0222785c; size: 0x18.
extern "C" void Ov031_SetGlobalObjectField1E298(unsigned int value) {
    *(unsigned int *)(data_ov031_02290c44 + 0x1e298) = value;
}

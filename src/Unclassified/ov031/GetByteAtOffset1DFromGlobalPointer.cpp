#include <globaldefs.h>
ARM
extern "C" unsigned int data_ov031_02290cf4;
// Original: arm9/ov031 @ 0x022351E4; symbol: func_ov031_022351e4; size: 0x14.
extern "C" unsigned int GetByteAtOffset1DFromGlobalPointer(void) {
    unsigned char *object = *(unsigned char **)&data_ov031_02290cf4;
    return object[0x1d];
}

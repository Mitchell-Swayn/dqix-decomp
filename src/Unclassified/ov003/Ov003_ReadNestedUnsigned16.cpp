#include <globaldefs.h>
ARM
// Original: arm9/ov003 @ 0x0217B200; symbol: func_ov003_0217b200; size: 0x14.
extern "C" unsigned int Ov003_ReadNestedUnsigned16(void *object) {
    unsigned short *value = *(unsigned short **)object;
    return value ? (unsigned int)*value : 0;
}

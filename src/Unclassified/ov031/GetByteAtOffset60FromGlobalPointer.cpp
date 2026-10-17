#include <globaldefs.h>
ARM
extern "C" unsigned int data_ov031_02250c00;
// Original: arm9/ov031 @ 0x02225C24; symbol: func_ov031_02225c24; size: 0x14.
extern "C" unsigned int GetByteAtOffset60FromGlobalPointer(void) {
    unsigned char *object = *(unsigned char **)&data_ov031_02250c00;
    return object[0x60];
}

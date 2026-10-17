#include <globaldefs.h>
ARM
extern "C" unsigned int data_ov031_0224e590[];

// Original: arm9/ov031 @ 0x022112E4; symbol: func_ov031_022112e4; size: 0x2C.
extern "C" void *Unclassified_GetGlobalPointerField2CWhenField30Zero(void) {
    unsigned char *object = *(unsigned char **)data_ov031_0224e590;
    return object != 0 && *(unsigned int *)(object + 0x30) == 0
        ? *(void **)(object + 0x2c)
        : 0;
}

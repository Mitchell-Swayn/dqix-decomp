#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021DBB20; symbol: func_ov023_021dbb20; size: 0x14.
extern "C" void func_ov023_021dbb20(void *destination, void *source) {
    *(unsigned int *)destination = *(unsigned int *)source;
    *((unsigned char *)destination + 4) = *((unsigned char *)source + 4);
}

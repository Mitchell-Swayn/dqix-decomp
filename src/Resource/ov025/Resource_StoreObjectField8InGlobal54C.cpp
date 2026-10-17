#include <globaldefs.h>
ARM
extern "C" void *data_ov025_021ef988[];
// Original: arm9/ov025 @ 0x021E628C; symbol: func_ov025_021e628c; size: 0x1C.
extern "C" int Resource_StoreObjectField8InGlobal54C(void *object) {
    *(unsigned int *)((char *)data_ov025_021ef988[3] + 0x54c) = *(unsigned int *)((char *)object + 8);
    return 1;
}

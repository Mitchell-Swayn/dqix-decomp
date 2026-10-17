#include <globaldefs.h>
ARM
extern "C" void *data_ov025_021ef988[];
// Original: arm9/ov025 @ 0x021E8724; symbol: func_ov025_021e8724; size: 0x1C.
extern "C" int Resource_StoreObjectByte8InGlobal5D0(void *object) {
    *((unsigned char *)data_ov025_021ef988[3] + 0x5d0) = *((unsigned char *)object + 8);
    return 1;
}

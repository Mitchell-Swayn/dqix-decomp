#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov025_021ef988[];
// Original: arm9/ov025 @ 0x021E6394; symbol: func_ov025_021e6394; size: 0x1C.
extern "C" int StoreInputOffset8ToGlobalNestedOffset560AndReturnOne(void *input) {
    void *object = *(void **)(data_ov025_021ef988 + 0xc);
    *(unsigned int *)((char *)object + 0x560) = *(unsigned int *)((char *)input + 8);
    return 1;
}

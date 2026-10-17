#include <globaldefs.h>
ARM
extern "C" char data_02109bf4[];
extern "C" void ResourceHandle_StartKeyOperationAndRefreshState(char *p, int key, unsigned a, unsigned b);
// Original: arm9/ov025 @ 0x021E8008; symbol: func_ov025_021e8008; size: 0x1C.
extern "C" unsigned func_ov025_021e8008(void *object, unsigned unused, unsigned a, unsigned b) {
    ResourceHandle_StartKeyOperationAndRefreshState(data_02109bf4, *(int *)((char *)object + 8), a, b);
    return 1;
}

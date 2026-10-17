#include <globaldefs.h>
ARM
extern "C" unsigned char data_02108760[];
extern "C" void ResourceHandle_ApplyAndSaveCurrentState(void *);
// Original: arm9/ov001 @ 0x02163994; symbol: func_ov001_02163994; size: 0x18.
extern "C" int ApplyCurrentResourceStateAndReturnOne(void) {
    ResourceHandle_ApplyAndSaveCurrentState(data_02108760);
    return 1;
}

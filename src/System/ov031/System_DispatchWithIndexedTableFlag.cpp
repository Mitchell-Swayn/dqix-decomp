#include <globaldefs.h>
ARM
extern "C" unsigned int data_ov031_02245ff4[];
extern "C" void System_DispatchOneOfTwoHandlers(void *first, void *second, unsigned int flags);
// Original: arm9/ov031 @ 0x022151B0; symbol: func_ov031_022151b0; size: 0x24.
extern "C" void System_DispatchWithIndexedTableFlag(void *first, void *second, int index, unsigned int flags) {
    if (index > 0x0c)
        index = 0x0c;
    unsigned int combined = flags | data_ov031_02245ff4[index];
    System_DispatchOneOfTwoHandlers(first, second, combined);
}

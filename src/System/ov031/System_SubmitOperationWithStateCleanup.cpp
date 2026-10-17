#include <globaldefs.h>
ARM
extern "C" void* data_ov031_0224e5d8;
extern "C" int SubmitOperationTwoAndNormalizePendingResult(unsigned int value);
// Original: arm9/ov031 @ 0x02216070; symbol: func_ov031_02216070; size: 0x40.
extern "C" int System_SubmitOperationWithStateCleanup(unsigned int value) {
    if (value == 0)
        return -1;
    *(unsigned int*)((char*)data_ov031_0224e5d8 + 0x1a90) = 3;
    data_ov031_0224e5d8 = 0;
    int result = SubmitOperationTwoAndNormalizePendingResult(value);
    if (result == 2)
        result = 0;
    return result;
}

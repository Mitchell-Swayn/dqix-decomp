#include <globaldefs.h>
ARM
extern "C" void *data_ov031_0224e5d8;
extern "C" int ValidateStatusFiveAndDispatchCommandEleven(void *);
// Original: arm9/ov031 @ 0x02216178; symbol: func_ov031_02216178; size: 0x38.
extern "C" int System_SetCommandFlagAndValidate(void *param) {
    if (param == 0) return -1;
    *(int *)((unsigned char *)data_ov031_0224e5d8 + 0x1A90) = 2;
    int result = ValidateStatusFiveAndDispatchCommandEleven(param);
    if (result == 2) result = 0;
    return result;
}

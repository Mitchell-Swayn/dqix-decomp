#include <globaldefs.h>
ARM
extern "C" int func_ov027_021d8c6c(void *argument, int code, const short *value);
// Original: arm9/ov027 @ 0x021D9E04; symbol: func_ov027_021d9e04; size: 0x18.
extern "C" int InvokeCallbackWithCode13AndHalfword(void *argument, short value) {
    short local = value;
    return func_ov027_021d8c6c(argument, 13, &local);
}

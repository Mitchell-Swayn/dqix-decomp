#include <globaldefs.h>
ARM
extern "C" void Object_ResetAsyncStateAndDisplayControl(void *object);
// Original: arm9/ov017 @ 0x021A7A5C; symbol: func_ov017_021a7a5c; size: 0x18.
extern "C" void Util_RunInitializerAndSetByte1(void *object) {
    Object_ResetAsyncStateAndDisplayControl(object);
    *(unsigned char *)((char *)object + 1) = 1;
}

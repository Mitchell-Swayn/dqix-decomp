#include <globaldefs.h>
ARM
extern "C" int MBi_CommChangeParentStateCallbackOnly(void *argument, int code, const short *value);
// Original: arm9/ov027 @ 0x021D9E04; symbol: func_ov027_021d9e04; size: 0x18.
extern "C" int MBi_CommCallParentError(void *argument, short value) {
    short local = value;
    return MBi_CommChangeParentStateCallbackOnly(argument, 13, &local);
}

#include <globaldefs.h>
ARM
extern unsigned int data_ov031_0224c8a8[];
// Original: arm9/ov031 @ 0x02243690; symbol: func_ov031_02243690; size: 0x30.
extern "C" int Object_InvokeByteIndexedCallbackFromField2C(unsigned char *object) {
    int index = (signed char)object[0x2c];
    if (index >= 0) {
        int (*callback)(unsigned char *) = (int (*)(unsigned char *))data_ov031_0224c8a8[index];
        object[0x2c] = (unsigned char)callback(object);
    }
    return 1;
}

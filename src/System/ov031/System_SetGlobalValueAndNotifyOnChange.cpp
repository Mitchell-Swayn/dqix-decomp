#include <globaldefs.h>
THUMB
struct GlobalValueSlot { unsigned int unused; unsigned int value; };
extern "C" GlobalValueSlot data_ov031_0224b070;
extern "C" int InvokeOptionalCallbackAtGlobalOffset4(unsigned int);
// Original: arm9/ov031 @ 0x0221D384; symbol: func_ov031_0221d384; size: 0x2C.
extern "C" int System_SetGlobalValueAndNotifyOnChange(unsigned int value) {
    if (value == 0xffffffffu) {
        data_ov031_0224b070.value = value;
        return 0;
    }
    if (data_ov031_0224b070.value != value) {
        data_ov031_0224b070.value = value;
        return InvokeOptionalCallbackAtGlobalOffset4(value);
    }
    return 0;
}

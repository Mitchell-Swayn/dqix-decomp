#include <globaldefs.h>
ARM
extern "C" void SetSharedObjectWord54UnlessStateNineOrTen(unsigned);
extern "C" int func_ov031_022399d8(void);
extern "C" void func_ov031_0223a358(void);
extern "C" void (*data_ov031_02290d18)(unsigned, const void*);
extern "C" char data_ov031_0224c3f4[];
// Original: arm9/ov031 @ 0x02239984; symbol: func_ov031_02239984; size: 0x54.
extern "C" void System_TransitionSharedObjectAndInvokeCallback(void* object) {
    unsigned value = *(unsigned short*)((char*)object + 2);
    if (value != 0) {
        SetSharedObjectWord54UnlessStateNineOrTen(value);
        func_ov031_0223a358();
        return;
    }
    if (func_ov031_022399d8()) return;
    if (data_ov031_02290d18 != 0)
        data_ov031_02290d18(0x08000000, data_ov031_0224c3f4);
    func_ov031_0223a358();
}

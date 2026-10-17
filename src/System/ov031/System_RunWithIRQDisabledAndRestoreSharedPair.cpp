#include <globaldefs.h>
extern "C" int _Z20DisableIRQInterruptsv();
extern "C" int _Z20SetIRQInterruptStatei(int);
extern "C" int func_ov031_02204c84(void*);
extern "C" unsigned data_ov031_0224c9e0[];
// Original: arm9/ov031 @ 0x02206EBC; symbol: func_ov031_02206ebc; size: 0x4C.
extern "C" int System_RunWithIRQDisabledAndRestoreSharedPair(void* object) {
    int irq = _Z20DisableIRQInterruptsv();
    unsigned first = data_ov031_0224c9e0[0];
    unsigned second = data_ov031_0224c9e0[1];
    data_ov031_0224c9e0[0] = 0;
    data_ov031_0224c9e0[1] = 0;
    int result = func_ov031_02204c84(object);
    data_ov031_0224c9e0[0] = first;
    data_ov031_0224c9e0[1] = second;
    _Z20SetIRQInterruptStatei(irq);
    return result;
}

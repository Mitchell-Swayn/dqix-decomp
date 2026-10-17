#include <globaldefs.h>
THUMB
extern "C" unsigned char data_ov031_0224f620[];
extern "C" int _Z20DisableIRQInterruptsv(void);
extern "C" int _Z20SetIRQInterruptStatei(int);
extern "C" int func_ov031_0220d214(void);
// Original: arm9/ov031 @ 0x0221F158; symbol: func_ov031_0221f158; size: 0x38.
extern "C" int AdvanceInterruptProtectedState(void) {
    int irqState = _Z20DisableIRQInterruptsv();
    if (*(int*)(data_ov031_0224f620 + 0x18) == 7 && func_ov031_0220d214() == 3) {
        *(int*)(data_ov031_0224f620 + 0x18) = 4;
        _Z20SetIRQInterruptStatei(irqState);
        return 1;
    }
    _Z20SetIRQInterruptStatei(irqState);
    return 0;
}

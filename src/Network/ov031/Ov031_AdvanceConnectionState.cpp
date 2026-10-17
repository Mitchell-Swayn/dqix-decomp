#include <globaldefs.h>
THUMB
extern "C" int _Z20DisableIRQInterruptsv(void);
extern "C" int _Z20SetIRQInterruptStatei(int);
extern "C" int System_DispatchOneOfTwoHandlers(int, int, int);
extern "C" char data_ov031_0224f620[];
// Original: arm9/ov031 @ 0x0221F11C; symbol: func_ov031_0221f11c; size: 0x3C.
extern "C" int Ov031_AdvanceConnectionState(void) {
    int state = _Z20DisableIRQInterruptsv();
    if (*(int *)(data_ov031_0224f620 + 0x18) == 5 && System_DispatchOneOfTwoHandlers(0, 0, 0) == 3) {
        *(int *)(data_ov031_0224f620 + 0x18) = 4;
        _Z20SetIRQInterruptStatei(state);
        return 1;
    }
    _Z20SetIRQInterruptStatei(state);
    return 0;
}

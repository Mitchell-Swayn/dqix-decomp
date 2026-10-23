#include <globaldefs.h>
THUMB
extern "C" ARM int _Z20DisableIRQInterruptsv(void);
extern "C" ARM int _Z20SetIRQInterruptStatei(int);
extern "C" ARM int Network_RequestWirelessPowerOff(void);
extern "C" THUMB int Network_StopQueueSessionWirelessOperation(void);
// Original data: arm9/ov031 @ 0x0224F620; symbol: data_ov031_0224f620.
extern "C" unsigned char Ov031AdvanceConnectionState_UnknownRoleZeroInitializedStorage[];
THUMB
// Original: arm9/ov031 @ 0x0221F190; symbol: func_ov031_0221f190; size: 0x58.
// Requests shutdown under the IRQ guard and marks a successful request as state two.
extern "C" int Network_BeginQueueSessionShutdown(void) {
    int irq = _Z20DisableIRQInterruptsv();
    int state = *(int*)(Ov031AdvanceConnectionState_UnknownRoleZeroInitializedStorage + 24);
    if (state == 3) {
        int result = Network_RequestWirelessPowerOff();
        if (result != 3) {
            _Z20SetIRQInterruptStatei(irq);
            return 0;
        }
        *(int*)(Ov031AdvanceConnectionState_UnknownRoleZeroInitializedStorage + 24) = 2;
        _Z20SetIRQInterruptStatei(irq);
        return 1;
    }
    int result = Network_StopQueueSessionWirelessOperation();
    if (result == 1) {
        *(int*)(Ov031AdvanceConnectionState_UnknownRoleZeroInitializedStorage + 24) = 2;
        _Z20SetIRQInterruptStatei(irq);
        return 1;
    }
    _Z20SetIRQInterruptStatei(irq);
    return 0;
}

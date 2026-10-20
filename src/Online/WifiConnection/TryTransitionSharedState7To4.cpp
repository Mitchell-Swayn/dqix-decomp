#include <globaldefs.h>
THUMB
extern "C" int _Z20DisableIRQInterruptsv(void);
extern "C" void _Z20SetIRQInterruptStatei(int);
extern "C" int Network_RequestDcfDisconnect(void);
// Original data: arm9/ov031 @ 0x224f670; symbol: data_ov031_0224f670.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 80 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned int WirelessSetupRunConfigurationExchange_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x0221F7C4; symbol: TryTransitionSharedState7To4; size: 0x38.
// With IRQs disabled, checks global state 7 and helper state 3, writes state 4 on success, restores the prior IRQ state, and returns the result.
extern "C" int TryTransitionSharedState7To4(void) {
    int irq = _Z20DisableIRQInterruptsv();
    if (WirelessSetupRunConfigurationExchange_UnknownRoleZeroInitializedStorage[0x2C / 4] == 7 && Network_RequestDcfDisconnect() == 3) {
        WirelessSetupRunConfigurationExchange_UnknownRoleZeroInitializedStorage[0x2C / 4] = 4;
        _Z20SetIRQInterruptStatei(irq);
        return 1;
    }
    _Z20SetIRQInterruptStatei(irq);
    return 0;
}

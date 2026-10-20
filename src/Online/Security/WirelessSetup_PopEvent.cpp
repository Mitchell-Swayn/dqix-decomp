#include <globaldefs.h>
THUMB
extern "C" {
ARM int _Z20DisableIRQInterruptsv(void);
ARM int _Z20SetIRQInterruptStatei(int state);
}
THUMB
// Original data: arm9/ov031 @ 0x224f670; symbol: data_ov031_0224f670.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 80 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WirelessSetupRunConfigurationExchange_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/ov031 @ 0x224f6f4; symbol: data_ov031_0224f6f4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned WirelessSetupPopEvent_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x0221FA20; symbol: func_ov031_0221fa20; size: 0x38.
extern "C" unsigned WirelessSetup_PopEvent(void) {
    int irq = _Z20DisableIRQInterruptsv();
    volatile unsigned char *state = WirelessSetupRunConfigurationExchange_UnknownRoleZeroInitializedStorage;
    int tail = *(volatile int *)(state + 0x6c);
    int head = *(volatile int *)(state + 0x68);
    unsigned value;
    if (head == tail) {
        value = 0;
    } else {
        value = WirelessSetupPopEvent_UnknownRoleZeroInitializedStorage[(unsigned)tail];
        int next = tail + 1;
        *(volatile unsigned *)(state + 0x6c) = next;
        if (next >= 4) {
            next = 0;
            *(volatile unsigned *)(state + 0x6c) = next;
        }
    }
    _Z20SetIRQInterruptStatei(irq);
    return value;
}

#include <globaldefs.h>
THUMB
// Original data: arm9/ov031 @ 0x224f620; symbol: data_ov031_0224f620.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 40 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char Ov031AdvanceConnectionState_UnknownRoleZeroInitializedStorage[];
extern "C" int _Z20DisableIRQInterruptsv(void);
extern "C" int _Z20SetIRQInterruptStatei(int);
extern "C" int Network_RequestDcfDisconnect(void);
// Original: arm9/ov031 @ 0x0221F158; symbol: func_ov031_0221f158; size: 0x38.
extern "C" int Network_DisconnectQueueSession(void) {
    int irqState = _Z20DisableIRQInterruptsv();
    if (*(int*)(Ov031AdvanceConnectionState_UnknownRoleZeroInitializedStorage + 0x18) == 7 && Network_RequestDcfDisconnect() == 3) {
        *(int*)(Ov031AdvanceConnectionState_UnknownRoleZeroInitializedStorage + 0x18) = 4;
        _Z20SetIRQInterruptStatei(irqState);
        return 1;
    }
    _Z20SetIRQInterruptStatei(irqState);
    return 0;
}

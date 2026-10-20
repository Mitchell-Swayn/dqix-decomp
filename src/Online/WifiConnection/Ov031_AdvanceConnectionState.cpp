#include <globaldefs.h>
THUMB
extern "C" int _Z20DisableIRQInterruptsv(void);
extern "C" int _Z20SetIRQInterruptStatei(int);
extern "C" int Network_RequestScanOrStopScan(int, int, int);
// Original data: arm9/ov031 @ 0x224f620; symbol: data_ov031_0224f620.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 40 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char Ov031AdvanceConnectionState_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x0221F11C; symbol: func_ov031_0221f11c; size: 0x3C.
extern "C" int Ov031_AdvanceConnectionState(void) {
    int state = _Z20DisableIRQInterruptsv();
    if (*(int *)(Ov031AdvanceConnectionState_UnknownRoleZeroInitializedStorage + 0x18) == 5 && Network_RequestScanOrStopScan(0, 0, 0) == 3) {
        *(int *)(Ov031AdvanceConnectionState_UnknownRoleZeroInitializedStorage + 0x18) = 4;
        _Z20SetIRQInterruptStatei(state);
        return 1;
    }
    _Z20SetIRQInterruptStatei(state);
    return 0;
}

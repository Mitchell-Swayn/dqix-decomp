#include <globaldefs.h>
ARM
extern "C" int _Z20DisableIRQInterruptsv(void);
extern "C" int _Z20SetIRQInterruptStatei(int);
// Original data: arm9/ov031 @ 0x224e53c; symbol: data_ov031_0224e53c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char *NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x0220CA88; symbol: func_ov031_0220ca88; size: 0x58.
extern "C" int System_ClearSharedPointerWhenWord2260IsOne(void) {
    int irqState = _Z20DisableIRQInterruptsv();
    char *object = NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage;
    if (object == 0) {
        _Z20SetIRQInterruptStatei(irqState);
        return 1;
    }
    if (*(unsigned int *)(object + 0x2260) != 1) {
        _Z20SetIRQInterruptStatei(irqState);
        return 1;
    }
    NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage = 0;
    _Z20SetIRQInterruptStatei(irqState);
    return 0;
}

#include <globaldefs.h>
ARM

// Original data: arm9/ov031 @ 0x2290c88; symbol: data_ov031_02290c88.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char Ov031AdvanceCallbackDelay_UnknownRoleZeroInitializedStorage;
extern "C" void System_ConfigureTwoDisplayModes(void);
extern "C" void WfcUtility_SetMainLoopCallback(void (*)(void));

// Original: arm9/ov031 @ 0x0222B610; symbol: func_ov031_0222b610; size: 0x34.
extern "C" void Ov031_AdvanceCallbackDelay(void) {
    unsigned int count = Ov031AdvanceCallbackDelay_UnknownRoleZeroInitializedStorage + 1;
    Ov031AdvanceCallbackDelay_UnknownRoleZeroInitializedStorage = count;
    count &= 0xff;
    if (count >= 0x78) {
        WfcUtility_SetMainLoopCallback(System_ConfigureTwoDisplayModes);
    }
}

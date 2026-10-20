#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290ca0; symbol: data_ov031_02290ca0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char StartMode6ContextCallback_UnknownRoleZeroInitializedStorage[];
extern "C" char *WfcUtility_GetEditableConnectionProfile(void);
extern "C" void WfcUtility_GetScreenOperationArguments(unsigned *, unsigned *);
// Original: arm9/ov031 @ 0x0222EE34; symbol: func_ov031_0222ee34; size: 0x3C.
extern "C" void Network_ClearStateWhenOptionalWordIsZero(void) {
    WfcUtility_GetEditableConnectionProfile();
    unsigned int value;
    WfcUtility_GetScreenOperationArguments(0, &value);
    switch (value) {
    case 0:
        *(unsigned short *)(StartMode6ContextCallback_UnknownRoleZeroInitializedStorage + 4) = 0;
        StartMode6ContextCallback_UnknownRoleZeroInitializedStorage[0] = 0;
        StartMode6ContextCallback_UnknownRoleZeroInitializedStorage[2] = 0;
        break;
    default:
        return;
    }
}

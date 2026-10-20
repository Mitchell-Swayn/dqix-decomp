#include <globaldefs.h>
ARM
extern "C" void WirelessHost_StoreErrorUnlessTerminal(unsigned);
extern "C" int WirelessCommand_SubmitCallbackAndStoreResultUnlessTwo(void);
extern "C" void Network_SetStateTenWhenSubmitResultIsZero(void);
// Original data: arm9/ov031 @ 0x2290d18; symbol: data_ov031_02290d18.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" void (*WirelessHostGetSystemState_UnknownRoleZeroInitializedStorage)(unsigned, const void*);
extern "C" char System_TransitionSharedObjectAndInvokeCallback_TextDWCiMOVWHStateInEndParentFailed[];
// Original: arm9/ov031 @ 0x02239984; symbol: func_ov031_02239984; size: 0x54.
extern "C" void System_TransitionSharedObjectAndInvokeCallback(void* object) {
    unsigned value = *(unsigned short*)((char*)object + 2);
    if (value != 0) {
        WirelessHost_StoreErrorUnlessTerminal(value);
        Network_SetStateTenWhenSubmitResultIsZero();
        return;
    }
    if (WirelessCommand_SubmitCallbackAndStoreResultUnlessTwo()) return;
    if (WirelessHostGetSystemState_UnknownRoleZeroInitializedStorage != 0)
        WirelessHostGetSystemState_UnknownRoleZeroInitializedStorage(0x08000000, System_TransitionSharedObjectAndInvokeCallback_TextDWCiMOVWHStateInEndParentFailed);
    Network_SetStateTenWhenSubmitResultIsZero();
}

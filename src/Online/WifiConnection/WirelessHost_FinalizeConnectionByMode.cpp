#include <globaldefs.h>
ARM
extern "C" void WirelessHost_SetSystemState(int);
extern "C" int Wireless_SubmitOpcode16AndUpdateSharedState(void);
extern "C" int GameState_RefreshSharedObjectOnModeSix(void);
extern "C" int System_SubmitOpcodeSixteenAndApplyResult(void);
extern "C" void Network_SetStateTenWhenSubmitResultIsZero(void);
extern "C" int Network_QuerySharedStateAndReturnForStatusTwo(void);
// Original data: arm9/ov031 @ 0x2290d18; symbol: data_ov031_02290d18.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WirelessHostGetSystemState_UnknownRoleZeroInitializedStorage[];
extern "C" char WirelessHost_FinalizeConnectionByMode_TextAlreadyDWCiMOVWHSYSSTATEIDLE[];
extern "C" char WirelessHost_FinalizeConnectionByMode_FormatDWCiMOVWHFinalizeStateD[];
typedef void (*OverlayLog)(unsigned, const char*, ...);
// Original: arm9/ov031 @ 0x0223A374; symbol: DispatchOverlayTransitionAndModeAction; size: 0x108.
// Dispatches overlay state transitions, logging state callbacks and applying mode-specific actions.
extern "C" void WirelessHost_FinalizeConnectionByMode(void) {
    void* initialState = *(void**)(WirelessHostGetSystemState_UnknownRoleZeroInitializedStorage + 4);
    unsigned initialMode = *(unsigned*)((char*)initialState + 0x40);
    if (initialMode == 1) {
        OverlayLog callback = *(OverlayLog volatile*)WirelessHostGetSystemState_UnknownRoleZeroInitializedStorage;
        if (callback) callback(0x08000000, WirelessHost_FinalizeConnectionByMode_TextAlreadyDWCiMOVWHSYSSTATEIDLE);
        return;
    }
    OverlayLog callback = *(OverlayLog volatile*)WirelessHostGetSystemState_UnknownRoleZeroInitializedStorage;
    if (callback) callback(0x08000000, WirelessHost_FinalizeConnectionByMode_FormatDWCiMOVWHFinalizeStateD, initialMode);
    unsigned mode = *(unsigned*)((char*)*(void**)(WirelessHostGetSystemState_UnknownRoleZeroInitializedStorage + 4) + 0x40);
    if (mode != 6 && mode != 5 && mode != 4) {
        WirelessHost_SetSystemState(3);
        Network_SetStateTenWhenSubmitResultIsZero();
        return;
    }
    WirelessHost_SetSystemState(3);
    unsigned substate = *(unsigned*)((char*)*(void**)(WirelessHostGetSystemState_UnknownRoleZeroInitializedStorage + 4) + 0x44);
    if (substate > 5) return;
    switch (substate) {
    case 3:
        if (GameState_RefreshSharedObjectOnModeSix()) return;
        Network_SetStateTenWhenSubmitResultIsZero();
        return;
    case 1:
    case 5:
        if (System_SubmitOpcodeSixteenAndApplyResult()) return;
        Network_SetStateTenWhenSubmitResultIsZero();
        return;
    case 2:
        if (Network_QuerySharedStateAndReturnForStatusTwo()) return;
        Network_SetStateTenWhenSubmitResultIsZero();
        return;
    case 0:
    case 4:
        if (Wireless_SubmitOpcode16AndUpdateSharedState()) return;
        Network_SetStateTenWhenSubmitResultIsZero();
        return;
    }
}

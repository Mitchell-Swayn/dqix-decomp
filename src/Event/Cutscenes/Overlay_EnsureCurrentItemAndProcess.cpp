#include <globaldefs.h>
// Original data: arm9/ov001 @ 0x2165828; symbol: data_ov001_02165828.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 84 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" unsigned char OverlayEnsureCurrentItemAndProcess_UnknownRoleZeroInitializedStorage[];
extern "C" void GameState_ProcessPendingOperationIfPresent(void*);
extern "C" void Event_AdvanceObjectAndMotionSessions();
extern "C" void Graphics_ResetWindowConfiguration(void*);
// Original: arm9/ov001 @ 0x02153994; symbol: func_ov001_02153994; size: 0x44.
extern "C" int Overlay_EnsureCurrentItemAndProcess() {
    GameState_ProcessPendingOperationIfPresent(OverlayEnsureCurrentItemAndProcess_UnknownRoleZeroInitializedStorage);
    if (!*(void**)(OverlayEnsureCurrentItemAndProcess_UnknownRoleZeroInitializedStorage + 0x3c)) Event_AdvanceObjectAndMotionSessions();
    void* item = *(void**)(OverlayEnsureCurrentItemAndProcess_UnknownRoleZeroInitializedStorage + 0x3c);
    if (!item) return 0;
    Graphics_ResetWindowConfiguration(item);
    return 1;
}

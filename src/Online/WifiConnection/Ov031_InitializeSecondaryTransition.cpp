#include <globaldefs.h>
// Original data: arm9/ov031 @ 0x2290cc0; symbol: data_ov031_02290cc0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char ConfigureSecondContextDisplay_UnknownRoleZeroInitializedStorage[];
extern "C" void* Memory_AllocateZeroedBlock(unsigned, unsigned);
extern "C" void Graphics_LoadSecondaryPlaneResourcesAndConfigurePriorities();
extern "C" void System_CreateCopyAndFinalizeResource(unsigned);
extern "C" void WfcUtility_ShowFormattedMessagePanel(unsigned, int, unsigned);
extern "C" void WfcUtility_ConfigureSecondaryControlsForDisplayMode(unsigned);
extern "C" void WfcUtility_CreateConnectionProfileSprites();
extern "C" void WfcUtility_PositionProfileSelectionHighlight();
extern "C" void Graphics_ConfigureMode2Masks1And0x14ThenSelectMode0();
extern "C" void WfcUtility_SetMainLoopCallback(void (*)());
// Original: arm9/ov031 @ 0x02232508; symbol: func_ov031_02232508; size: 0x60.
extern "C" ARM void Ov031_InitializeSecondaryTransition() {
    void* object = Memory_AllocateZeroedBlock(0x20, 4);
    *(void**)(ConfigureSecondContextDisplay_UnknownRoleZeroInitializedStorage + 4) = object;
    *((unsigned char*)object + 0x1d) = 0;
    Graphics_LoadSecondaryPlaneResourcesAndConfigurePriorities();
    System_CreateCopyAndFinalizeResource(1);
    WfcUtility_ShowFormattedMessagePanel(0x2f, -1, 0);
    WfcUtility_ConfigureSecondaryControlsForDisplayMode(0);
    WfcUtility_CreateConnectionProfileSprites();
    WfcUtility_PositionProfileSelectionHighlight();
    WfcUtility_SetMainLoopCallback(Graphics_ConfigureMode2Masks1And0x14ThenSelectMode0);
}

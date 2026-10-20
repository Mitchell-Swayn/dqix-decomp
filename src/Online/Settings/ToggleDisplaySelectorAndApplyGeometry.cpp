#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290c50; symbol: data_ov031_02290c50.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WfcUtilityInitializeMainMenu_UnknownRoleZeroInitializedStorage;
// Original data: arm9/ov031 @ 0x2248d9e; symbol: data_ov031_02248d9e.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0600.
// Observed span: 2 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned short WfcUtilityInitializeMainMenu_UnknownRoleInitializedBytes;
// Original data: arm9/ov031 @ 0x2248da2; symbol: data_ov031_02248da2.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 9e00.
// Observed span: 2 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned short WfcUtilityInitializeMainMenu_UnknownRoleInitializedBytes_Variant3;
// Original data: arm9/ov031 @ 0x2248da0; symbol: data_ov031_02248da0.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 1e00.
// Observed span: 2 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned short WfcUtilityInitializeMainMenu_UnknownRoleInitializedBytes_Variant2;
// Original data: arm9/ov031 @ 0x2248da4; symbol: data_ov031_02248da4.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 9200b2001e00ea009200.
// Observed span: 10 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned short WfcUtilityInitializeMainMenu_UnknownRoleInitializedBytes_Variant4;
extern "C" void WfcUtility_PlaySequenceArchiveEntry(int);
extern "C" void WfcUtility_CreateCornerSelectionMarkers(unsigned int, unsigned int, unsigned int, unsigned int);
// Original: arm9/ov031 @ 0x022284EC; symbol: ToggleDisplaySelectorAndApplyGeometry; size: 0x70.
// For modes other than 1 or 3, toggles the selector, selects mode 8, reads four table halfwords, and passes them to geometry helper.
extern "C" void ToggleDisplaySelectorAndApplyGeometry(int mode) {
    if (mode == 1 || mode == 3) return;
    WfcUtilityInitializeMainMenu_UnknownRoleZeroInitializedStorage ^= 1;
    WfcUtility_PlaySequenceArchiveEntry(8);
    unsigned int offset = WfcUtilityInitializeMainMenu_UnknownRoleZeroInitializedStorage * 8;
    WfcUtility_CreateCornerSelectionMarkers(*(unsigned short*)((char*)&WfcUtilityInitializeMainMenu_UnknownRoleInitializedBytes + offset), *(unsigned short*)((char*)&WfcUtilityInitializeMainMenu_UnknownRoleInitializedBytes_Variant3 + offset), *(unsigned short*)((char*)&WfcUtilityInitializeMainMenu_UnknownRoleInitializedBytes_Variant2 + offset), *(unsigned short*)((char*)&WfcUtilityInitializeMainMenu_UnknownRoleInitializedBytes_Variant4 + offset));
}

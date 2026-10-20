#pragma thumb off
struct BytePair {unsigned char values[2];};
struct Selection {unsigned char index;char pad[3];unsigned base;};
// Original data: arm9/ov031 @ 0x2248d8c; symbol: data_ov031_02248d8c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0102.
// Observed span: 2 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" BytePair GraphicsConfigureTransformUsingSelectedByte_UnknownRoleInitializedBytes;
// Original data: arm9/ov031 @ 0x2290c50; symbol: data_ov031_02290c50.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" Selection WfcUtilityInitializeMainMenu_UnknownRoleZeroInitializedStorage;
extern "C" void WfcUtility_QueueBackgroundPaletteBankCopy(unsigned,unsigned,unsigned);
// Original: arm9/ov031 @ 0x0222855C; symbol: func_ov031_0222855c; size: 0x40.
extern "C" void Graphics_ConfigureTransformUsingSelectedByte() {
 BytePair choices=GraphicsConfigureTransformUsingSelectedByte_UnknownRoleInitializedBytes;
 unsigned selected=choices.values[WfcUtilityInitializeMainMenu_UnknownRoleZeroInitializedStorage.index];
 WfcUtility_QueueBackgroundPaletteBankCopy(WfcUtilityInitializeMainMenu_UnknownRoleZeroInitializedStorage.base,selected,selected);
}

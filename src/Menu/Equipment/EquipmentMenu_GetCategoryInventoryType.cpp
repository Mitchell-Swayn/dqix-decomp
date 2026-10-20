// Original data: arm9/ov005 @ 0x215cd18; symbol: data_ov005_0215cd18.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0001040205030607.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov005.md.
extern unsigned char EquipmentMenuGetCategoryInventoryType_UnknownRoleInitializedBytes[8];
// Original: arm9/ov005 @ 0x0215A948; symbol: func_ov005_0215a948; size: 0x18.
extern "C" unsigned EquipmentMenu_GetCategoryInventoryType(void* unused, unsigned index) { return index >= 8 ? 0 : EquipmentMenuGetCategoryInventoryType_UnknownRoleInitializedBytes[index]; }

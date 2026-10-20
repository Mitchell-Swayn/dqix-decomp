// Original data: arm9/ov005 @ 0x215cd20; symbol: data_ov005_0215cd20.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 080907000501060a.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov005.md.
extern unsigned char EquipmentMenuGetCategoryEquipmentRecordIndex_UnknownRoleInitializedBytes[8];
// Original: arm9/ov005 @ 0x0215A930; symbol: func_ov005_0215a930; size: 0x18.
extern "C" unsigned EquipmentMenu_GetCategoryEquipmentRecordIndex(void* unused, unsigned index) { return index >= 8 ? 0 : EquipmentMenuGetCategoryEquipmentRecordIndex_UnknownRoleInitializedBytes[index]; }

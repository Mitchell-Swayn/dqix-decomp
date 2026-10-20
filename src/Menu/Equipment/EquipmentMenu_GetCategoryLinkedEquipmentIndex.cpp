// Original data: arm9/ov005 @ 0x215cd28; symbol: data_ov005_0215cd28.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0708060004010509.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov005.md.
extern unsigned char EquipmentMenuGetCategoryLinkedEquipmentIndex_UnknownRoleInitializedBytes[8];
// Original: arm9/ov005 @ 0x0215A918; symbol: func_ov005_0215a918; size: 0x18.
extern "C" unsigned EquipmentMenu_GetCategoryLinkedEquipmentIndex(void* unused, unsigned index) { return index >= 8 ? 0 : EquipmentMenuGetCategoryLinkedEquipmentIndex_UnknownRoleInitializedBytes[index]; }

// Dimensions are computed from the overlay's original floating-point configuration.
#pragma define_section init ".init" RX
extern "C" {
// Original data: arm9/ov014 @ 0x21895a0; symbol: data_ov014_021895a0.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0000f0410000f0410000344300003443.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov014.md.
extern float GraphicsUpdateObjectInputRotationAndDispatch_UnknownRoleInitializedBytes[4];
// Original data: arm9/ov014 @ 0x2189800; symbol: data_ov014_02189800.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 28 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov014.md.
extern float BestiaryDetailInitialize_UnknownRoleZeroInitializedStorage[7];
// Original: arm9/ov014 @ 0x02189510; symbol: __sinit_ov014_02189510; size: 0x88.
__declspec(section "init") void __sinit_ov014_02189510() {
 BestiaryDetailInitialize_UnknownRoleZeroInitializedStorage[6]=GraphicsUpdateObjectInputRotationAndDispatch_UnknownRoleInitializedBytes[0]+(GraphicsUpdateObjectInputRotationAndDispatch_UnknownRoleInitializedBytes[3]+(GraphicsUpdateObjectInputRotationAndDispatch_UnknownRoleInitializedBytes[2]+GraphicsUpdateObjectInputRotationAndDispatch_UnknownRoleInitializedBytes[1]));
 BestiaryDetailInitialize_UnknownRoleZeroInitializedStorage[2]=BestiaryDetailInitialize_UnknownRoleZeroInitializedStorage[5]+GraphicsUpdateObjectInputRotationAndDispatch_UnknownRoleInitializedBytes[2];
 float sum=BestiaryDetailInitialize_UnknownRoleZeroInitializedStorage[2]+GraphicsUpdateObjectInputRotationAndDispatch_UnknownRoleInitializedBytes[1];
 float right=GraphicsUpdateObjectInputRotationAndDispatch_UnknownRoleInitializedBytes[3];
 BestiaryDetailInitialize_UnknownRoleZeroInitializedStorage[4]=sum;
 BestiaryDetailInitialize_UnknownRoleZeroInitializedStorage[0]=sum+right;
}
}

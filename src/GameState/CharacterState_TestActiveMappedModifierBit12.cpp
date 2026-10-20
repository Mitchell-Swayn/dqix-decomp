// Original data: arm9/main @ 0x20e8b24; symbol: data_020e8b24.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00.
// Observed span: 1 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x20e8b25; symbol: data_020e8b25.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 08010002090307040505010606070affff.
// Observed span: 17 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" signed char CharacterStateTestActiveMappedModifierBit12_UnknownRoleInitializedBytes[],CharacterStateTestActiveMappedModifierBit12_UnknownRoleInitializedBytes_Variant2[];
// Original: arm9/main @ 0x02085230; symbol: func_02085230; size: 0x74.
 extern "C" int CharacterState_TestActiveMappedModifierBit12(unsigned char *self) { int i=0; while(CharacterStateTestActiveMappedModifierBit12_UnknownRoleInitializedBytes[i*2]!=-1) { int slot=CharacterStateTestActiveMappedModifierBit12_UnknownRoleInitializedBytes[i*2]; if(*(short *)(self+CharacterStateTestActiveMappedModifierBit12_UnknownRoleInitializedBytes_Variant2[i*2]*32+0x1ac)>0 && ((*(unsigned int *)(self+slot*44+0x2f4)<<19)>>31)!=0) return 1; ++i; } return 0; }

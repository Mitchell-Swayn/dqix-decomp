#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x20e8b5a; symbol: data_020e8b5a.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00.
// Observed span: 1 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x20e8b5b; symbol: data_020e8b5b.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 08010002090307040505010606070affff.
// Observed span: 17 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" signed char CharacterStateCountActiveMappedModifierBit15_UnknownRoleInitializedBytes[]; extern "C" signed char CharacterStateCountActiveMappedModifierBit15_UnknownRoleInitializedBytes_Variant2[];
struct Flags { unsigned pad:15; unsigned active:1; };
// Original: arm9/main @ 0x02085318; symbol: func_02085318; size: 0x74.
extern "C" int CharacterState_CountActiveMappedModifierBit15(char *self) { int result,i=0,index; result=0; while((index=CharacterStateCountActiveMappedModifierBit15_UnknownRoleInitializedBytes[i*2])!=-1) { if(*(short *)(self+CharacterStateCountActiveMappedModifierBit15_UnknownRoleInitializedBytes_Variant2[i+i]*32+0x1ac)>0 && ((Flags *)(self+index*44+0x2f4))->active) ++result; ++i; } return result; }

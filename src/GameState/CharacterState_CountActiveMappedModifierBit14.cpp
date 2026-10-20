#include <globaldefs.h>
ARM
#pragma optimize_for_size off
#pragma optimization_level 2
#pragma opt_common_subs off
// Original data: arm9/main @ 0x20e8b48; symbol: data_020e8b48.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00.
// Observed span: 1 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x20e8b49; symbol: data_020e8b49.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 08010002090307040505010606070affff.
// Observed span: 17 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" signed char CharacterStateCountActiveMappedModifierBit14_UnknownRoleInitializedBytes[],CharacterStateCountActiveMappedModifierBit14_UnknownRoleInitializedBytes_Variant2[];
// Original: arm9/main @ 0x020852A4; symbol: func_020852a4; size: 0x74.
extern "C" int CharacterState_CountActiveMappedModifierBit14(char* p){int count;int i=0;count=0;int entry;while((entry=CharacterStateCountActiveMappedModifierBit14_UnknownRoleInitializedBytes[i*2])!=-1){if(*(short*)(p+CharacterStateCountActiveMappedModifierBit14_UnknownRoleInitializedBytes_Variant2[i*2]*32+0x1ac)>0 && ((*(unsigned*)(p+entry*44+0x2f4)<<17)>>31))++count;++i;}return count;}

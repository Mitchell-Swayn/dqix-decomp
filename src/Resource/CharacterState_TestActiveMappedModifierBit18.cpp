#include <globaldefs.h>
#include <Resource/Script.h>
ARM
// Original data: arm9/main @ 0x20e8b90; symbol: data_020e8b90.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00.
// Observed span: 1 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x20e8b91; symbol: data_020e8b91.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 08010002090307040505010606070affff0008010002090307040505010606070affff.
// Observed span: 35 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" signed char CharacterStateTestActiveMappedModifierBit18_UnknownRoleInitializedBytes_Variant2[];extern "C" signed char CharacterStateTestActiveMappedModifierBit18_UnknownRoleInitializedBytes[];
// Original: arm9/main @ 0x02085474; symbol: func_02085474; size: 0x74.
extern "C" int CharacterState_TestActiveMappedModifierBit18(unsigned char* p){int count=0;for(int i=0;CharacterStateTestActiveMappedModifierBit18_UnknownRoleInitializedBytes[i*2]!=-1;i++){int index=CharacterStateTestActiveMappedModifierBit18_UnknownRoleInitializedBytes[i*2];int check=CharacterStateTestActiveMappedModifierBit18_UnknownRoleInitializedBytes_Variant2[i*2];if(*(short*)(p+check*32+0x1ac)>0&&((*(unsigned*)(p+index*44+0x2f4)<<13)>>31)){return 1;}}return count;}

#include <globaldefs.h>
#include <Resource/Script.h>
ARM
// Original data: arm9/main @ 0x20e8b12; symbol: data_020e8b12.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00.
// Observed span: 1 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x20e8b13; symbol: data_020e8b13.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 08010002090307040505010606070affff.
// Observed span: 17 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" signed char CharacterStateTestActiveMappedModifierBit22_UnknownRoleInitializedBytes_Variant2[];extern "C" signed char CharacterStateTestActiveMappedModifierBit22_UnknownRoleInitializedBytes[];
// Original: arm9/main @ 0x020855D0; symbol: func_020855d0; size: 0x74.
extern "C" int CharacterState_TestActiveMappedModifierBit22(unsigned char* p){int count=0;for(int i=0;CharacterStateTestActiveMappedModifierBit22_UnknownRoleInitializedBytes[i*2]!=-1;i++){int index=CharacterStateTestActiveMappedModifierBit22_UnknownRoleInitializedBytes[i*2];int check=CharacterStateTestActiveMappedModifierBit22_UnknownRoleInitializedBytes_Variant2[i*2];if(*(short*)(p+check*32+0x1ac)>0&&((*(unsigned*)(p+index*44+0x2f4)<<9)>>31)){return 1;}}return count;}

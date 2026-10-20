#include <globaldefs.h>

ARM
#pragma always_inline on
extern "C" {
// Original data: arm9/main @ 0x20e8bb4; symbol: data_020e8bb4.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00.
// Observed span: 1 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x20e8bb5; symbol: data_020e8bb5.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 08010002090307040505010606070affff0008010002090307040505010606070affff.
// Observed span: 35 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern signed char CharacterStateTestActiveMappedModifierBit20_UnknownRoleInitializedBytes[],CharacterStateTestActiveMappedModifierBit20_UnknownRoleInitializedBytes_Variant2[];
struct Flags { unsigned first:20;unsigned active:1;unsigned rest:11; };
struct Entry {signed char index,pad;};
static inline int SearchActiveEntry(unsigned char *p,const Entry *first,int i,const Entry *second) {
    int index;
    while((index=second[i].index) != -1) {
        if(*(short *)(p+0x1ac+first[i].index*32)>0 && ((Flags *)(p+0x2f4+index*44))->active)return 1;
        i++;
    }
    return 0;
}
// Original: arm9/main @ 0x020854E8; symbol: func_020854e8; size: 0x74.
int CharacterState_TestActiveMappedModifierBit20(unsigned char *p) {
    return SearchActiveEntry(p,(Entry *)CharacterStateTestActiveMappedModifierBit20_UnknownRoleInitializedBytes_Variant2,0,(Entry *)CharacterStateTestActiveMappedModifierBit20_UnknownRoleInitializedBytes);
}
}

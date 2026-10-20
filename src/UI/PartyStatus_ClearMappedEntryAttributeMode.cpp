#include <globaldefs.h>
ARM
#pragma optimization_level 4
// Original data: arm9/main @ 0x20e7039; symbol: data_020e7039.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 05060708ff.
// Observed span: 5 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" const signed char PartyStatusClearMappedEntryAttributeMode_UnknownRoleInitializedBytes[];
extern "C" void Graphics_SetCellObjectMode(void *, void *, int);
// Original: arm9/main @ 0x02026EBC; symbol: func_02026ebc; size: 0x4C.
extern "C" void PartyStatus_ClearMappedEntryAttributeMode(void *object) {
    unsigned char i;
    for (i = 0; PartyStatusClearMappedEntryAttributeMode_UnknownRoleInitializedBytes[i] >= 0; i++)
        Graphics_SetCellObjectMode((char *)object + 0x94, (char *)object + 0xe8 + PartyStatusClearMappedEntryAttributeMode_UnknownRoleInitializedBytes[i] * 0x28, 0);
}

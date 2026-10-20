#include "Graphics/VRAMAllocations.h"
#include "Graphics/VRAMImagePool.h"

// Original data: arm9/main @ 0x20f1ef8; symbol: data_020f1ef8.
// Contains original relocated data addresses. Referenced targets and raw storage values are recorded; semantic role and record layout remain unresolved.
// Initial values: hex 141f0f025c1f0f02741f0f025c1f0f02141f0f02441f0f022c1f0f02.
// Observed span: 28 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern Struct_020f1f14* NNSGfdAllocFrmTexVram_UnknownRoleDataReferences[7];
extern "C" unsigned int NNS_GfdAllocFrmTexVram(unsigned int, unsigned int, unsigned int);

#pragma dont_inline on
// Original: arm9/main @ 0x020BB444; symbol: _Z28SetTextureImageVRAMPoolOrderiiiii; size: 0x48.
void SetTextureImageVRAMPoolOrder(int first, int second, int third, int fourth, int fifth)
{
    NNSGfdAllocFrmTexVram_UnknownRoleDataReferences[2] = &ResetTextureImageVRAM_UnknownRoleInitializedBytes[first];
    NNSGfdAllocFrmTexVram_UnknownRoleDataReferences[3] = &ResetTextureImageVRAM_UnknownRoleInitializedBytes[second];
    NNSGfdAllocFrmTexVram_UnknownRoleDataReferences[4] = &ResetTextureImageVRAM_UnknownRoleInitializedBytes[third];
    NNSGfdAllocFrmTexVram_UnknownRoleDataReferences[5] = &ResetTextureImageVRAM_UnknownRoleInitializedBytes[fourth];
    NNSGfdAllocFrmTexVram_UnknownRoleDataReferences[6] = &ResetTextureImageVRAM_UnknownRoleInitializedBytes[fifth];
}

// Original: arm9/main @ 0x020BB48C; symbol: _Z26InitializeTextureImageVRAMjb; size: 0x88.
void InitializeTextureImageVRAM(unsigned int banks, bool setDefault)
{
    if (banks <= 2)
        SetTextureImageVRAMPoolOrder(4, 3, 2, 0, 1);
    else
        SetTextureImageVRAMPoolOrder(4, 3, 0, 2, 1);
    ResetTextureImageVRAM_UnknownRoleZeroInitializedStorage.bankCount = banks;
    ResetTextureImageVRAM();
    if (setDefault)
    {
        InitializeTextureImageVRAM_UnknownRoleProcedureReferenceRecords = NNS_GfdAllocFrmTexVram;
        InitializeTextureImageVRAM_UnknownRoleProcedureReferenceRecords_Variant2 = FreeTextureImageVRAM;
    }
}

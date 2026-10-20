#include "Graphics/VRAMAllocations.h"
#include <globaldefs.h>

struct TexturePaletteVRAMAllocator
{
    unsigned int freeStart_;
    unsigned int freeEnd_;
    unsigned int size;
};
TexturePaletteVRAMAllocator AllocateTexturePaletteVRAM_UnknownRoleZeroInitializedStorage;

#pragma optimize_for_size off
#pragma dont_inline on

// Original: arm9/main @ 0x020BB780; symbol: _Z28InitializeTexturePaletteVRAMjb; size: 0x4C.
void InitializeTexturePaletteVRAM(unsigned int size, bool setDefault)
{
    AllocateTexturePaletteVRAM_UnknownRoleZeroInitializedStorage.size = size;
    ResetTexturePaletteVRAM();
    if (setDefault)
    {
        InitializeTexturePaletteVRAM_UnknownRoleProcedureReferenceRecords = AllocateTexturePaletteVRAM;
        InitializeTexturePaletteVRAM_UnknownRoleProcedureReferenceRecords_Variant2 = FreeTexturePaletteVRAM;
    }
}

// The explicit branches preserve the original SDK allocator's control flow.
// Original: arm9/main @ 0x020BB7CC; symbol: AllocateTexturePaletteVRAM; size: 0x13C.
unsigned int AllocateTexturePaletteVRAM(unsigned int amount, unsigned int eightByteAlign, unsigned int direction)
{  
    unsigned int chosenPosition = 0;
    unsigned int frontPadding;
    unsigned int alignedSize;
    unsigned int totalSpaceNeeded;

    if (amount == 0)
        alignedSize = 8;
    else
        alignedSize = (amount + 7) & ~7;

    // The shared allocation-key format imposes a 512 KiB size limit.
    if (alignedSize >= 0x7fff8)
        return 0;

    bool success;
    
    if (direction == 1)
    {
        unsigned int start = AllocateTexturePaletteVRAM_UnknownRoleZeroInitializedStorage.freeStart_;
        if (eightByteAlign)
            frontPadding = (8 - (start & 7)) & 7;
        else
            frontPadding = (16 - (start & 15)) & 15;
        
        totalSpaceNeeded = alignedSize + frontPadding;
        unsigned newFreeStart;
        if (AllocateTexturePaletteVRAM_UnknownRoleZeroInitializedStorage.freeEnd_ - start < totalSpaceNeeded)
            goto lab_a4;
        newFreeStart = start + totalSpaceNeeded;
        if (!eightByteAlign)
            goto lab_88;
        if (newFreeStart > 0x10000)
        {
            success = false;
            goto end;
        }
    lab_88:
        success = true;
        chosenPosition = AllocateTexturePaletteVRAM_UnknownRoleZeroInitializedStorage.freeStart_ + frontPadding;
        AllocateTexturePaletteVRAM_UnknownRoleZeroInitializedStorage.freeStart_ += totalSpaceNeeded;
        goto end;
    lab_a4:
        success = false;
    }
    else
    {
        if (AllocateTexturePaletteVRAM_UnknownRoleZeroInitializedStorage.freeEnd_ >= alignedSize)
        {
            if (!eightByteAlign)
                frontPadding = (AllocateTexturePaletteVRAM_UnknownRoleZeroInitializedStorage.freeEnd_ - alignedSize) & 15;
            else
                frontPadding = (AllocateTexturePaletteVRAM_UnknownRoleZeroInitializedStorage.freeEnd_ - alignedSize) & 7;

            int totalSpaceUsed = alignedSize + frontPadding;

            if (AllocateTexturePaletteVRAM_UnknownRoleZeroInitializedStorage.freeEnd_ - AllocateTexturePaletteVRAM_UnknownRoleZeroInitializedStorage.freeStart_ >= alignedSize + frontPadding)
            {
                if (eightByteAlign && AllocateTexturePaletteVRAM_UnknownRoleZeroInitializedStorage.freeEnd_ > 0x10000)
                {
                    success = false;
                    goto end;
                }
                else
                {
                    success = true;
                    chosenPosition = *(volatile unsigned int*)&AllocateTexturePaletteVRAM_UnknownRoleZeroInitializedStorage.freeEnd_ - totalSpaceUsed;
                    AllocateTexturePaletteVRAM_UnknownRoleZeroInitializedStorage.freeEnd_ = chosenPosition;
                    goto end;
                }
            }
        }
        success = false;
    }
end:
    if (!success)
        return 0;

    int mask = (alignedSize >> 3) << 16 | ((chosenPosition << 13) >> 16);
    return mask;
}
// Original successful no-op: the frame allocator releases storage via reset
// or state restoration rather than freeing individual keys.
// Original: arm9/main @ 0x020BB908; symbol: FreeTexturePaletteVRAM; size: 0x8.
extern "C" int FreeTexturePaletteVRAM(unsigned int key) { return 0; }

// Original: arm9/main @ 0x020BB910; symbol: _Z27SaveTexturePaletteVRAMStateP23TexturePaletteVRAMState; size: 0x1C.
void SaveTexturePaletteVRAMState(TexturePaletteVRAMState* state)
{
    state->freeStart = AllocateTexturePaletteVRAM_UnknownRoleZeroInitializedStorage.freeStart_;
    state->freeEnd = AllocateTexturePaletteVRAM_UnknownRoleZeroInitializedStorage.freeEnd_;
}

// Original: arm9/main @ 0x020BB92C; symbol: _Z30RestoreTexturePaletteVRAMStatePK23TexturePaletteVRAMState; size: 0x1C.
void RestoreTexturePaletteVRAMState(const TexturePaletteVRAMState* state)
{
    AllocateTexturePaletteVRAM_UnknownRoleZeroInitializedStorage.freeStart_ = state->freeStart;
    AllocateTexturePaletteVRAM_UnknownRoleZeroInitializedStorage.freeEnd_ = state->freeEnd;
}

// Original: arm9/main @ 0x020BB948; symbol: _Z23ResetTexturePaletteVRAMv; size: 0x1C.
void ResetTexturePaletteVRAM()
{
    AllocateTexturePaletteVRAM_UnknownRoleZeroInitializedStorage.freeStart_ = 0;
    AllocateTexturePaletteVRAM_UnknownRoleZeroInitializedStorage.freeEnd_ = AllocateTexturePaletteVRAM_UnknownRoleZeroInitializedStorage.size;
}

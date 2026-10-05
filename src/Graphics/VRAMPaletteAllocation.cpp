#include "Graphics/VRAMAllocations.h"
#include <globaldefs.h>

struct TexturePaletteVRAMAllocator
{
    unsigned int freeStart_;
    unsigned int freeEnd_;
    unsigned int size;
};
TexturePaletteVRAMAllocator data_0210cf88;

#pragma optimize_for_size off
#pragma dont_inline on

void InitializeTexturePaletteVRAM(unsigned int size, bool setDefault)
{
    data_0210cf88.size = size;
    ResetTexturePaletteVRAM();
    if (setDefault)
    {
        data_020f1ef0 = AllocateTexturePaletteVRAM;
        data_020f1ef4 = FreeTexturePaletteVRAM;
    }
}

// The explicit branches preserve the original SDK allocator's control flow.
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
        unsigned int start = data_0210cf88.freeStart_;
        if (eightByteAlign)
            frontPadding = (8 - (start & 7)) & 7;
        else
            frontPadding = (16 - (start & 15)) & 15;
        
        totalSpaceNeeded = alignedSize + frontPadding;
        unsigned newFreeStart;
        if (data_0210cf88.freeEnd_ - start < totalSpaceNeeded)
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
        chosenPosition = data_0210cf88.freeStart_ + frontPadding;
        data_0210cf88.freeStart_ += totalSpaceNeeded;
        goto end;
    lab_a4:
        success = false;
    }
    else
    {
        if (data_0210cf88.freeEnd_ >= alignedSize)
        {
            if (!eightByteAlign)
                frontPadding = (data_0210cf88.freeEnd_ - alignedSize) & 15;
            else
                frontPadding = (data_0210cf88.freeEnd_ - alignedSize) & 7;

            int totalSpaceUsed = alignedSize + frontPadding;

            if (data_0210cf88.freeEnd_ - data_0210cf88.freeStart_ >= alignedSize + frontPadding)
            {
                if (eightByteAlign && data_0210cf88.freeEnd_ > 0x10000)
                {
                    success = false;
                    goto end;
                }
                else
                {
                    success = true;
                    chosenPosition = *(volatile unsigned int*)&data_0210cf88.freeEnd_ - totalSpaceUsed;
                    data_0210cf88.freeEnd_ = chosenPosition;
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
extern "C" int FreeTexturePaletteVRAM(unsigned int key) { return 0; }

void SaveTexturePaletteVRAMState(TexturePaletteVRAMState* state)
{
    state->freeStart = data_0210cf88.freeStart_;
    state->freeEnd = data_0210cf88.freeEnd_;
}

void RestoreTexturePaletteVRAMState(const TexturePaletteVRAMState* state)
{
    data_0210cf88.freeStart_ = state->freeStart;
    data_0210cf88.freeEnd_ = state->freeEnd;
}

void ResetTexturePaletteVRAM()
{
    data_0210cf88.freeStart_ = 0;
    data_0210cf88.freeEnd_ = data_0210cf88.size;
}

#include "Graphics/VRAMAllocations.h"
#include <globaldefs.h>

#include "Graphics/VRAMImagePool.h"

// Original data: arm9/main @ 0x20f1ef8; symbol: data_020f1ef8.
// Contains original relocated data addresses. Referenced targets and raw storage values are recorded; semantic role and record layout remain unresolved.
// Initial values: hex 141f0f025c1f0f02741f0f025c1f0f02141f0f02441f0f022c1f0f02.
// Observed span: 28 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern Struct_020f1f14* NNSGfdAllocFrmTexVram_UnknownRoleDataReferences[7];
// points to elements in the above array.
// Initially in the order ([4], [3], [0], [2], [1]).
// No idea why


struct Struct_0210cf88
{
    unsigned int freeStart_;
    unsigned int freeEnd_;
// Original data: arm9/main @ 0x210cf88; symbol: data_0210cf88.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
} extern AllocateTexturePaletteVRAM_UnknownRoleZeroInitializedStorage;

#pragma optimize_for_size off

// I wasn't able to get this to match, so the file isn't delinked yet
extern "C" unsigned int MaybeAllocateTextureImageVRAM(unsigned int amount, bool paired, unsigned int defaultOffset)
{
    unsigned int chosenOffset = defaultOffset;
    unsigned int alignedSize = amount + 0xf;
    if (amount == 0)
        alignedSize = 0x10;
    else
        alignedSize = (amount + 0xf) & ~0xf;

    if (alignedSize >= 0x7fff0)
        return 0;

    bool success;
    if (paired)
    {
        int pass = 0;
        do
        {
            unsigned int start;
            Struct_020f1f14* secondaryPool;
            Struct_020f1f14* primaryPool;
            
            primaryPool = NNSGfdAllocFrmTexVram_UnknownRoleDataReferences[pass];
            
            if (primaryPool->maybeIsUsable_ == 0)
                continue;
                
            start = primaryPool->freeStart_;
            if (primaryPool->freeEnd_ - start < alignedSize)
                continue;
            
            switch (primaryPool->relatedToPairing_)
            {
            case 0:
                secondaryPool = &ResetTextureImageVRAM_UnknownRoleInitializedBytes[1];
                break;
            case 3:
                secondaryPool = &ResetTextureImageVRAM_UnknownRoleInitializedBytes[2];
                break;
            default:
                secondaryPool = NULL;
                break;
            }
            if (secondaryPool->maybeIsUsable_ == 0)
                continue;
            if (secondaryPool->freeEnd_ - secondaryPool->freeStart_ >= (alignedSize >> 1))
            {
                primaryPool->freeStart_ += alignedSize;
                success = true;
                secondaryPool->freeStart_ += (alignedSize >> 1);
                chosenOffset = start + primaryPool->poolBase_;
                goto end;
            }
        } while (pass++, pass < 2);
        success = false;
    }
    else
    {
        int pass = 0;
        do
        {
            Struct_020f1f14* pool;
            pool = NNSGfdAllocFrmTexVram_UnknownRoleDataReferences[pass + 2];
            if (pool->maybeIsUsable_ == 0)
                continue;
            if (pool->freeEnd_ - pool->freeStart_ >= alignedSize)
            {
                success = true;
                pool->freeEnd_ = (volatile unsigned int&)pool->freeEnd_ - alignedSize;
                chosenOffset = pool->freeEnd_ + pool->poolBase_;
                goto end;
            }
        } while (pass++, pass < 5);
        success = false;
    }

end:
    if (!success)
        return 0;

    return ((alignedSize >> 4) << 16) | ((chosenOffset << 13) >> 16) | (paired << 31);
}


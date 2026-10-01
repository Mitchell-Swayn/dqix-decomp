#include "Graphics/VRAMAllocations.h"
#include <globaldefs.h>

#include "Graphics/VRAMImagePool.h"

extern Struct_020f1f14* data_020f1ef8[2];
// points to elements in the above array.
// Initially in the order ([4], [3], [0], [2], [1]).
// No idea why
extern Struct_020f1f14* data_020f1f00[5];

struct Struct_0210cf88
{
    unsigned int freeStart_;
    unsigned int freeEnd_;
} extern data_0210cf88;

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
            
            primaryPool = data_020f1ef8[pass];
            
            if (primaryPool->maybeIsUsable_ == 0)
                continue;
                
            start = primaryPool->freeStart_;
            if (primaryPool->freeEnd_ - start < alignedSize)
                continue;
            
            switch (primaryPool->relatedToPairing_)
            {
            case 0:
                secondaryPool = &data_020f1f14[1];
                break;
            case 3:
                secondaryPool = &data_020f1f14[2];
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
            pool = data_020f1f00[pass];
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


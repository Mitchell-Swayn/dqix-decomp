#include "Graphics/VRAMAllocations.h"
#include <globaldefs.h>

#include "Graphics/VRAMImagePool.h"


void ResetTextureImageVRAM()
{
    int index;
    Struct_020f1f14* pool;
    int activePools = data_0210cf84.bankCount;
    if ((unsigned int)activePools > 1)
        ++activePools;
    index = 0;
    pool = data_020f1f14;
    do
    {
        if (index < activePools)
            pool->maybeIsUsable_ = 1;
        else
            pool->maybeIsUsable_ = 0;
        if (pool->halfSize_)
        {
            pool->freeStart_ = 0;
            pool->freeEnd_ = 0x10000;
        }
        else
        {
            pool->freeStart_ = 0;
            pool->freeEnd_ = 0x20000;
        }
        ++pool;
    } while (++index < 5);
}

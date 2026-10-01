#include "Graphics/VRAMAllocations.h"
#include <globaldefs.h>

#include "Graphics/VRAMImagePool.h"

// The stack allocator releases images only by restoring or resetting state.
extern "C" int FreeTextureImageVRAM(unsigned int /*key*/)
{
    return 0;
}

void SaveTextureImageVRAMState(unsigned int* state)
{
    int index = 0;
    Struct_020f1f14* pool = data_020f1f14;
    int offset = 0;
    do
    {
        state[offset] = pool->freeStart_;
        (&state[offset])[1] = pool->freeEnd_;
        ++pool;
        offset += 2;
    } while (++index < 5);
}

void RestoreTextureImageVRAMState(const unsigned int* state)
{
    int index = 0;
    int offset = 0;
    Struct_020f1f14* pool = data_020f1f14;
    do
    {
        pool->freeStart_ = state[offset];
        pool->freeEnd_ = (&state[offset])[1];
        offset += 2;
        ++pool;
    } while (++index < 5);
}

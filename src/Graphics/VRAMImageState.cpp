#include "Graphics/VRAMAllocations.h"
#include <globaldefs.h>

struct Struct_020f1f14
{
    unsigned int freeStart_;
    unsigned int freeEnd_;
    unsigned int maybeIsUsable_;
    char unk_c[4];
    unsigned short relatedToPairing_;
    char unk_12[2];
    unsigned int poolBase_;
} extern data_020f1f14[5];

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

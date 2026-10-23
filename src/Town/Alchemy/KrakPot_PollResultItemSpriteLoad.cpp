#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
ARM

// Original callee: arm9/main @ 0x02076080; consumes a sprite payload,
// allocation arena, loaded SPR bytes and their byte count; returns a status.
extern "C" int Sprite_LoadCellsPalettesAndAnimationTables(void*, SafeAllocator*, void*, unsigned);

// Original: arm9/ov006 @ 0x0215FECC; symbol: func_ov006_0215fecc; size: 0x88.
// Consumes a result-item SPR task once its loader status is nonzero.
extern "C" int KrakPot_PollResultItemSpriteLoad(void* object)
{
    unsigned char* self = (unsigned char*)object;
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (!loader->GetTaskStatus(*(int*)(self + 0x428)))
        return 0;

    unsigned char* resourceOwner = *(unsigned char**)(self + 0xc);
    SafeAllocator* allocator = (SafeAllocator*)(resourceOwner + 0xb4);
    allocator->Reset();
    void* file = 0;
    unsigned length = 0;
    loader->GetLoadedFileByID(*(int*)(self + 0x428), &file, &length);
    Sprite_LoadCellsPalettesAndAnimationTables(self + 0x3b8, allocator, file, length);
    loader->RemoveTask(*(int*)(self + 0x428));
    *(int*)(self + 0x428) = -1;
    return 1;
}

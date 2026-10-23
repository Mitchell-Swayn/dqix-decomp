#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
ARM

struct KrakPotPreviewSpriteLayout {
    unsigned char payload[0x70];
    int task;
    short item, x, y;
    unsigned char pending;
};

extern "C" int Sprite_LoadCellsPalettesAndAnimationTables(void*, SafeAllocator*, void*, unsigned);

// Original: arm9/ov006 @ 0x02156FDC; symbol: func_ov006_02156fdc; size: 0xD8.
// Completes pending preview SPR loads in their corresponding allocator slots.
extern "C" void KrakPot_PollItemPreviewSpriteLoads(void* object)
{
    unsigned char* self = (unsigned char*)object;
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    KrakPotPreviewSpriteLayout* sprite = (KrakPotPreviewSpriteLayout*)(self + 0x894);
    unsigned char i = 0;
    void* file;
    unsigned length;
    for (; i < 4; ++sprite, ++i) {
        if (sprite->pending) {
            if (loader->GetTaskStatus(sprite->task)) {
                loader->GetLoadedFileByID(sprite->task, &file, &length);
                if (file) {
                    unsigned offset = i * 20;
                    ((SafeAllocator*)(self + 0xa84 + offset))->Reset();
                    Sprite_LoadCellsPalettesAndAnimationTables(sprite, (SafeAllocator*)(self + 0xa84 + offset), file, length);
                }
                loader->RemoveTask(sprite->task);
                sprite->task = -1;
                sprite->pending = 0;
            }
            sprite->x = 0x6f;
            sprite->y = -26;
        }
    }
}

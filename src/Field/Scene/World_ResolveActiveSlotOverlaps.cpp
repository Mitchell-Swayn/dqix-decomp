#include <globaldefs.h>
ARM
struct GameResources;
extern "C" int GameResources_GetMaskedPrimaryFlags(GameResources*,unsigned);
extern "C" void *ActorPool_GetGlobalInstance();
extern "C" unsigned int *ActorPool_GetActiveSlot(unsigned int **p,unsigned int i);
extern "C" unsigned short* Actor_GetPlacementDescriptor(void*);
extern "C" GameResources* GameResources_GetInstance();
extern "C" int World_ResolveHorizontalObjectOverlap(void*,void*,void*);
// Original: arm9/ov017 @ 0x0218DF50; symbol: func_ov017_0218df50; size: 0x88.
extern "C" int World_ResolveActiveSlotOverlaps(void *self, void *arg) {
    int found = 0;
    if (!GameResources_GetMaskedPrimaryFlags(GameResources_GetInstance(), 0x100)) {
        unsigned **table = (unsigned**)ActorPool_GetGlobalInstance();
        for (int i = 0; i < 32; i++) {
            unsigned *entry = ActorPool_GetActiveSlot(table, i);
            if (!entry) continue;
            if (((unsigned char*)Actor_GetPlacementDescriptor(entry))[2] == 1) continue;
            if (World_ResolveHorizontalObjectOverlap(self, entry, arg)) found = 1;
        }
    }
    return found;
}

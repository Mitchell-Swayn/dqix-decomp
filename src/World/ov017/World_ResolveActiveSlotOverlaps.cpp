#include <globaldefs.h>
ARM
struct GameResources;
extern "C" int ReadMaskedWord(GameResources*,unsigned);
extern "C" void *Object_GetGlobalThirtyTwoEntryContainer();
extern "C" unsigned int *GetBoundedSlotUnlessFlag8000(unsigned int **p,unsigned int i);
extern "C" unsigned short* ReadWordFieldAtOffset8(void*);
extern "C" GameResources* GameResources_GetInstance();
extern "C" int World_ResolveHorizontalObjectOverlap(void*,void*,void*);
// Original: arm9/ov017 @ 0x0218DF50; symbol: func_ov017_0218df50; size: 0x88.
extern "C" int World_ResolveActiveSlotOverlaps(void *self, void *arg) {
    int found = 0;
    if (!ReadMaskedWord(GameResources_GetInstance(), 0x100)) {
        unsigned **table = (unsigned**)Object_GetGlobalThirtyTwoEntryContainer();
        for (int i = 0; i < 32; i++) {
            unsigned *entry = GetBoundedSlotUnlessFlag8000(table, i);
            if (!entry) continue;
            if (((unsigned char*)ReadWordFieldAtOffset8(entry))[2] == 1) continue;
            if (World_ResolveHorizontalObjectOverlap(self, entry, arg)) found = 1;
        }
    }
    return found;
}

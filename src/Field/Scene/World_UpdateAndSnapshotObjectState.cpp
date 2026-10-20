#include <globaldefs.h>
ARM

extern "C" void *Zone3D_GetMainInstance(void);
extern "C" void ResourceLoader_ResetPresentationOwner(int object);
extern "C" bool _ZN13ZoneState084018IsValueInRangeC3b5Ei(void *, int);
extern "C" void TextureVRAM_SnapshotAllocationBounds(char *p);

// Original: arm9/ov017 @ 0x0218D5C8; symbol: func_ov017_0218d5c8; size: 0x50.
extern "C" void World_UpdateAndSnapshotObjectState(char *self) {
    int pending = *(int *)(self + 0x4498);
    if (pending != 0) {
        ResourceLoader_ResetPresentationOwner(pending);
    }
    char *global = (char *)Zone3D_GetMainInstance();
    int value = *(unsigned short *)global;
    bool inRange = _ZN13ZoneState084018IsValueInRangeC3b5Ei(global + 0x840, value);
    char *snapshot = self + 0x2cc;
    if (inRange) snapshot += 0x930;
    else snapshot += 0xc40;
    TextureVRAM_SnapshotAllocationBounds(snapshot);
    *(int *)(self + 0x4498) = 0;
}

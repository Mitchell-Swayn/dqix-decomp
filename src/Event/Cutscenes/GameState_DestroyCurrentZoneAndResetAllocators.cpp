#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" unsigned char* Zone3D_GetMainInstance();
extern "C" void* GameState_GetFieldAddress5CA4(void*);
extern "C" void _ZN6Zone3D18ResetZoneResourcesEb(void*,int);
extern "C" void _ZN13SafeAllocator7DestroyEv(void*);
extern "C" void _ZN13SafeAllocator5ResetEv(void*);
extern "C" void TextureVRAM_SnapshotAllocationBounds(void*);
// Original: arm9/ov001 @ 0x02163C60; symbol: GameState_DestroyCurrentZoneAndResetAllocators; size: 0x6C.
// Resets current Zone3D resources, destroys its embedded allocator when present, clears GameState field 0x5ca4, resets the global allocator, snapshots the volatile pair, and returns success.
extern "C" int GameState_DestroyCurrentZoneAndResetAllocators(void) {
    void* game = _ZN9GameState11GetInstanceEv();
    unsigned char* global = Zone3D_GetMainInstance();
    void** currentZoneField = (void**)GameState_GetFieldAddress5CA4(game);
    void* currentZone = *currentZoneField;
    if (currentZone != 0) {
        _ZN6Zone3D18ResetZoneResourcesEb(currentZone, 1);
        void* embedded = *(void**)((char*)currentZone + 0x4c);
        if (embedded != 0)
            _ZN13SafeAllocator7DestroyEv(embedded);
    }
    *currentZoneField = 0;
    void* allocator = *(void* volatile*)(global + 0x4c);
    void* snapshot = *(void* volatile*)(global + 0x50);
    _ZN13SafeAllocator5ResetEv(allocator);
    TextureVRAM_SnapshotAllocationBounds(snapshot);
    return 1;
}

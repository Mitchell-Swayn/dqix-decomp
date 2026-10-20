#include <globaldefs.h>

extern "C" {
void* _ZN16BackgroundLoader11GetInstanceEv();
void _ZN16BackgroundLoader10RemoveTaskEi(void*, int);
void Selection_ReleaseAttachedDisplayResources(unsigned char*);
void Graphics_ResetLoadedLayerResources(unsigned char*);
void* _ZNK13SafeAllocator18GetSignedAllocatorEv(void*);
void _ZN13SafeAllocator7DestroyEv(void*);
void BattleMenu_ReleaseMemberTextAndResetCommand(void*);
void BattleMenu_RestoreSubDisplayResources(unsigned char*);
// Original data: arm9/ov000 @ 0x2184288; symbol: data_ov000_02184288.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov000.md.
extern unsigned BattleHudUpdateSlotHighlightPalette_UnknownRoleZeroInitializedStorage[];
}
// Original: arm9/ov000 @ 0x02172720; symbol: func_ov000_02172720; size: 0x130.
// Removes the active load task and releases the object's owned records and allocators.
extern "C" ARM void GameState_CleanupOwnedResourcesAndResetRecords(unsigned char* self) {
    if (*(int*)(self + 0x90c) >= 0) {
        void* loader = _ZN16BackgroundLoader11GetInstanceEv();
        _ZN16BackgroundLoader10RemoveTaskEi(loader, *(int*)(self + 0x90c));
        *(int*)(self + 0x90c) = -1;
    }

    Selection_ReleaseAttachedDisplayResources(self + 0x188);
    Graphics_ResetLoadedLayerResources(self + 0x8c4);
    Graphics_ResetLoadedLayerResources(self + 0x8a4);

    void* allocators[7] = {
        self + 0x1aa0,
        self + 0x1ab4,
        self + 0x1ac8,
        self + 0x1adc,
        self + 0x1af8,
        self + 0x1a78,
        self + 0x1a8c
    };
    for (int i = 0; i < 7; ++i) {
        void* allocator = allocators[i];
        if (_ZNK13SafeAllocator18GetSignedAllocatorEv(allocator)) {
            _ZN13SafeAllocator7DestroyEv(allocator);
        }
    }

    for (int i = 0; i < 4; ++i) {
        BattleMenu_ReleaseMemberTextAndResetCommand(self + 0x958 + i * 0x448);
    }
    BattleMenu_RestoreSubDisplayResources(self);
    *(unsigned short*)(self + 0x1d72) &= 0x40;
    BattleHudUpdateSlotHighlightPalette_UnknownRoleZeroInitializedStorage[2] = 0;
}

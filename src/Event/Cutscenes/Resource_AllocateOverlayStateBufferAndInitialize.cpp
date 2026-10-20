#include <globaldefs.h>
ARM

extern "C" void OverlayLoader_PushSecondarySelection(unsigned int index);
extern "C" void *GameResources_GetInstance(void);
extern "C" char *_ZN13SafeAllocator8AllocateEj(unsigned int allocator, unsigned int size);
extern "C" void StaffRoll_InitializeDisplayState(void *state);
extern "C" void StaffRoll_AllocateTileBufferAndScriptArena(void *state, void *data);
// Original data: arm9/ov001 @ 0x21658b8; symbol: data_ov001_021658b8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" unsigned int EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage;

// Original: arm9/ov001 @ 0x021619BC; symbol: func_ov001_021619bc; size: 0x60.
extern "C" int Resource_AllocateOverlayStateBufferAndInitialize(void) {
    OverlayLoader_PushSecondarySelection(5);
    char *resources = (char *)GameResources_GetInstance();
    char *list = *(char **)(resources + 0x3734);
    char *buffer = _ZN13SafeAllocator8AllocateEj(EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage, 0x84);
    if (buffer == 0) {
        return 0;
    }
    *(char **)(list + 0x160) = buffer;
    list[0x164] = 0;
    StaffRoll_InitializeDisplayState(buffer);
    StaffRoll_AllocateTileBufferAndScriptArena(buffer, (void *)EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage);
    return 1;
}

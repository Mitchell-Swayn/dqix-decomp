#include <globaldefs.h>
ARM
extern "C" void OverlayLoader_PushSecondarySelection(unsigned int index);
extern "C" void *GameResources_GetInstance();
extern "C" void GameResources_SetPrimaryFlags(unsigned int *word, unsigned int mask);
extern "C" void StaffRoll_InitializeAndScheduleScanlineAlarm(void *a);
// Original data: arm9/ov001 @ 0x21658b8; symbol: data_ov001_021658b8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" volatile unsigned int EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov001 @ 0x0216224C; symbol: OverlayLoader_PushSlotFiveAndSetResourceMask1000; size: 0x30.
// Pushes mapped overlay slot 5, sets resource mask 0x1000, calls the overlay 028 helper with the mapped word, and returns one.
extern "C" int OverlayLoader_PushSlotFiveAndSetResourceMask1000(void) {
    OverlayLoader_PushSecondarySelection(5);
    GameResources_SetPrimaryFlags((unsigned int *)GameResources_GetInstance(), 0x1000);
    StaffRoll_InitializeAndScheduleScanlineAlarm((void *)EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage);
    return 1;
}

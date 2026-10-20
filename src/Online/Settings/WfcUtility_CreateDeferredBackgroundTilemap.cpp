#include <globaldefs.h>
#include <Graphics/NSBXX/JACInternal.h>
ARM
extern "C" void MIi_CpuCopyFast(const void *, void *, unsigned int);
extern "C" void *Memory_AllocateZeroedBlock(unsigned int, unsigned int);
// Original data: arm9/ov031 @ 0x2290ce8; symbol: data_ov031_02290ce8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" void * volatile WfcUtilityDestroyDeferredBackgroundTilemap_UnknownRoleZeroInitializedStorage;
extern "C" void Overlay_LoadPendingBG2ScreenData(void);
extern "C" unsigned int WfcUtility_CreateTaskWithBorrowedContext(unsigned int, void (*)(void), unsigned int, unsigned int);
// Original: arm9/ov031 @ 0x02234EA8; symbol: func_ov031_02234ea8; size: 0x60.
extern "C" void WfcUtility_CreateDeferredBackgroundTilemap(void *source) {
    void *resource = Memory_AllocateZeroedBlock(0x608, 4);
    WfcUtilityDestroyDeferredBackgroundTilemap_UnknownRoleZeroInitializedStorage = resource;
    MIi_CpuCopyFast(source, (char *)resource + 4, 0x600);
    unsigned int handle = WfcUtility_CreateTaskWithBorrowedContext(1, Overlay_LoadPendingBG2ScreenData, 0, 0x78);
    *(unsigned int *)WfcUtilityDestroyDeferredBackgroundTilemap_UnknownRoleZeroInitializedStorage = handle;
}

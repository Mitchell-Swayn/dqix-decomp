#include <globaldefs.h>
ARM
#pragma force_active on
extern "C" void WfcUtility_FreeAllocationAndClearPointer(void **);
extern "C" void WfcUtility_RemoveTaskImmediately(unsigned, void *);
// Original data: arm9/ov031 @ 0x02290CE8; symbol: data_ov031_02290ce8.
// Initial value: null; mutable context pointer at runtime.
// The accessed field offsets are established by the original loads.
// Full data references: docs/data-symbols/ov031.md.
extern "C" void *WfcUtilityDestroyDeferredBackgroundTilemap_UnknownRoleZeroInitializedStorage;
// Separate C-linkage declarations preserve the original value/address literal entries.
namespace ContextStorageAddress { extern "C" void *WfcUtilityDestroyDeferredBackgroundTilemap_UnknownRoleZeroInitializedStorage; }
// Original: arm9/ov031 @ 0x02234F08; symbol: func_ov031_02234f08; size: 0x2C.
// Removes the deferred tilemap task and frees its context.
extern "C" void WfcUtility_DestroyDeferredBackgroundTilemap(void) {
    WfcUtility_RemoveTaskImmediately(1, *(void **)((char *)WfcUtilityDestroyDeferredBackgroundTilemap_UnknownRoleZeroInitializedStorage + 0x0));
    WfcUtility_FreeAllocationAndClearPointer(&ContextStorageAddress::WfcUtilityDestroyDeferredBackgroundTilemap_UnknownRoleZeroInitializedStorage);
}
#pragma force_active reset

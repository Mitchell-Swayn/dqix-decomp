#include <globaldefs.h>
ARM
#pragma force_active on
extern "C" void WfcUtility_FreeAllocationAndClearPointer(void **);
extern "C" void WfcUtility_RemoveTaskImmediately(unsigned, void *);
extern "C" void WfcUtility_ReleaseOamSprite(void *);
// Original data: arm9/ov031 @ 0x02250BA4; symbol: data_ov031_02250ba4.
// Initial value: null; mutable context pointer at runtime.
// The accessed field offsets are established by the original loads.
// Full data references: docs/data-symbols/ov031.md.
extern "C" void *WfcUtilityDestroyAnimatedStatusSprite_UnknownRoleZeroInitializedStorage;
// Separate C-linkage declarations preserve the original value/address literal entries.
namespace ContextStorageAddress { extern "C" void *WfcUtilityDestroyAnimatedStatusSprite_UnknownRoleZeroInitializedStorage; }
// Original: arm9/ov031 @ 0x02222BDC; symbol: func_ov031_02222bdc; size: 0x3C.
// Removes the animation task, releases its sprite, and frees its context.
extern "C" void WfcUtility_DestroyAnimatedStatusSprite(void) {
    WfcUtility_RemoveTaskImmediately(1, *(void **)((char *)WfcUtilityDestroyAnimatedStatusSprite_UnknownRoleZeroInitializedStorage + 0x0));
    WfcUtility_ReleaseOamSprite(*(void **)((char *)WfcUtilityDestroyAnimatedStatusSprite_UnknownRoleZeroInitializedStorage + 4));
    WfcUtility_FreeAllocationAndClearPointer(&ContextStorageAddress::WfcUtilityDestroyAnimatedStatusSprite_UnknownRoleZeroInitializedStorage);
}
#pragma force_active reset

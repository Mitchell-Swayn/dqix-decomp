#include <globaldefs.h>
ARM
#pragma force_active on
struct SlidingDialogResources {
    void* primary; void* secondary; void* elements[2]; void* inputOwner;
    unsigned char padding[8]; unsigned char kind;
};
extern "C" {
// Original data: arm9/ov031 @ 0x02290d10; symbol: data_ov031_02290d10; mutable dialog pointer, initially zero.
extern SlidingDialogResources* WfcUtilityDestroySlidingDialog_UnknownRoleZeroInitializedStorage;
// Original data: arm9/ov031 @ 0x02249394; symbol: data_ov031_02249394; per-kind element counts.
extern const unsigned char WfcUtilityCreateSlidingDialog_UnknownRoleInitializedBytes_Variant7[];
void Network_UnlinkNodeAndReleaseRecords(void*);
void Memory_UnlinkInputOwnerAndQueueReference(void*);
void WfcUtility_RequestTaskRemoval(unsigned,void*);
void WfcUtility_FreeAllocationAndClearPointer(void*);
}
namespace ContextStorageAddress { extern "C" SlidingDialogResources* WfcUtilityDestroySlidingDialog_UnknownRoleZeroInitializedStorage; }
// Original: arm9/ov031 @ 0x022385e4; symbol: func_ov031_022385e4; size: 0xb0.
// Disables the main display windows, releases dialog-owned sprite groups and input, and removes its task.
extern "C" void WfcUtility_DestroySlidingDialog(void* task)
{
    *(volatile unsigned*)0x04000000 &= ~0xe000u;
    Network_UnlinkNodeAndReleaseRecords(WfcUtilityDestroySlidingDialog_UnknownRoleZeroInitializedStorage->primary);
    Network_UnlinkNodeAndReleaseRecords(WfcUtilityDestroySlidingDialog_UnknownRoleZeroInitializedStorage->secondary);
    for (int i=0;i<WfcUtilityCreateSlidingDialog_UnknownRoleInitializedBytes_Variant7[WfcUtilityDestroySlidingDialog_UnknownRoleZeroInitializedStorage->kind];++i) {
        void* element=WfcUtilityDestroySlidingDialog_UnknownRoleZeroInitializedStorage->elements[i];
        if (element) Network_UnlinkNodeAndReleaseRecords(element);
    }
    Memory_UnlinkInputOwnerAndQueueReference(WfcUtilityDestroySlidingDialog_UnknownRoleZeroInitializedStorage->inputOwner);
    WfcUtility_RequestTaskRemoval(1,task);
    WfcUtility_FreeAllocationAndClearPointer(&ContextStorageAddress::WfcUtilityDestroySlidingDialog_UnknownRoleZeroInitializedStorage);
}

#pragma force_active reset

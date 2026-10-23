#include <globaldefs.h>
ARM
#pragma force_active on
struct SpritePool { unsigned char groups[0x200]; void* first; void* firstEnd; void* firstData; unsigned firstCount; void* second; void* secondEnd; void* secondData; unsigned secondCount; void* queue; void* available; };
extern "C" {
// Original data: arm9/ov031 @ 0x02290d28; symbol: data_ov031_02290d28; initially zero, two-screen sprite pools.
extern SpritePool* WfcUtilityDestroySpriteGroupPools_UnknownRoleZeroInitializedStorage;
void* Memory_AllocateZeroedBlock(unsigned,unsigned);
void* WfcUtility_CreateSteppedPointerRing(int,void*,int);
void* System_InitializeGlobalQueue();
void* Ov031_GetGlobalElementAddress(unsigned,unsigned);
void WfcUtility_PrependListNode(void*,void*);
void WfcUtility_AppendListNode(void*,void*);
}
// Original: arm9/ov031 @ 0x0223b79c; symbol: func_ov031_0223b79c; size: 0xd4.
// Allocates two pools, builds their available-group rings, and attaches each screen's two OAM ranges to its queue.
extern "C" void WfcUtility_InitializeSpriteGroupPools()
{
    WfcUtilityDestroySpriteGroupPools_UnknownRoleZeroInitializedStorage=(SpritePool*)Memory_AllocateZeroedBlock(0x450,4);
    for (int i=0;i<2;++i) {
        WfcUtilityDestroySpriteGroupPools_UnknownRoleZeroInitializedStorage[i].available=WfcUtility_CreateSteppedPointerRing(32,&WfcUtilityDestroySpriteGroupPools_UnknownRoleZeroInitializedStorage[i],16);
        WfcUtilityDestroySpriteGroupPools_UnknownRoleZeroInitializedStorage[i].queue=System_InitializeGlobalQueue();
        WfcUtilityDestroySpriteGroupPools_UnknownRoleZeroInitializedStorage[i].firstData=Ov031_GetGlobalElementAddress(i,64);
        WfcUtilityDestroySpriteGroupPools_UnknownRoleZeroInitializedStorage[i].secondData=(unsigned char*)Ov031_GetGlobalElementAddress(i,127)+8;
        WfcUtility_PrependListNode(WfcUtilityDestroySpriteGroupPools_UnknownRoleZeroInitializedStorage[i].queue,&WfcUtilityDestroySpriteGroupPools_UnknownRoleZeroInitializedStorage[i].first);
        WfcUtility_AppendListNode(WfcUtilityDestroySpriteGroupPools_UnknownRoleZeroInitializedStorage[i].queue,&WfcUtilityDestroySpriteGroupPools_UnknownRoleZeroInitializedStorage[i].second);
    }
}
#pragma force_active reset

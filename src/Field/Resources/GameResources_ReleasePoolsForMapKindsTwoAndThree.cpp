#include <globaldefs.h>
#include <Resource/GameResources.h>
#pragma force_active on
ARM
extern "C" void Memory_FreeThroughAllocatorUnion(void*,void*);
// Original data: arm9/main @ 0x02114E20; symbol: data_02114e20.
// Shared allocator union used to release each destroyed pool's backing allocation.
extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage_Variant3[];
// Original data: arm9/ov017 @ 0x021D665C; symbol: data_ov017_021d665c.
// Signed pool indices terminated by -1 for this map-kind resource group.
extern "C" const int GameResourcesReleasePoolsForMapKindsTwoAndThree_UnknownRoleInitializedBytes[];
// Original: arm9/ov017 @ 0x021A0790; symbol: func_ov017_021a0790; size: 0x64.
// Destroys the selected map-kind pools and frees each existing backing allocation.
extern "C" void GameResources_ReleasePoolsForMapKindsTwoAndThree(GameResources* resources)
{
    // Pool numbering spans adjacent banks; byte offsets are computed within GameResources before casting.
    for(int i=0;GameResourcesReleasePoolsForMapKindsTwoAndThree_UnknownRoleInitializedBytes[i]>-1;++i) {
        int index=GameResourcesReleasePoolsForMapKindsTwoAndThree_UnknownRoleInitializedBytes[i];
        SignedAllocatorHeader* allocation=((SafeAllocator*)((unsigned char*)resources+0x38+index*sizeof(SafeAllocator)))->GetSignedAllocator();
        if(allocation) {
            ((SafeAllocator*)((unsigned char*)resources+0x38+index*sizeof(SafeAllocator)))->Destroy();
            Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3,allocation);
        }
    }
}

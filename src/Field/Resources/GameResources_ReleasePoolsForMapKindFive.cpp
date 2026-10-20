#include <globaldefs.h>
#include <Resource/GameResources.h>
#pragma force_active on
ARM
extern "C" void Memory_FreeThroughAllocatorUnion(void*,void*);
// Original data: arm9/main @ 0x02114E20; symbol: data_02114e20.
// Shared allocator union used to release each destroyed pool's backing allocation.
extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage_Variant3[];
// Original data: arm9/ov017 @ 0x021D6668; symbol: data_ov017_021d6668.
// Signed pool indices terminated by -1 for this map-kind resource group.
extern "C" const int GameResourcesReleasePoolsForMapKindFive_UnknownRoleInitializedBytes[];
// Original: arm9/ov017 @ 0x021A0F40; symbol: func_ov017_021a0f40; size: 0x64.
// Destroys the selected map-kind pools and frees each existing backing allocation.
extern "C" void GameResources_ReleasePoolsForMapKindFive(GameResources* resources)
{
    // Pool numbering spans adjacent banks; byte offsets are computed within GameResources before casting.
    for(int i=0;GameResourcesReleasePoolsForMapKindFive_UnknownRoleInitializedBytes[i]>-1;++i) {
        int index=GameResourcesReleasePoolsForMapKindFive_UnknownRoleInitializedBytes[i];
        SignedAllocatorHeader* allocation=((SafeAllocator*)((unsigned char*)resources+0x38+index*sizeof(SafeAllocator)))->GetSignedAllocator();
        if(allocation) {
            ((SafeAllocator*)((unsigned char*)resources+0x38+index*sizeof(SafeAllocator)))->Destroy();
            Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3,allocation);
        }
    }
}

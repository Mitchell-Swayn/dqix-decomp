#include <globaldefs.h>
#include <Resource/GameResources.h>
#pragma force_active on
ARM
extern "C" void Memory_FreeThroughAllocatorUnion(void*,void*);
// Original data: arm9/main @ 0x02114E20; symbol: data_02114e20.
// Shared allocator union used to release each destroyed pool's backing allocation.
extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage_Variant3[];
// Original data: arm9/ov017 @ 0x021D67E8; symbol: data_ov017_021d67e8.
// Signed pool indices terminated by -1 for this map-kind resource group.
extern "C" const int GameResourcesReleasePoolsForMapKindSeven_UnknownRoleInitializedBytes[];
// Original: arm9/ov017 @ 0x021A0BA8; symbol: func_ov017_021a0ba8; size: 0x64.
// Destroys the selected map-kind pools and frees each existing backing allocation.
extern "C" void GameResources_ReleasePoolsForMapKindSeven(GameResources* resources)
{
    // Pool numbering spans adjacent banks; byte offsets are computed within GameResources before casting.
    for(int i=0;GameResourcesReleasePoolsForMapKindSeven_UnknownRoleInitializedBytes[i]>-1;++i) {
        int index=GameResourcesReleasePoolsForMapKindSeven_UnknownRoleInitializedBytes[i];
        SignedAllocatorHeader* allocation=((SafeAllocator*)((unsigned char*)resources+0x38+index*sizeof(SafeAllocator)))->GetSignedAllocator();
        if(allocation) {
            ((SafeAllocator*)((unsigned char*)resources+0x38+index*sizeof(SafeAllocator)))->Destroy();
            Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3,allocation);
        }
    }
}

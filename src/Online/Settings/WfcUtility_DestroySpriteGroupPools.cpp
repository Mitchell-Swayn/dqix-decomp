#include <globaldefs.h>
ARM
#pragma force_active on

struct SpritePool { char entries[0x220]; void *records; void *allocator; };
// Original data: arm9/ov031 @ 0x02290D28; symbol: data_ov031_02290d28.
// Zero-initialized pointer; pool fields follow the original 0x228-byte stride.
extern "C" SpritePool *WfcUtilityDestroySpriteGroupPools_UnknownRoleZeroInitializedStorage;
namespace PoolStorageAddress { extern "C" SpritePool *WfcUtilityDestroySpriteGroupPools_UnknownRoleZeroInitializedStorage; }
extern "C" void Memory_FreeSharedAllocationFromFirstArgument(void *);
extern "C" void Memory_FreeSharedAllocation(void *);
extern "C" void WfcUtility_FreeAllocationAndClearPointer(void **);
// Original: arm9/ov031 @ 0x0223B870; symbol: func_ov031_0223b870; size: 0x54.
// Releases the record storage and allocator for both sprite pools, then clears the pool context.
extern "C" void WfcUtility_DestroySpriteGroupPools(void)
{
    int i = 0;
    unsigned offset = 0;
    do {
        Memory_FreeSharedAllocationFromFirstArgument(((SpritePool *)((char *)WfcUtilityDestroySpriteGroupPools_UnknownRoleZeroInitializedStorage + offset))->records);
        Memory_FreeSharedAllocation(((SpritePool *)((char *)WfcUtilityDestroySpriteGroupPools_UnknownRoleZeroInitializedStorage + offset))->allocator);
        ++i;
        offset += 0x228;
    } while (i < 2);
    WfcUtility_FreeAllocationAndClearPointer((void **)&PoolStorageAddress::WfcUtilityDestroySpriteGroupPools_UnknownRoleZeroInitializedStorage);
}
#pragma force_active reset

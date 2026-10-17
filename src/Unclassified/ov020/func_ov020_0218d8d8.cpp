#include <GameState/GameState.h>
#include <Memory/SafeAllocator.h>
struct Overlay20AllocatorOwner { unsigned char earlierFields[0x470]; SafeAllocator allocator; };
extern unsigned char data_02114e20[], data_02109bf4[], data_02108760[];
extern "C" void Memory_FreeThroughAllocatorUnion(void*, SignedAllocatorHeader*);
extern "C" unsigned char GameState_ReadByteAtOffset4(GameState*);
extern "C" void DispatchObjectStateOneOrTwoUnlessFlag4(void*, int);
extern "C" void InitializeObjectHandlesAndInvalidIndices(void*);
extern "C" void TransferActiveResourceHandleAndInvalidateIndices(void*);
// Original: arm9/ov020 @ 0x0218D8D8; symbol: func_ov020_0218d8d8; size: 0x6C.
extern "C" void func_ov020_0218d8d8(Overlay20AllocatorOwner* owner)
{
    GameState* state = GameState::GetInstance();
    SignedAllocatorHeader* allocation = owner->allocator.GetSignedAllocator();
    owner->allocator.Destroy();
    Memory_FreeThroughAllocatorUnion(data_02114e20, allocation);
    if (GameState_ReadByteAtOffset4(state) != 2) {
        DispatchObjectStateOneOrTwoUnlessFlag4(data_02109bf4, 0);
        InitializeObjectHandlesAndInvalidIndices(data_02109bf4);
        TransferActiveResourceHandleAndInvalidateIndices(data_02108760);
    }
}

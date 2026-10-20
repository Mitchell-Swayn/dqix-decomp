#include <GameState/GameState.h>
#include <Memory/SafeAllocator.h>
struct Overlay20AllocatorOwner { unsigned char earlierFields[0x470]; SafeAllocator allocator; };
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2109bf4; symbol: data_02109bf4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned char Main_UnknownRoleZeroInitializedStorage_Variant3[], Main_UnknownRoleZeroInitializedStorage_Variant2[], Main_UnknownRoleZeroInitializedStorage[];
extern "C" void Memory_FreeThroughAllocatorUnion(void*, SignedAllocatorHeader*);
extern "C" unsigned char GameState_ReadByteAtOffset4(GameState*);
extern "C" void Bgm_StopActiveSequenceUnlessBlocked(void*, int);
extern "C" void Bgm_StopPlaybackAndResetController(void*);
extern "C" void SoundSfx_RestoreSecondaryHeapStateAndVolume(void*);
// Original: arm9/ov020 @ 0x0218D8D8; symbol: func_ov020_0218d8d8; size: 0x6C.
extern "C" void BootScreen_ReleaseResourcesAndResetAudio(Overlay20AllocatorOwner* owner)
{
    GameState* state = GameState::GetInstance();
    SignedAllocatorHeader* allocation = owner->allocator.GetSignedAllocator();
    owner->allocator.Destroy();
    Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3, allocation);
    if (GameState_ReadByteAtOffset4(state) != 2) {
        Bgm_StopActiveSequenceUnlessBlocked(Main_UnknownRoleZeroInitializedStorage_Variant2, 0);
        Bgm_StopPlaybackAndResetController(Main_UnknownRoleZeroInitializedStorage_Variant2);
        SoundSfx_RestoreSecondaryHeapStateAndVolume(Main_UnknownRoleZeroInitializedStorage);
    }
}

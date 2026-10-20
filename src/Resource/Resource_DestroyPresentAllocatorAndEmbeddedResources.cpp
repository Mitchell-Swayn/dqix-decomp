#include <globaldefs.h>
#include <Memory/SafeAllocator.h>
#include <GameState/GameState.h>
extern "C" {
    void *GameState_GetFieldOrbitCamera(GameState *);
    void Camera_EnableOrbitInput(void *);
    void ResetWordAndTwoHalfwordRecord(void *);
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
    extern unsigned char Main_UnknownRoleZeroInitializedStorage_Variant3[];
    void Memory_FreeThroughAllocatorUnion(void *,void *);
// Original: arm9/main @ 0x020D8484; symbol: func_020d8484; size: 0x58.
    void Resource_DestroyPresentAllocatorAndEmbeddedResources(unsigned char *p){
        Camera_EnableOrbitInput(GameState_GetFieldOrbitCamera(GameState::GetInstance()));
        SafeAllocator *alloc=(SafeAllocator *)(p+20);
        SignedAllocatorHeader *q=alloc->GetSignedAllocator();
        if(q){
            alloc->Reset();
            alloc->Destroy();
            ResetWordAndTwoHalfwordRecord(p+12);
            Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3,q);
        }p[1]=1;
    }
}

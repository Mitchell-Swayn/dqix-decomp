#include <globaldefs.h>
#include <Memory/SafeAllocator.h>
#include <GameState/GameState.h>
extern "C" {
    void *GameState_GetField3B0ObjectWithFlag4(GameState *);
    void Object_SetWordAtOffset23CTo1(void *);
    void ResetWordAndTwoHalfwordRecord(void *);
    extern unsigned char data_02114e20[];
    void Memory_FreeThroughAllocatorUnion(void *,void *);
// Original: arm9/main @ 0x020D8484; symbol: func_020d8484; size: 0x58.
    void DestroyPresentAllocatorAndEmbeddedResources(unsigned char *p){
        Object_SetWordAtOffset23CTo1(GameState_GetField3B0ObjectWithFlag4(GameState::GetInstance()));
        SafeAllocator *alloc=(SafeAllocator *)(p+20);
        SignedAllocatorHeader *q=alloc->GetSignedAllocator();
        if(q){
            alloc->Reset();
            alloc->Destroy();
            ResetWordAndTwoHalfwordRecord(p+12);
            Memory_FreeThroughAllocatorUnion(data_02114e20,q);
        }p[1]=1;
    }
}

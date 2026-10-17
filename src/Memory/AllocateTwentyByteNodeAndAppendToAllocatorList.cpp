#include <globaldefs.h>
#include <Memory/HMRFAllocator.h>
extern "C" {
    void ResourceAllocator_InitializeTrackingList(void *);
    struct Obj{
        HMRFAllocator *allocator;
        SignedAllocatorList list;
    };
// Original: arm9/main @ 0x020BDC24; symbol: func_020bdc24; size: 0x3C.
    bool AllocateTwentyByteNodeAndAppendToAllocatorList(Obj *p){
        void *q=p->allocator->Allocate(20,4);
        if(!q)return false;
        ResourceAllocator_InitializeTrackingList(q);
        p->list.InsertAtEnd((SignedAllocatorHeader *)q);
        return true;
    }
}

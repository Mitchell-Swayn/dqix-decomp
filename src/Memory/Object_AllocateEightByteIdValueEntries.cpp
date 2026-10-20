#include <globaldefs.h>
#include <Memory/SafeAllocator.h>
extern "C" {
    struct R{
        short id,pad;
        int value;
    };
    struct L{
        R *entries;
        unsigned short capacity,count;
    };
// Original: arm9/main @ 0x020729B4; symbol: func_020729b4; size: 0x74.
    void Object_AllocateEightByteIdValueEntries(L *p,SafeAllocator *alloc,unsigned short count){
        if(p->entries)return;
        p->count=0;
        p->capacity=count;
        p->entries=(R *)alloc->Allocate(count*8);
        for(unsigned short i=0;i<count;i++){
            p->entries[i].id=-1;
            p->entries[i].value=0;
        }
    }
}

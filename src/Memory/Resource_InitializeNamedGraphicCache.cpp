#include <globaldefs.h>
#include <Memory/SafeAllocator.h>
extern "C" {
    void Resource_ResetNamedGraphicCacheEntry(void *);
    struct Obj{
        unsigned int count;
        unsigned char a,b;
        unsigned short pad;
        unsigned char *entries;
    };
// Original: arm9/main @ 0x020401FC; symbol: func_020401fc; size: 0x5C.
    void Resource_InitializeNamedGraphicCache(Obj *p,unsigned int count,SafeAllocator *alloc){
        p->a=0;
        p->count=count;
        p->b=0;
        p->entries=(unsigned char *)alloc->Allocate(p->count*60);
        for(unsigned int i=0;i<p->count;i++)Resource_ResetNamedGraphicCacheEntry(p->entries+i*60);
    }
}

#include <globaldefs.h>
#include <System/Cache.h>
extern "C" {
    extern void (*data_020f2bb0[])(void *,unsigned int,unsigned int);
    unsigned char *Graphics_ReadSelectedBackgroundOrObjectCharacterBase(void *);
// Original: arm9/main @ 0x020E1384; symbol: func_020e1384; size: 0x58.
    void ResourceBuffer_InvokeIndexedTransformWithCacheMaintenance(unsigned char *p){
        unsigned char *base=Graphics_ReadSelectedBackgroundOrObjectCharacterBase(p);
        if(!base)return;
        unsigned int offset=*(unsigned int *)p;
        void (*fn)(void *,unsigned int,unsigned int)=data_020f2bb0[p[20]];
        if(!fn)return;
        CleanInvalidateCacheRange(base+offset,*(unsigned int *)(p+4));
        fn(base+offset,*(unsigned int *)(p+12),*(unsigned int *)(p+4));
        CleanCacheRange(base+offset,*(unsigned int *)(p+4));
    }
}

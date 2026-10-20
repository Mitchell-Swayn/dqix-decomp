#include <globaldefs.h>
#include <System/Cache.h>
extern "C" {
// Original data: arm9/main @ 0x20f2bb0; symbol: data_020f2bb0.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 00000000d85d0c02985e0c02585f0c0218600c02285a0c02385e0c02f85e0c02b85f0c0278600c02805a0c02.
// Observed span: 44 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
    extern void (*CleanCacheAndInvokeTypedRangeCallback_UnknownRoleProcedureReferenceRecords[])(void *,unsigned int,unsigned int);
    unsigned char *Graphics_ReadSelectedBackgroundOrObjectCharacterBase(void *);
// Original: arm9/main @ 0x020E1384; symbol: func_020e1384; size: 0x58.
    void ResourceBuffer_InvokeIndexedTransformWithCacheMaintenance(unsigned char *p){
        unsigned char *base=Graphics_ReadSelectedBackgroundOrObjectCharacterBase(p);
        if(!base)return;
        unsigned int offset=*(unsigned int *)p;
        void (*fn)(void *,unsigned int,unsigned int)=CleanCacheAndInvokeTypedRangeCallback_UnknownRoleProcedureReferenceRecords[p[20]];
        if(!fn)return;
        CleanInvalidateCacheRange(base+offset,*(unsigned int *)(p+4));
        fn(base+offset,*(unsigned int *)(p+12),*(unsigned int *)(p+4));
        CleanCacheRange(base+offset,*(unsigned int *)(p+4));
    }
}

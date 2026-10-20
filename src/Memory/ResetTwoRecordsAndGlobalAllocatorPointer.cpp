#include <globaldefs.h>
#include <Memory/SafeAllocator.h>
extern "C" {
// Original data: arm9/main @ 0x2153694; symbol: data_02153694.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
    extern unsigned char TextLookupStandardString_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/main @ 0x2153680; symbol: data_02153680.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
    extern SafeAllocator AllocatorCreateAndResetGlobalTypeAHeap_UnknownRoleZeroInitializedStorage;
    void ResourceStringLoader_Reset(void *);
// Original: arm9/main @ 0x020E5058; symbol: func_020e5058; size: 0x3C.
    void ResetTwoRecordsAndGlobalAllocatorPointer(){
        for(int i=0;i<2;i++)ResourceStringLoader_Reset(TextLookupStandardString_UnknownRoleZeroInitializedStorage+i*24);
        AllocatorCreateAndResetGlobalTypeAHeap_UnknownRoleZeroInitializedStorage.ResetAllocatorPointer();
    }
}

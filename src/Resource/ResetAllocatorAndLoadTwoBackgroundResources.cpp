#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
// Original data: arm9/main @ 0x2153680; symbol: data_02153680.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" SafeAllocator AllocatorCreateAndResetGlobalTypeAHeap_UnknownRoleZeroInitializedStorage;
// Original data: arm9/main @ 0x2153694; symbol: data_02153694.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char TextLookupStandardString_UnknownRoleZeroInitializedStorage[];
extern "C" char ResetAllocatorAndLoadTwoBackgroundResources_PathDataBinStrstdGp2[],ResetAllocatorAndLoadTwoBackgroundResources_PathDataPrmArticleGp2[],ResetAllocatorAndLoadTwoBackgroundResources_MarkupArticleLGNat[],ResetAllocatorAndLoadTwoBackgroundResources_MarkupStrstdLGNat[];
extern "C" void ResourceStringLoader_Reset(void*);
extern "C" void ResourceStringTable_CopySerializedData(void*,SafeAllocator*,void*,unsigned);
// Original: arm9/main @ 0x020E5114; symbol: func_020e5114; size: 0xB8.
extern "C" ARM int ResetAllocatorAndLoadTwoBackgroundResources()
{
    unsigned size;
    AllocatorCreateAndResetGlobalTypeAHeap_UnknownRoleZeroInitializedStorage.Reset();
    BackgroundLoader::AddLockGlobal();
    BackgroundLoader::FreeAllocationsGlobal();
    int offset;
    char* base;
    int i=0;
    base=TextLookupStandardString_UnknownRoleZeroInitializedStorage;
    for(;i<2;++i)
    {
        offset=i*24;
        ResourceStringLoader_Reset(base+offset);
        void* data;
        if(i!=0)data=Filesystem_ExtractLocalizedGp2FileToScratch(ResetAllocatorAndLoadTwoBackgroundResources_PathDataPrmArticleGp2,ResetAllocatorAndLoadTwoBackgroundResources_MarkupArticleLGNat,&size);
        else data=Filesystem_ExtractLocalizedGp2FileToScratch(ResetAllocatorAndLoadTwoBackgroundResources_PathDataBinStrstdGp2,ResetAllocatorAndLoadTwoBackgroundResources_MarkupStrstdLGNat,&size);
        if(data)ResourceStringTable_CopySerializedData(base+offset,&AllocatorCreateAndResetGlobalTypeAHeap_UnknownRoleZeroInitializedStorage,data,size);
    }BackgroundLoader::RemoveLockGlobal();
    return 0;
}

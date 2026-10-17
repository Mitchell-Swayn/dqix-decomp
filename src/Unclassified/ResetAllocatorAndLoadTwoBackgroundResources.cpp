#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
extern "C" SafeAllocator data_02153680;
extern "C" char data_02153694[];
extern "C" char data_020f2dfa[],data_020f2dd4[],data_020f2de9[],data_020f2e0e[];
extern "C" void ClearRecordAndInvalidateTwoIndices(void*);
extern "C" void func_020dfec0(void*,SafeAllocator*,void*,unsigned);
// Original: arm9/main @ 0x020E5114; symbol: func_020e5114; size: 0xB8.
extern "C" ARM int ResetAllocatorAndLoadTwoBackgroundResources()
{
    unsigned size;
    data_02153680.Reset();
    BackgroundLoader::AddLockGlobal();
    BackgroundLoader::FreeAllocationsGlobal();
    int offset;
    char* base;
    int i=0;
    base=data_02153694;
    for(;i<2;++i)
    {
        offset=i*24;
        ClearRecordAndInvalidateTwoIndices(base+offset);
        void* data;
        if(i!=0)data=ExtractFileFromGP2(data_020f2dd4,data_020f2de9,&size);
        else data=ExtractFileFromGP2(data_020f2dfa,data_020f2e0e,&size);
        if(data)func_020dfec0(base+offset,&data_02153680,data,size);
    }BackgroundLoader::RemoveLockGlobal();
    return 0;
}

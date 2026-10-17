#include <globaldefs.h>
ARM
#include <Filesystem/BackgroundLoader.h>
#include <Memory/SafeAllocator.h>
extern "C" unsigned Object_GetGlobalRequestQueue();extern "C" unsigned Memory_ReadMaximumAlignedAllocation(void*);extern "C" void* AllocatorUnion_AllocateFourByteAligned(void*,unsigned);
extern "C" void Memory_FreeThroughAllocatorUnion(void*,void*);extern "C" char data_02114e20[];
extern "C" void func_0209576c(unsigned,SafeAllocator*,void*,unsigned,unsigned);extern "C" void GameState_ConsumeReadyKeyRecordAndMappedValues(unsigned,unsigned,unsigned);extern "C" void BackgroundLoader_RemoveIndexedTaskAndClearMask(char*,unsigned);
// Original: arm9/main @ 0x020DA074; symbol: func_020da074; size: 0xDC.
extern "C" void ProcessLoadedFileUsingTemporary1024ByteAllocator(char* p){
    void* data;unsigned length;SafeAllocator allocator;
    BackgroundLoader* loader=BackgroundLoader::GetInstance();unsigned object=Object_GetGlobalRequestQueue();
    loader->GetLoadedFileByID(*(int*)(p+12),&data,&length);
    if(Memory_ReadMaximumAlignedAllocation(data_02114e20)>0x400){
        allocator.ResetAllocatorPointer();allocator.ResetAllocatorPointer();void* buffer=AllocatorUnion_AllocateFourByteAligned(data_02114e20,0x400);
        allocator.CreateTypeA(buffer,0x400);allocator.Reset();
        func_0209576c(object,&allocator,data,length,0);GameState_ConsumeReadyKeyRecordAndMappedValues(object,*(unsigned*)(p+16),0);
        SignedAllocatorHeader* allocation=allocator.GetSignedAllocator();
        if(allocation){allocator.Destroy();Memory_FreeThroughAllocatorUnion(data_02114e20,allocation);}
    }
    BackgroundLoader_RemoveIndexedTaskAndClearMask(p,0);
}

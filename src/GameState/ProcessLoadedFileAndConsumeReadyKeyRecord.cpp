#include <globaldefs.h>
ARM
#include <Filesystem/BackgroundLoader.h>
#include <Memory/SafeAllocator.h>
extern "C" unsigned Quest_GetGlobalOrderState();extern "C" unsigned Memory_ReadMaximumAlignedAllocation(void*);extern "C" void* AllocatorUnion_AllocateFourByteAligned(void*,unsigned);
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" void Memory_FreeThroughAllocatorUnion(void*,void*);extern "C" char Main_UnknownRoleZeroInitializedStorage_Variant3[];
extern "C" void Quest_ExecuteOrderPayloadScript(unsigned,SafeAllocator*,void*,unsigned,unsigned);extern "C" void Quest_ConsumeAcceptedOrderPayload(unsigned,unsigned,unsigned);extern "C" void BackgroundLoader_RemoveIndexedTaskAndClearMask(char*,unsigned);
// Original: arm9/main @ 0x020DA074; symbol: func_020da074; size: 0xDC.
extern "C" void ProcessLoadedFileAndConsumeReadyKeyRecord(char* p){
    void* data;unsigned length;SafeAllocator allocator;
    BackgroundLoader* loader=BackgroundLoader::GetInstance();unsigned object=Quest_GetGlobalOrderState();
    loader->GetLoadedFileByID(*(int*)(p+12),&data,&length);
    if(Memory_ReadMaximumAlignedAllocation(Main_UnknownRoleZeroInitializedStorage_Variant3)>0x400){
        allocator.ResetAllocatorPointer();allocator.ResetAllocatorPointer();void* buffer=AllocatorUnion_AllocateFourByteAligned(Main_UnknownRoleZeroInitializedStorage_Variant3,0x400);
        allocator.CreateTypeA(buffer,0x400);allocator.Reset();
        Quest_ExecuteOrderPayloadScript(object,&allocator,data,length,0);Quest_ConsumeAcceptedOrderPayload(object,*(unsigned*)(p+16),0);
        SignedAllocatorHeader* allocation=allocator.GetSignedAllocator();
        if(allocation){allocator.Destroy();Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3,allocation);}
    }
    BackgroundLoader_RemoveIndexedTaskAndClearMask(p,0);
}

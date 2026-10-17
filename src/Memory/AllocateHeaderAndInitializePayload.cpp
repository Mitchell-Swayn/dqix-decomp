#include <globaldefs.h>
ARM
#pragma optimize_for_size off
#include <Memory/SignedAllocator.h>
extern "C" char* ResourceAllocator_AllocateTrackedAlignedBlock(unsigned,unsigned,unsigned,unsigned,unsigned);
extern "C" unsigned ResourceAllocator_CreateAlignedHeapRegion(char*,unsigned);
extern "C" void Header_Invokeif();
extern "C" char data_0210f824[];
// Original: arm9/main @ 0x020BBF84; symbol: func_020bbf84; size: 0x94.
extern "C" int AllocateHeaderAndInitializePayload(int index,unsigned allocator,unsigned size) {
    char* allocation=ResourceAllocator_AllocateTrackedAlignedBlock(allocator,size+20,(unsigned)Header_Invokeif,0,0);
    if (!allocation) return 0;
    *(unsigned*)(allocation+12)=0;
    *(int*)(allocation+16)=index;
    *(unsigned*)(allocation+8)=0;
    unsigned value=ResourceAllocator_CreateAlignedHeapRegion(allocation+20,size);
    if (!value) return 0;
    char* list=data_0210f824+index*36;
    *(unsigned*)(allocation+8)=value;
    ((SignedAllocatorList*)(list+12))->InsertAtEnd((SignedAllocatorHeader*)allocation);
    return 1;
}

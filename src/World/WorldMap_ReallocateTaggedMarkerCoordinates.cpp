#include <globaldefs.h>
#include <std_library_functions.h>
#include <Resource/GameResources.h>
ARM
// Original: arm9/main @ 0x02027B10; symbol: WorldMap_ReallocateTaggedMarkerCoordinates; size: 0x4C.
// Replaces the owner's twelve-byte entry allocation and resets the byte at+0xA99.
extern "C" void WorldMap_ReallocateTaggedMarkerCoordinates(char* self,unsigned count) {
 SafeAllocator* allocator=(SafeAllocator*)((unsigned)GameResources_GetInstance()+offsetof(GameResources,allocator_array_38)+12*sizeof(SafeAllocator));
 void* old=*(void**)(self+0xa9c);
 if(old)allocator->Free(old);
 *(void**)(self+0xa9c)=allocator->Allocate(count*12);
 *(unsigned char*)(self+0xa98)=count;
 *(unsigned char*)(self+0xa99)=0;
}

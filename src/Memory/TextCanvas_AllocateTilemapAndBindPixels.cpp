#include <Memory/SafeAllocator.h>
// Original: arm9/main @ 0x0204C7A8; symbol: func_0204c7a8; size: 0x24.
extern "C" void TextCanvas_AllocateTilemapAndBindPixels(char* p,SafeAllocator* allocator,int value,unsigned int size) { *(void**)(p+0xd4)=allocator->Allocate(size); *(int*)(p+8)=value; }

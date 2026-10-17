#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
extern "C" unsigned int data_020e7c18[],data_020e7d30[],data_020e7d34[];
extern "C" void SnapshotBlockAndVolatileWordPair(void*),Graphics_RestoreTextureImageAndPaletteVRAMState(void*),Object_InvokeSaveTextureImageVRAMState(void*);
extern "C" void VRAM_SaveStateAndReserveImagePaletteBytes(void*,unsigned int,unsigned int);
struct Display {char data[0x70];};
struct Owner {unsigned int header;SafeAllocator allocators[10];Display displays[10];SafeAllocator extraA,extraB,extraC;Display extraDisplay;SafeAllocator extraD;};
// Original: arm9/main @ 0x02054464; symbol: func_02054464; size: 0x148.
extern "C" ARM void Graphics_InitializeTenDisplayAllocatorsAndExtraBuffers(Owner* self,SafeAllocator* allocator,void* argument) {
 allocator->Reset();SnapshotBlockAndVolatileWordPair(argument);Graphics_RestoreTextureImageAndPaletteVRAMState(argument);
 for(int i=0;i<10;++i) {
  unsigned int size=data_020e7c18[i];
  if(size) {void* memory=allocator->Allocate(size);self->allocators[i].CreateTypeA(memory,size);VRAM_SaveStateAndReserveImagePaletteBytes(&self->displays[i],*(unsigned int*)((char*)data_020e7d30+i*8),*(unsigned int*)((char*)data_020e7d34+i*8));}
  else self->allocators[i].ResetAllocatorPointer();
 }
 VRAM_SaveStateAndReserveImagePaletteBytes(&self->extraDisplay,0x240,0x20);Object_InvokeSaveTextureImageVRAMState(argument);
 void* memory=allocator->Allocate(0x2000);self->extraA.CreateTypeA(memory,0x2000);
 memory=allocator->Allocate(0x5400);self->extraB.CreateTypeA(memory,0x5400);
 memory=allocator->Allocate(0x1000);self->extraC.CreateTypeA(memory,0x1000);
 memory=allocator->Allocate(0xc00);self->extraD.CreateTypeA(memory,0xc00);
}

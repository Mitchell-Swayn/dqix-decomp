#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
// Original data: arm9/main @ 0x20e7c18; symbol: data_020e7c18.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 7c840000000200000000000000000000000000000000000000000000000000000000000000000000.
// Observed span: 40 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x20e7d30; symbol: data_020e7d30.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 40080000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x20e7d34; symbol: data_020e7d34.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 600000000004000040000000000800004000000000000000000000000004000040000000c0010000400000000002000040000000000800004000000000040000 ...; full span in module reference.
// Observed span: 80 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned int GraphicsInitializeTenDisplayAllocatorsAndExtraBuffers_UnknownRoleInitializedBytes[],GraphicsInitializeTenDisplayAllocatorsAndExtraBuffers_UnknownRoleInitializedBytes_Variant2[],GraphicsInitializeTenDisplayAllocatorsAndExtraBuffers_UnknownRoleInitializedBytes_Variant3[];
extern "C" void TextureVRAM_SnapshotAllocationBounds(void*),Graphics_RestoreTextureImageAndPaletteVRAMState(void*),Object_InvokeSaveTextureImageVRAMState(void*);
extern "C" void VRAM_SaveStateAndReserveImagePaletteBytes(void*,unsigned int,unsigned int);
struct Display {char data[0x70];};
struct Owner {unsigned int header;SafeAllocator allocators[10];Display displays[10];SafeAllocator extraA,extraB,extraC;Display extraDisplay;SafeAllocator extraD;};
// Original: arm9/main @ 0x02054464; symbol: func_02054464; size: 0x148.
extern "C" ARM void Graphics_InitializeTenDisplayAllocatorsAndExtraBuffers(Owner* self,SafeAllocator* allocator,void* argument) {
 allocator->Reset();TextureVRAM_SnapshotAllocationBounds(argument);Graphics_RestoreTextureImageAndPaletteVRAMState(argument);
 for(int i=0;i<10;++i) {
  unsigned int size=GraphicsInitializeTenDisplayAllocatorsAndExtraBuffers_UnknownRoleInitializedBytes[i];
  if(size) {void* memory=allocator->Allocate(size);self->allocators[i].CreateTypeA(memory,size);VRAM_SaveStateAndReserveImagePaletteBytes(&self->displays[i],*(unsigned int*)((char*)GraphicsInitializeTenDisplayAllocatorsAndExtraBuffers_UnknownRoleInitializedBytes_Variant2+i*8),*(unsigned int*)((char*)GraphicsInitializeTenDisplayAllocatorsAndExtraBuffers_UnknownRoleInitializedBytes_Variant3+i*8));}
  else self->allocators[i].ResetAllocatorPointer();
 }
 VRAM_SaveStateAndReserveImagePaletteBytes(&self->extraDisplay,0x240,0x20);Object_InvokeSaveTextureImageVRAMState(argument);
 void* memory=allocator->Allocate(0x2000);self->extraA.CreateTypeA(memory,0x2000);
 memory=allocator->Allocate(0x5400);self->extraB.CreateTypeA(memory,0x5400);
 memory=allocator->Allocate(0x1000);self->extraC.CreateTypeA(memory,0x1000);
 memory=allocator->Allocate(0xc00);self->extraD.CreateTypeA(memory,0xc00);
}

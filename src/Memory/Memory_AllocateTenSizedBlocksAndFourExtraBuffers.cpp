#include <globaldefs.h>
ARM
#include <Memory/SafeAllocator.h>
#include <System/Memory.h>
// Original data: arm9/main @ 0x20e7c40; symbol: data_020e7c40.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 38280000681900000c0b0000640d000010080000000200000002000064100000ac0a00004c050000000000000000000000000000000000000000000000000000 ...; full span in module reference.
// Observed span: 84 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" {extern unsigned int MemoryAllocateTenSizedBlocksAndFourExtraBuffers_UnknownRoleInitializedBytes[];void CharacterResourceContext_ReserveTextureVRAMRegions(void*,int);
// Original: arm9/main @ 0x020542B4; symbol: func_020542b4; size: 0x138.
void Memory_AllocateTenSizedBlocksAndFourExtraBuffers(unsigned char* p,SafeAllocator* alloc,int value){alloc->Reset();for(int i=0;i<10;i++){unsigned int size=MemoryAllocateTenSizedBlocksAndFourExtraBuffers_UnknownRoleInitializedBytes[i];void* data=alloc->Allocate(size);VectorizedMemset(data,0,size);((SafeAllocator*)(p+4+i*0x14))->CreateTypeA(data,size);}CharacterResourceContext_ReserveTextureVRAMRegions(p,value);void* data=alloc->Allocate(0x2000);VectorizedMemset(data,0,0x2000);((SafeAllocator*)(p+0x52c))->CreateTypeA(data,0x2000);data=alloc->Allocate(0x5400);VectorizedMemset(data,0,0x5400);((SafeAllocator*)(p+0x540))->CreateTypeA(data,0x5400);data=alloc->Allocate(0x1000);VectorizedMemset(data,0,0x1000);((SafeAllocator*)(p+0x554))->CreateTypeA(data,0x1000);data=alloc->Allocate(0xc00);VectorizedMemset(data,0,0xc00);((SafeAllocator*)(p+0x5d8))->CreateTypeA(data,0xc00);}}

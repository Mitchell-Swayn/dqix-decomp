#include <globaldefs.h>
#include <Memory/SafeAllocator.h>
ARM
extern "C" void Graphics_ResetTilePayloadWithUnitScale(unsigned *);
// Original: arm9/ov023 @ 0x021DBFD0; symbol: ItemDetail_AllocateDisplayResources; size: 0x164.
// Allocates nested allocators and paired records; initializes their selected scalar fields.
extern "C" void ItemDetail_AllocateDisplayResources(char *self, SafeAllocator *allocator) {
 if(!allocator)return;
 signed char *sourceByte=(signed char *)(self+0x77c);
 ((SafeAllocator *)(self))->CreateTypeA(allocator->Allocate(0xd33),0xd33);
 ((SafeAllocator *)(self+0x14))->CreateTypeA(allocator->Allocate(0x4cc),0x4cc);
 ((SafeAllocator *)(self+0x28))->CreateTypeA(allocator->Allocate(0x400),0x400);
 *(void **)(self+0xc4)=allocator->Allocate(0x70);
 *(void **)(self+0xc8)=allocator->Allocate(0x70);
 *(void **)(self+0x3c)=allocator->Allocate(0x14);
 *(void **)(self+0x40)=allocator->Allocate(0x14);
 *(void **)(self+0x44)=allocator->Allocate(0x14);
 (*(SafeAllocator **)(self+0x44))->CreateTypeA(allocator->Allocate(0x180),0x180);
 Graphics_ResetTilePayloadWithUnitScale(*(unsigned **)(self+0xc4));
 Graphics_ResetTilePayloadWithUnitScale(*(unsigned **)(self+0xc8));
 (*(char **)(self+0xc4))[0x5e]=*sourceByte;
 *(unsigned *)(*(char **)(self+0xc4)+0x3c)=0;
 (*(char **)(self+0xc8))[0x5e]=*sourceByte;
 *(unsigned *)(*(char **)(self+0xc8)+0x38)=0x120;
 *(unsigned *)(*(char **)(self+0xc8)+0x3c)=1;
 (*(SafeAllocator **)(self+0x3c))->CreateTypeA(allocator->Allocate(0x280),0x280);
 (*(SafeAllocator **)(self+0x40))->CreateTypeA(allocator->Allocate(0x280),0x280);
}

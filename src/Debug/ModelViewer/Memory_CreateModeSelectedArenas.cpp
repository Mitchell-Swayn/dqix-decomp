#include <globaldefs.h>
ARM
struct AllocatorUnion;struct SlotPool;struct Slot;
struct SizePairs {unsigned sizes[11][2];};
struct ModeSizes {unsigned sizes[7];};
extern "C" {
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern char Main_UnknownRoleZeroInitializedStorage_Variant3[];
// Original data: arm9/ov015 @ 0x2193d80; symbol: data_ov015_02193d80.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00000000000000000050010000500300000001000050000000500000.
// Observed span: 28 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov015.md.
// Original data: arm9/ov015 @ 0x2193df0; symbol: data_ov015_02193df0.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 382800000054000068190000002000000c0b000000140000640d0000001c000010080000000c000000020000001c000000020000001c000064100000e8230000 ...; full span in module reference.
// Observed span: 88 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov015.md.
extern SizePairs MemoryCreateModeSelectedArenas_UnknownRoleInitializedBytes_Variant2;extern ModeSizes MemoryCreateModeSelectedArenas_UnknownRoleInitializedBytes;
void* AllocatorUnion_AllocateFourByteAligned(AllocatorUnion*,unsigned);
void _ZN13SafeAllocator21ResetAllocatorPointerEv(void*);
void _ZN13SafeAllocator11CreateTypeAEPvj(void*,void*,unsigned);
void _ZN13SafeAllocator5ResetEv(void*);
void _ZN8Object3D10InitializeEv(void*);
void ResourceTracks_ClearBindingOwner(int*);
void CharacterViewer_DestroyModelInstanceResources(unsigned char*);
Slot* CharacterViewer_FindUnusedPlayerVramReservation(SlotPool*);
Slot* CharacterViewer_FindUnusedDollVramReservation(SlotPool*);
Slot* CharacterViewer_FindUnusedSingleModelVramReservation(SlotPool*);
void* memset(void*,int,unsigned);
}
#define P(p,o) (*(unsigned char**)((p)+(o)))
#define W(p,o) (*(unsigned*)((p)+(o)))
#define ALLOC(n) ((unsigned char*)AllocatorUnion_AllocateFourByteAligned((AllocatorUnion*)Main_UnknownRoleZeroInitializedStorage_Variant3,(n)))
#define FAIL() {CharacterViewer_DestroyModelInstanceResources(self);return 0;}
// Original: arm9/ov015 @ 0x0218BCB0; symbol: func_ov015_0218bcb0; size: 0x38C.
// Creates ten arenas and model slots for modes zero/one, or one arena and optional buffers for other modes.
extern "C" int Memory_CreateModeSelectedArenas(unsigned char* self) {
 if(self[0x1c]==0 || self[0x1c]==1) {
 SizePairs sizes=MemoryCreateModeSelectedArenas_UnknownRoleInitializedBytes_Variant2;
 P(self,8)=ALLOC(0xc8);if(!P(self,8))FAIL();
 P(self,0x24)=ALLOC(0x6b8);if(!P(self,0x24))FAIL();
 for(int i=0;i<10;++i) {
 _ZN13SafeAllocator21ResetAllocatorPointerEv(P(self,8)+i*20);
 void* allocation=ALLOC(sizes.sizes[i][self[0x1c]]);if(!allocation)return 0;
 _ZN13SafeAllocator11CreateTypeAEPvj(P(self,8)+i*20,allocation,sizes.sizes[i][self[0x1c]]);
 _ZN13SafeAllocator5ResetEv(P(self,8)+i*20);
 _ZN8Object3D10InitializeEv(P(self,0x24)+i*0xac);
 }
 P(self,0x20)=ALLOC(0x28);if(!P(self,0x20))FAIL();
 memset(P(self,0x20),-1,0x28);
 W(P(self,0x20),0)=0x32cf;
 W(P(self,0x20),4)=0x3f57;
 W(P(self,0x20),8)=0x233c;
 W(P(self,0x20),12)=0x2328;
 W(P(self,0x20),16)=0x2328;
 W(P(self,0x20),20)=0x36b7;
 W(P(self,0x20),24)=0x42e0;
 if(self[0x1c]==0)P(self,4)=(unsigned char*)CharacterViewer_FindUnusedPlayerVramReservation((SlotPool*)P(self,0));
 else P(self,4)=(unsigned char*)CharacterViewer_FindUnusedDollVramReservation((SlotPool*)P(self,0));
 if(!P(self,4))FAIL();
 P(self,4)[4]=1;
 W(self,0x18)=sizes.sizes[10][self[0x1c]];
 P(self,0x14)=ALLOC(W(self,0x18));if(!P(self,0x14))FAIL();
 }else {
 ModeSizes sizes=MemoryCreateModeSelectedArenas_UnknownRoleInitializedBytes;
 P(self,8)=ALLOC(20);if(!P(self,8))FAIL();
 _ZN13SafeAllocator21ResetAllocatorPointerEv(P(self,8));
 void* allocation=ALLOC(sizes.sizes[self[0x1c]]);if(!allocation)return 0;
 _ZN13SafeAllocator11CreateTypeAEPvj(P(self,8),allocation,sizes.sizes[self[0x1c]]);
 _ZN13SafeAllocator5ResetEv(P(self,8));
 P(self,4)=(unsigned char*)CharacterViewer_FindUnusedSingleModelVramReservation((SlotPool*)P(self,0));if(!P(self,4))FAIL();
 P(self,4)[4]=1;
 if(self[0x1c]==2||self[0x1c]==3) {W(self,0x18)=0xc000;P(self,0x14)=ALLOC(0xc000);if(!P(self,0x14))FAIL();}
 P(self,0x24)=ALLOC(0xac);if(!P(self,0x24))FAIL();
 _ZN8Object3D10InitializeEv(P(self,0x24));
 if(self[0x1c]==4) {P(self,0x28)=ALLOC(0x1c);if(!P(self,0x28))FAIL();ResourceTracks_ClearBindingOwner((int*)P(self,0x28));}
 }
 return 1;
}

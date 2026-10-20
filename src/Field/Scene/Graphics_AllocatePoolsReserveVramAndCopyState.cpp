#include <globaldefs.h>
ARM
#pragma auto_inline on
struct Block { unsigned value[10]; };
struct Two {unsigned value[2];};
struct Pair {unsigned value,pad;};
struct Triple {unsigned value,pad[2];};
extern "C" {
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern char Main_UnknownRoleZeroInitializedStorage_Variant3[];
// Original data: arm9/ov017 @ 0x21d689c; symbol: data_ov017_021d689c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 14000000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
// Original data: arm9/ov017 @ 0x21d68a0; symbol: data_ov017_021d68a0.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 002000000000000000b80200070000000068030015000000002001001a000000005000000000000000000000.
// Observed span: 44 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
extern Pair GraphicsAllocatePoolsReserveVramAndCopyState_UnknownRoleInitializedBytes_Variant7[],GraphicsAllocatePoolsReserveVramAndCopyState_UnknownRoleInitializedBytes_Variant8[];
// Original data: arm9/ov017 @ 0x21d6758; symbol: data_ov017_021d6758.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00000000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
// Original data: arm9/ov017 @ 0x21d675c; symbol: data_ov017_021d675c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00000200.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
// Original data: arm9/ov017 @ 0x21d6760; symbol: data_ov017_021d6760.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 000c0000000000000000000000000000.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
extern Triple GraphicsAllocatePoolsReserveVramAndCopyState_UnknownRoleInitializedBytes[],GraphicsAllocatePoolsReserveVramAndCopyState_UnknownRoleInitializedBytes_Variant3[],GraphicsAllocatePoolsReserveVramAndCopyState_UnknownRoleInitializedBytes_Variant2[];
// Original data: arm9/ov017 @ 0x21d6850; symbol: data_ov017_021d6850.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 07000000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
// Original data: arm9/ov017 @ 0x21d6854; symbol: data_ov017_021d6854.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00d40000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
// Original data: arm9/ov017 @ 0x21d6858; symbol: data_ov017_021d6858.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 9911000015000000002c000000040000000000000000000000000000.
// Observed span: 28 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
extern Triple GraphicsAllocatePoolsReserveVramAndCopyState_UnknownRoleInitializedBytes_Variant4[],GraphicsAllocatePoolsReserveVramAndCopyState_UnknownRoleInitializedBytes_Variant6[],GraphicsAllocatePoolsReserveVramAndCopyState_UnknownRoleInitializedBytes_Variant5[];
void* AllocatorUnion_AllocateFourByteAligned(void*,unsigned);
void _ZN13SafeAllocator11CreateTypeAEPvj(void*,void*,unsigned);
void VRAM_SaveStateAndReserveImagePaletteBytes(void*,unsigned,unsigned);
unsigned NNS_GfdAllocFrmTexVram(unsigned,int,unsigned);
void _Z28RestoreTextureImageVRAMStatePKj(void*);
void _Z30RestoreTexturePaletteVRAMStatePK23TexturePaletteVRAMState(void*);
}
// Original: arm9/ov017 @ 0x021A0C0C; symbol: Graphics_InitializeAllocatorAndVramReservations; size: 0x160.
extern "C" void Graphics_AllocatePoolsReserveVramAndCopyState(char* p){
unsigned size;
for(int i=0;(size=GraphicsAllocatePoolsReserveVramAndCopyState_UnknownRoleInitializedBytes_Variant8[i].value)!=0;i++){
void* mem=AllocatorUnion_AllocateFourByteAligned(Main_UnknownRoleZeroInitializedStorage_Variant3,size);
_ZN13SafeAllocator11CreateTypeAEPvj(p+0x38+GraphicsAllocatePoolsReserveVramAndCopyState_UnknownRoleInitializedBytes_Variant7[i].value*0x14,mem,size);
}
_Z28RestoreTextureImageVRAMStatePKj(p+0x2a78);
_Z30RestoreTexturePaletteVRAMStatePK23TexturePaletteVRAMState(p+0x2ad0);
NNS_GfdAllocFrmTexVram(0x20000,0,0);
for(int i=0;GraphicsAllocatePoolsReserveVramAndCopyState_UnknownRoleInitializedBytes_Variant2[i].value;i++)
VRAM_SaveStateAndReserveImagePaletteBytes(p+0x2cc+GraphicsAllocatePoolsReserveVramAndCopyState_UnknownRoleInitializedBytes[i].value*0x70,GraphicsAllocatePoolsReserveVramAndCopyState_UnknownRoleInitializedBytes_Variant2[i].value,GraphicsAllocatePoolsReserveVramAndCopyState_UnknownRoleInitializedBytes_Variant3[i].value);
_Z28RestoreTextureImageVRAMStatePKj(p+0x2aa8);
for(int i=0;GraphicsAllocatePoolsReserveVramAndCopyState_UnknownRoleInitializedBytes_Variant5[i].value;i++)
VRAM_SaveStateAndReserveImagePaletteBytes(p+0x2cc+GraphicsAllocatePoolsReserveVramAndCopyState_UnknownRoleInitializedBytes_Variant4[i].value*0x70,GraphicsAllocatePoolsReserveVramAndCopyState_UnknownRoleInitializedBytes_Variant5[i].value,GraphicsAllocatePoolsReserveVramAndCopyState_UnknownRoleInitializedBytes_Variant6[i].value);
*(Block*)(p+0xf0c)=*(Block*)(p+0xbfc);
*(Block*)(p+0xf34)=*(Block*)(p+0xc24);
*(unsigned*)(p+0xf5c)=*(unsigned*)(p+0xc4c);
*(unsigned*)(p+0xf60)=*(unsigned*)(p+0xc50);
*(Two*)(p+0xf64)=*(Two*)(p+0xc54);
*(Two*)(p+0xf6c)=*(Two*)(p+0xc5c);
*(unsigned*)(p+0xf74)=*(unsigned*)(p+0xc64);
*(unsigned*)(p+0xf78)=*(unsigned*)(p+0xc68);
}

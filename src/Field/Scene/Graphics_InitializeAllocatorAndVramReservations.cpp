#include <globaldefs.h>
ARM
struct Pair {unsigned value,pad;};
struct Triple {unsigned value,pad[2];};
extern "C" {
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern char Main_UnknownRoleZeroInitializedStorage_Variant3[];
// Original data: arm9/ov017 @ 0x21d6830; symbol: data_ov017_021d6830.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 14000000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
// Original data: arm9/ov017 @ 0x21d6834; symbol: data_ov017_021d6834.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00200000000000000030040007000000006003000000000000000000.
// Observed span: 28 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
extern Pair GraphicsInitializeAllocatorAndVramReservations_UnknownRoleInitializedBytes_Variant7[],GraphicsInitializeAllocatorAndVramReservations_UnknownRoleInitializedBytes_Variant8[];
// Original data: arm9/ov017 @ 0x21d66f8; symbol: data_ov017_021d66f8.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00000000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
// Original data: arm9/ov017 @ 0x21d66fc; symbol: data_ov017_021d66fc.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00000400.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
// Original data: arm9/ov017 @ 0x21d6700; symbol: data_ov017_021d6700.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00100000000000000000000000000000.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
extern Triple GraphicsInitializeAllocatorAndVramReservations_UnknownRoleInitializedBytes[],GraphicsInitializeAllocatorAndVramReservations_UnknownRoleInitializedBytes_Variant3[],GraphicsInitializeAllocatorAndVramReservations_UnknownRoleInitializedBytes_Variant2[];
// Original data: arm9/ov017 @ 0x21d6740; symbol: data_ov017_021d6740.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 07000000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
// Original data: arm9/ov017 @ 0x21d6744; symbol: data_ov017_021d6744.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00400000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
// Original data: arm9/ov017 @ 0x21d6748; symbol: data_ov017_021d6748.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00040000000000000000000000000000.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
extern Triple GraphicsInitializeAllocatorAndVramReservations_UnknownRoleInitializedBytes_Variant4[],GraphicsInitializeAllocatorAndVramReservations_UnknownRoleInitializedBytes_Variant6[],GraphicsInitializeAllocatorAndVramReservations_UnknownRoleInitializedBytes_Variant5[];
void* AllocatorUnion_AllocateFourByteAligned(void*,unsigned);
void _ZN13SafeAllocator11CreateTypeAEPvj(void*,void*,unsigned);
void VRAM_SaveStateAndReserveImagePaletteBytes(void*,unsigned,unsigned);
void _Z28RestoreTextureImageVRAMStatePKj(void*);
void _Z30RestoreTexturePaletteVRAMStatePK23TexturePaletteVRAMState(void*);
}
// Original: arm9/ov017 @ 0x021A0C0C; symbol: func_ov017_021a0c0c; size: 0x160.
extern "C" void Graphics_InitializeAllocatorAndVramReservations(char* p){
unsigned size;
for(int i=0;(size=GraphicsInitializeAllocatorAndVramReservations_UnknownRoleInitializedBytes_Variant8[i].value)!=0;i++){
void* mem=AllocatorUnion_AllocateFourByteAligned(Main_UnknownRoleZeroInitializedStorage_Variant3,size);
_ZN13SafeAllocator11CreateTypeAEPvj(p+0x38+GraphicsInitializeAllocatorAndVramReservations_UnknownRoleInitializedBytes_Variant7[i].value*0x14,mem,size);
}
_Z28RestoreTextureImageVRAMStatePKj(p+0x2a78);
_Z30RestoreTexturePaletteVRAMStatePK23TexturePaletteVRAMState(p+0x2ad0);
for(int i=0;GraphicsInitializeAllocatorAndVramReservations_UnknownRoleInitializedBytes_Variant2[i].value;i++)
VRAM_SaveStateAndReserveImagePaletteBytes(p+0x2cc+GraphicsInitializeAllocatorAndVramReservations_UnknownRoleInitializedBytes[i].value*0x70,GraphicsInitializeAllocatorAndVramReservations_UnknownRoleInitializedBytes_Variant2[i].value,GraphicsInitializeAllocatorAndVramReservations_UnknownRoleInitializedBytes_Variant3[i].value);
_Z28RestoreTextureImageVRAMStatePKj(p+0x2aa8);
for(int i=0;GraphicsInitializeAllocatorAndVramReservations_UnknownRoleInitializedBytes_Variant5[i].value;i++)
VRAM_SaveStateAndReserveImagePaletteBytes(p+0x2cc+GraphicsInitializeAllocatorAndVramReservations_UnknownRoleInitializedBytes_Variant4[i].value*0x70,GraphicsInitializeAllocatorAndVramReservations_UnknownRoleInitializedBytes_Variant5[i].value,GraphicsInitializeAllocatorAndVramReservations_UnknownRoleInitializedBytes_Variant6[i].value);
VRAM_SaveStateAndReserveImagePaletteBytes(p+0xe9c,0x8000,0x400);
VRAM_SaveStateAndReserveImagePaletteBytes(p+0xf0c,0x4000,0x400);
}

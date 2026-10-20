#include <globaldefs.h>
ARM
struct AllocatorUnion;struct State;
extern "C" void* AllocatorUnion_AllocateFourByteAligned(AllocatorUnion*,unsigned);
extern "C" void _ZN13SafeAllocator11CreateTypeAEPvj(void*,void*,unsigned);
extern "C" void VRAM_SaveStateAndReserveImagePaletteBytes(State*,unsigned,unsigned);
extern "C" unsigned NNS_GfdAllocFrmTexVram(unsigned,int,unsigned);
extern "C" void _Z28RestoreTextureImageVRAMStatePKj(void*);
extern "C" void _Z30RestoreTexturePaletteVRAMStatePK23TexturePaletteVRAMState(void*);
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char Main_UnknownRoleZeroInitializedStorage_Variant3[];
struct Pair { unsigned value,pad; };
struct Triple { unsigned value,pad1,pad2; };
// Original data: arm9/ov017 @ 0x21d6788; symbol: data_ov017_021d6788.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00000000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
// Original data: arm9/ov017 @ 0x21d678c; symbol: data_ov017_021d678c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00b0040007000000000003000000000000000000.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
extern "C" Pair GraphicsInitializeTableDrivenAllocatorAndVramReservations_UnknownRoleInitializedBytes_Variant7[],GraphicsInitializeTableDrivenAllocatorAndVramReservations_UnknownRoleInitializedBytes_Variant8[];
// Original data: arm9/ov017 @ 0x21d66b0; symbol: data_ov017_021d66b0.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00000000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
// Original data: arm9/ov017 @ 0x21d66b4; symbol: data_ov017_021d66b4.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00000200.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
// Original data: arm9/ov017 @ 0x21d66b8; symbol: data_ov017_021d66b8.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00100000000000000000000000000000.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
// Original data: arm9/ov017 @ 0x21d6728; symbol: data_ov017_021d6728.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 07000000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
// Original data: arm9/ov017 @ 0x21d672c; symbol: data_ov017_021d672c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00400000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
// Original data: arm9/ov017 @ 0x21d6730; symbol: data_ov017_021d6730.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00080000000000000000000000000000.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
extern "C" Triple GraphicsInitializeTableDrivenAllocatorAndVramReservations_UnknownRoleInitializedBytes[],GraphicsInitializeTableDrivenAllocatorAndVramReservations_UnknownRoleInitializedBytes_Variant3[],GraphicsInitializeTableDrivenAllocatorAndVramReservations_UnknownRoleInitializedBytes_Variant2[],GraphicsInitializeTableDrivenAllocatorAndVramReservations_UnknownRoleInitializedBytes_Variant4[],GraphicsInitializeTableDrivenAllocatorAndVramReservations_UnknownRoleInitializedBytes_Variant6[],GraphicsInitializeTableDrivenAllocatorAndVramReservations_UnknownRoleInitializedBytes_Variant5[];
// Original: arm9/ov017 @ 0x021A0DD0; symbol: func_ov017_021a0dd0; size: 0x170.
extern "C" void Graphics_InitializeTableDrivenAllocatorAndVramReservations(char* p) {
 unsigned size;
 for(int i=0;(size=GraphicsInitializeTableDrivenAllocatorAndVramReservations_UnknownRoleInitializedBytes_Variant8[i].value)!=0;i++) {
  void* memory=AllocatorUnion_AllocateFourByteAligned((AllocatorUnion*)Main_UnknownRoleZeroInitializedStorage_Variant3,size);
  _ZN13SafeAllocator11CreateTypeAEPvj(p+0x38+GraphicsInitializeTableDrivenAllocatorAndVramReservations_UnknownRoleInitializedBytes_Variant7[i].value*20,memory,size);
 }
 _Z28RestoreTextureImageVRAMStatePKj(p+0x2a78);
 _Z30RestoreTexturePaletteVRAMStatePK23TexturePaletteVRAMState(p+0x2ad0);
 NNS_GfdAllocFrmTexVram(0x20000,0,0);
 for(int i=0;GraphicsInitializeTableDrivenAllocatorAndVramReservations_UnknownRoleInitializedBytes_Variant2[i].value;i++) {
  VRAM_SaveStateAndReserveImagePaletteBytes((State*)(p+0x2cc+GraphicsInitializeTableDrivenAllocatorAndVramReservations_UnknownRoleInitializedBytes[i].value*0x70),GraphicsInitializeTableDrivenAllocatorAndVramReservations_UnknownRoleInitializedBytes_Variant2[i].value,GraphicsInitializeTableDrivenAllocatorAndVramReservations_UnknownRoleInitializedBytes_Variant3[i].value);
 }
 _Z28RestoreTextureImageVRAMStatePKj(p+0x2aa8);
 for(int i=0;GraphicsInitializeTableDrivenAllocatorAndVramReservations_UnknownRoleInitializedBytes_Variant5[i].value;i++) {
  VRAM_SaveStateAndReserveImagePaletteBytes((State*)(p+0x2cc+GraphicsInitializeTableDrivenAllocatorAndVramReservations_UnknownRoleInitializedBytes_Variant4[i].value*0x70),GraphicsInitializeTableDrivenAllocatorAndVramReservations_UnknownRoleInitializedBytes_Variant5[i].value,GraphicsInitializeTableDrivenAllocatorAndVramReservations_UnknownRoleInitializedBytes_Variant6[i].value);
 }
 VRAM_SaveStateAndReserveImagePaletteBytes((State*)(p+0xe9c),0x8000,0x400);
 VRAM_SaveStateAndReserveImagePaletteBytes((State*)(p+0xf0c),0x4000,0x400);
}

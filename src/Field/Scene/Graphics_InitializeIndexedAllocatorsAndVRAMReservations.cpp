#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char Main_UnknownRoleZeroInitializedStorage_Variant3[];
struct Entry2 {unsigned v,pad;};
struct Entry3 {unsigned v,pad[2];};
// Original data: arm9/ov017 @ 0x21d67a0; symbol: data_ov017_021d67a0.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00000000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
// Original data: arm9/ov017 @ 0x21d67a4; symbol: data_ov017_021d67a4.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0040060007000000007001000000000000000000.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
extern "C" Entry2 GraphicsInitializeIndexedAllocatorsAndVRAMReservations_UnknownRoleInitializedBytes_Variant4[],GraphicsInitializeIndexedAllocatorsAndVRAMReservations_UnknownRoleInitializedBytes_Variant5[];
// Original data: arm9/ov017 @ 0x21d66e0; symbol: data_ov017_021d66e0.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00000000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
// Original data: arm9/ov017 @ 0x21d66e4; symbol: data_ov017_021d66e4.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00000200.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
// Original data: arm9/ov017 @ 0x21d66e8; symbol: data_ov017_021d66e8.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00100000000000000000000000000000.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
extern "C" Entry3 GraphicsInitializeIndexedAllocatorsAndVRAMReservations_UnknownRoleInitializedBytes[],GraphicsInitializeIndexedAllocatorsAndVRAMReservations_UnknownRoleInitializedBytes_Variant3[],GraphicsInitializeIndexedAllocatorsAndVRAMReservations_UnknownRoleInitializedBytes_Variant2[];
// Original data: arm9/ov017 @ 0x21d67d0; symbol: data_ov017_021d67d0.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 07000000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
// Original data: arm9/ov017 @ 0x21d67d4; symbol: data_ov017_021d67d4.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00400000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
// Original data: arm9/ov017 @ 0x21d67d8; symbol: data_ov017_021d67d8.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00080000000000000000000000000000.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
extern "C" Entry3 GraphicsInitializeIndexedAllocatorsAndVRAMReservations_UnknownRoleInitializedBytes_Variant6[],GraphicsInitializeIndexedAllocatorsAndVRAMReservations_UnknownRoleInitializedBytes_Variant8[],GraphicsInitializeIndexedAllocatorsAndVRAMReservations_UnknownRoleInitializedBytes_Variant7[];
extern "C" void* AllocatorUnion_AllocateFourByteAligned(void*,unsigned);
extern "C" void _ZN13SafeAllocator11CreateTypeAEPvj(void*,void*,unsigned);
extern "C" void VRAM_SaveStateAndReserveImagePaletteBytes(void*,unsigned,unsigned);
extern "C" unsigned NNS_GfdAllocFrmTexVram(unsigned,int,unsigned);
extern "C" void _Z28RestoreTextureImageVRAMStatePKj(void*);
extern "C" void _Z30RestoreTexturePaletteVRAMStatePK23TexturePaletteVRAMState(void*);
// Original: arm9/ov017 @ 0x021A0FA4; symbol: func_ov017_021a0fa4; size: 0x170.
extern "C" void Graphics_InitializeIndexedAllocatorsAndVRAMReservations(char* self) {
 unsigned size;
 for(int i=0;(size=GraphicsInitializeIndexedAllocatorsAndVRAMReservations_UnknownRoleInitializedBytes_Variant5[i].v)!=0;i++) {
  void* mem=AllocatorUnion_AllocateFourByteAligned(Main_UnknownRoleZeroInitializedStorage_Variant3,size);
  _ZN13SafeAllocator11CreateTypeAEPvj(self+0x38+GraphicsInitializeIndexedAllocatorsAndVRAMReservations_UnknownRoleInitializedBytes_Variant4[i].v*20,mem,size);
 }
 _Z28RestoreTextureImageVRAMStatePKj(self+0x2a78);
 _Z30RestoreTexturePaletteVRAMStatePK23TexturePaletteVRAMState(self+0x2ad0);
 NNS_GfdAllocFrmTexVram(0x20000,0,0);
 for(int i=0;GraphicsInitializeIndexedAllocatorsAndVRAMReservations_UnknownRoleInitializedBytes_Variant2[i].v;i++) {
  VRAM_SaveStateAndReserveImagePaletteBytes(self+0x2cc+GraphicsInitializeIndexedAllocatorsAndVRAMReservations_UnknownRoleInitializedBytes[i].v*0x70,GraphicsInitializeIndexedAllocatorsAndVRAMReservations_UnknownRoleInitializedBytes_Variant2[i].v,GraphicsInitializeIndexedAllocatorsAndVRAMReservations_UnknownRoleInitializedBytes_Variant3[i].v);
 }
 _Z28RestoreTextureImageVRAMStatePKj(self+0x2aa8);
 for(int i=0;GraphicsInitializeIndexedAllocatorsAndVRAMReservations_UnknownRoleInitializedBytes_Variant7[i].v;i++) {
  VRAM_SaveStateAndReserveImagePaletteBytes(self+0x2cc+GraphicsInitializeIndexedAllocatorsAndVRAMReservations_UnknownRoleInitializedBytes_Variant6[i].v*0x70,GraphicsInitializeIndexedAllocatorsAndVRAMReservations_UnknownRoleInitializedBytes_Variant7[i].v,GraphicsInitializeIndexedAllocatorsAndVRAMReservations_UnknownRoleInitializedBytes_Variant8[i].v);
 }
 VRAM_SaveStateAndReserveImagePaletteBytes(self+0xe9c,0x8000,0x400);
 VRAM_SaveStateAndReserveImagePaletteBytes(self+0xf0c,0x4000,0x400);
}

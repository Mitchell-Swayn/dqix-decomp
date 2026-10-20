#include <globaldefs.h>
ARM
struct AllocatorUnion; struct State;
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" AllocatorUnion Main_UnknownRoleZeroInitializedStorage_Variant3;
struct Pair { unsigned value,pad; };
struct Triple { unsigned value,pad[2]; };
// Original data: arm9/ov017 @ 0x21d6710; symbol: data_ov017_021d6710.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00000000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
// Original data: arm9/ov017 @ 0x21d6714; symbol: data_ov017_021d6714.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00b0040007000000000003000000000000000000.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
extern "C" Pair GraphicsInitializeTableDrivenAllocatorsAndVRAM_UnknownRoleInitializedBytes[],GraphicsInitializeTableDrivenAllocatorsAndVRAM_UnknownRoleInitializedBytes_Variant2[];
// Original data: arm9/ov017 @ 0x21d6770; symbol: data_ov017_021d6770.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 07000000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
// Original data: arm9/ov017 @ 0x21d6774; symbol: data_ov017_021d6774.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00400000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
// Original data: arm9/ov017 @ 0x21d6778; symbol: data_ov017_021d6778.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00080000000000000000000000000000.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
// Original data: arm9/ov017 @ 0x21d67b8; symbol: data_ov017_021d67b8.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00000000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
// Original data: arm9/ov017 @ 0x21d67bc; symbol: data_ov017_021d67bc.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00000200.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
// Original data: arm9/ov017 @ 0x21d67c0; symbol: data_ov017_021d67c0.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00100000000000000000000000000000.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
extern "C" Triple GraphicsInitializeTableDrivenAllocatorsAndVRAM_UnknownRoleInitializedBytes_Variant6[],GraphicsInitializeTableDrivenAllocatorsAndVRAM_UnknownRoleInitializedBytes_Variant8[],GraphicsInitializeTableDrivenAllocatorsAndVRAM_UnknownRoleInitializedBytes_Variant7[],GraphicsInitializeTableDrivenAllocatorsAndVRAM_UnknownRoleInitializedBytes_Variant3[],GraphicsInitializeTableDrivenAllocatorsAndVRAM_UnknownRoleInitializedBytes_Variant5[],GraphicsInitializeTableDrivenAllocatorsAndVRAM_UnknownRoleInitializedBytes_Variant4[];
extern "C" void* AllocatorUnion_AllocateFourByteAligned(AllocatorUnion*,unsigned);
extern "C" void _ZN13SafeAllocator11CreateTypeAEPvj(void*,void*,unsigned);
extern "C" void VRAM_SaveStateAndReserveImagePaletteBytes(State*,unsigned,unsigned);
extern "C" unsigned NNS_GfdAllocFrmTexVram(unsigned,int,unsigned);
extern "C" void _Z28RestoreTextureImageVRAMStatePKj(const unsigned*);
extern "C" void _Z30RestoreTexturePaletteVRAMStatePK23TexturePaletteVRAMState(const void*);
// Original: arm9/ov017 @ 0x021A07F4; symbol: func_ov017_021a07f4; size: 0x170.
extern "C" void Graphics_InitializeTableDrivenAllocatorsAndVRAM(char* p) {
 unsigned size;
 for(int i=0;(size=GraphicsInitializeTableDrivenAllocatorsAndVRAM_UnknownRoleInitializedBytes_Variant2[i].value)!=0;++i) {
  void* memory=AllocatorUnion_AllocateFourByteAligned(&Main_UnknownRoleZeroInitializedStorage_Variant3,size);
  _ZN13SafeAllocator11CreateTypeAEPvj(p+0x38+GraphicsInitializeTableDrivenAllocatorsAndVRAM_UnknownRoleInitializedBytes[i].value*0x14,memory,size);
 }
 _Z28RestoreTextureImageVRAMStatePKj((unsigned*)(p+0x2a78));
 _Z30RestoreTexturePaletteVRAMStatePK23TexturePaletteVRAMState(p+0x2ad0);
 NNS_GfdAllocFrmTexVram(0x20000,0,0);
 for(int i=0;GraphicsInitializeTableDrivenAllocatorsAndVRAM_UnknownRoleInitializedBytes_Variant7[i].value!=0;++i) {
  VRAM_SaveStateAndReserveImagePaletteBytes((State*)(p+0x2cc+GraphicsInitializeTableDrivenAllocatorsAndVRAM_UnknownRoleInitializedBytes_Variant6[i].value*0x70),GraphicsInitializeTableDrivenAllocatorsAndVRAM_UnknownRoleInitializedBytes_Variant7[i].value,GraphicsInitializeTableDrivenAllocatorsAndVRAM_UnknownRoleInitializedBytes_Variant8[i].value);
 }
 _Z28RestoreTextureImageVRAMStatePKj((unsigned*)(p+0x2aa8));
 for(int i=0;GraphicsInitializeTableDrivenAllocatorsAndVRAM_UnknownRoleInitializedBytes_Variant4[i].value!=0;++i) {
  VRAM_SaveStateAndReserveImagePaletteBytes((State*)(p+0x2cc+GraphicsInitializeTableDrivenAllocatorsAndVRAM_UnknownRoleInitializedBytes_Variant3[i].value*0x70),GraphicsInitializeTableDrivenAllocatorsAndVRAM_UnknownRoleInitializedBytes_Variant4[i].value,GraphicsInitializeTableDrivenAllocatorsAndVRAM_UnknownRoleInitializedBytes_Variant5[i].value);
 }
 VRAM_SaveStateAndReserveImagePaletteBytes((State*)(p+0xe9c),0x8000,0x400);
 VRAM_SaveStateAndReserveImagePaletteBytes((State*)(p+0xf0c),0x4000,0x400);
}

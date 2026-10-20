#include <globaldefs.h>
ARM
extern "C" void* AllocatorUnion_AllocateFourByteAligned(void*,unsigned);
extern "C" void _ZN13SafeAllocator11CreateTypeAEPvj(void*,void*,unsigned);
extern "C" void VRAM_SaveStateAndReserveImagePaletteBytes(void*,unsigned,unsigned);
extern "C" void _Z28RestoreTextureImageVRAMStatePKj(void*);
extern "C" void _Z30RestoreTexturePaletteVRAMStatePK23TexturePaletteVRAMState(void*);
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char Main_UnknownRoleZeroInitializedStorage_Variant3[];
struct Pair { int v; int pad; };
struct Triple { int v; int pad[2]; };
// Original data: arm9/ov017 @ 0x21d66c8; symbol: data_ov017_021d66c8.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00000000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
// Original data: arm9/ov017 @ 0x21d66cc; symbol: data_ov017_021d66cc.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00b0040007000000000003000000000000000000.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
extern "C" Pair GraphicsAllocatePoolsAndReserveVram_UnknownRoleInitializedBytes[],GraphicsAllocatePoolsAndReserveVram_UnknownRoleInitializedBytes_Variant2[];
// Original data: arm9/ov017 @ 0x21d6818; symbol: data_ov017_021d6818.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00000000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
// Original data: arm9/ov017 @ 0x21d681c; symbol: data_ov017_021d681c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00000400.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
// Original data: arm9/ov017 @ 0x21d6820; symbol: data_ov017_021d6820.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00100000000000000000000000000000.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
extern "C" Triple GraphicsAllocatePoolsAndReserveVram_UnknownRoleInitializedBytes_Variant6[],GraphicsAllocatePoolsAndReserveVram_UnknownRoleInitializedBytes_Variant8[],GraphicsAllocatePoolsAndReserveVram_UnknownRoleInitializedBytes_Variant7[];
// Original data: arm9/ov017 @ 0x21d6800; symbol: data_ov017_021d6800.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 07000000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
// Original data: arm9/ov017 @ 0x21d6804; symbol: data_ov017_021d6804.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00400000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
// Original data: arm9/ov017 @ 0x21d6808; symbol: data_ov017_021d6808.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00040000000000000000000000000000.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
extern "C" Triple GraphicsAllocatePoolsAndReserveVram_UnknownRoleInitializedBytes_Variant3[],GraphicsAllocatePoolsAndReserveVram_UnknownRoleInitializedBytes_Variant5[],GraphicsAllocatePoolsAndReserveVram_UnknownRoleInitializedBytes_Variant4[];
// Original: arm9/ov017 @ 0x021A0630; symbol: func_ov017_021a0630; size: 0x160.
extern "C" void Graphics_AllocatePoolsAndReserveVram(char* p) {
 int i;
 for(i=0;GraphicsAllocatePoolsAndReserveVram_UnknownRoleInitializedBytes_Variant2[i].v;i++) {
 unsigned size=GraphicsAllocatePoolsAndReserveVram_UnknownRoleInitializedBytes_Variant2[i].v;
 void* mem=AllocatorUnion_AllocateFourByteAligned(Main_UnknownRoleZeroInitializedStorage_Variant3,size);
 _ZN13SafeAllocator11CreateTypeAEPvj(p+0x38+GraphicsAllocatePoolsAndReserveVram_UnknownRoleInitializedBytes[i].v*20,mem,size);
 }
 _Z28RestoreTextureImageVRAMStatePKj(p+0x2a78);
 _Z30RestoreTexturePaletteVRAMStatePK23TexturePaletteVRAMState(p+0x2ad0);
 for(i=0;GraphicsAllocatePoolsAndReserveVram_UnknownRoleInitializedBytes_Variant7[i].v;i++)
 VRAM_SaveStateAndReserveImagePaletteBytes(p+0x2cc+GraphicsAllocatePoolsAndReserveVram_UnknownRoleInitializedBytes_Variant6[i].v*0x70,GraphicsAllocatePoolsAndReserveVram_UnknownRoleInitializedBytes_Variant7[i].v,GraphicsAllocatePoolsAndReserveVram_UnknownRoleInitializedBytes_Variant8[i].v);
 _Z28RestoreTextureImageVRAMStatePKj(p+0x2aa8);
 for(i=0;GraphicsAllocatePoolsAndReserveVram_UnknownRoleInitializedBytes_Variant4[i].v;i++)
 VRAM_SaveStateAndReserveImagePaletteBytes(p+0x2cc+GraphicsAllocatePoolsAndReserveVram_UnknownRoleInitializedBytes_Variant3[i].v*0x70,GraphicsAllocatePoolsAndReserveVram_UnknownRoleInitializedBytes_Variant4[i].v,GraphicsAllocatePoolsAndReserveVram_UnknownRoleInitializedBytes_Variant5[i].v);
 VRAM_SaveStateAndReserveImagePaletteBytes(p+0xe9c,0x8000,0x400);
 VRAM_SaveStateAndReserveImagePaletteBytes(p+0xf0c,0x4000,0x400);
}

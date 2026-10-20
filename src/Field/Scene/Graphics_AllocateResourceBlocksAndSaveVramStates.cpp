#include <globaldefs.h>
ARM
struct AllocatorUnion;struct State;struct SafeAllocator;
extern "C" void* AllocatorUnion_AllocateFourByteAligned(AllocatorUnion*,unsigned);
extern "C" void _ZN13SafeAllocator11CreateTypeAEPvj(void*,void*,unsigned);
extern "C" void VRAM_SaveStateAndReserveImagePaletteBytes(State*,unsigned,unsigned);
extern "C" unsigned NNS_GfdAllocFrmTexVram(unsigned,int,unsigned);
extern "C" void _Z25SaveTextureImageVRAMStatePj(void*);
extern "C" void _Z27SaveTexturePaletteVRAMStateP23TexturePaletteVRAMState(void*);
extern "C" void Memory_AllocateTenSizedBlocksAndFourExtraBuffers(unsigned char*,SafeAllocator*,int);
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char Main_UnknownRoleZeroInitializedStorage_Variant3[];
struct Pair { unsigned value,pad; };
struct Triple { unsigned value,pad1,pad2; };
struct Block {short pad,index; char rest[0x5e8];};
// Original data: arm9/ov017 @ 0x21d6984; symbol: data_ov017_021d6984.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 01000000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
// Original data: arm9/ov017 @ 0x21d6988; symbol: data_ov017_021d6988.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex b016010002000000b016010003000000b016010004000000b016010008000000802c000009000000802c00000a000000802c00000b000000802c000006000000 ...; full span in module reference.
// Observed span: 172 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
extern "C" Pair GraphicsAllocateResourceBlocksAndSaveVramStates_UnknownRoleInitializedBytes_Variant4[],GraphicsAllocateResourceBlocksAndSaveVramStates_UnknownRoleInitializedBytes_Variant5[];
// Original data: arm9/ov017 @ 0x21d6924; symbol: data_ov017_021d6924.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 05000000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
// Original data: arm9/ov017 @ 0x21d6928; symbol: data_ov017_021d6928.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00880000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
// Original data: arm9/ov017 @ 0x21d692c; symbol: data_ov017_021d692c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 100500000600000000380000400100000d0000000040000020000000010000000040000000060000020000000040000000060000030000000040000000060000 ...; full span in module reference.
// Observed span: 88 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
extern "C" Triple GraphicsAllocateResourceBlocksAndSaveVramStates_UnknownRoleInitializedBytes[],GraphicsAllocateResourceBlocksAndSaveVramStates_UnknownRoleInitializedBytes_Variant3[],GraphicsAllocateResourceBlocksAndSaveVramStates_UnknownRoleInitializedBytes_Variant2[];
// Original: arm9/ov017 @ 0x021A02F0; symbol: func_ov017_021a02f0; size: 0x180.
extern "C" void Graphics_AllocateResourceBlocksAndSaveVramStates(char* p) {
 unsigned size;
 for(int i=0;(size=GraphicsAllocateResourceBlocksAndSaveVramStates_UnknownRoleInitializedBytes_Variant5[i].value)!=0;i++) {
  void* memory=AllocatorUnion_AllocateFourByteAligned((AllocatorUnion*)Main_UnknownRoleZeroInitializedStorage_Variant3,size);
  _ZN13SafeAllocator11CreateTypeAEPvj(p+0x38+GraphicsAllocateResourceBlocksAndSaveVramStates_UnknownRoleInitializedBytes_Variant4[i].value*20,memory,size);
 }
 _Z25SaveTextureImageVRAMStatePj(p+0x2a78);
 _Z27SaveTexturePaletteVRAMStateP23TexturePaletteVRAMState(p+0x2aa0);
 NNS_GfdAllocFrmTexVram(0x20000,0,0);
 NNS_GfdAllocFrmTexVram(0x20000,0,0);
 for(int i=0;GraphicsAllocateResourceBlocksAndSaveVramStates_UnknownRoleInitializedBytes_Variant2[i].value;i++) {
  VRAM_SaveStateAndReserveImagePaletteBytes((State*)(p+0x2cc+GraphicsAllocateResourceBlocksAndSaveVramStates_UnknownRoleInitializedBytes[i].value*0x70),GraphicsAllocateResourceBlocksAndSaveVramStates_UnknownRoleInitializedBytes_Variant2[i].value,GraphicsAllocateResourceBlocksAndSaveVramStates_UnknownRoleInitializedBytes_Variant3[i].value);
  if(i==1) {
   _Z25SaveTextureImageVRAMStatePj(p+0x2ad8);
   _Z27SaveTexturePaletteVRAMStateP23TexturePaletteVRAMState(p+0x2b00);
  }
 }
 _Z25SaveTextureImageVRAMStatePj(p+0x2aa8);
 _Z27SaveTexturePaletteVRAMStateP23TexturePaletteVRAMState(p+0x2ad0);
 for(int i=0;i<4;i++) {
  int offset=i*0x5ec;
  Memory_AllocateTenSizedBlocksAndFourExtraBuffers((unsigned char*)(p+0x12c8+offset),(SafeAllocator*)(p+0x38+(i+1)*20),(int)(p+0x2cc+(i+1)*0x70));
  *(short*)(p+offset+0x12ca)=i;
 }
}

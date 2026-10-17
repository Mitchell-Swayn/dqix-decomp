#include <globaldefs.h>
ARM
extern "C" char data_02114e20[];
struct Entry2 {unsigned v,pad;};
struct Entry3 {unsigned v,pad[2];};
extern "C" Entry2 data_ov017_021d67a0[],data_ov017_021d67a4[];
extern "C" Entry3 data_ov017_021d66e0[],data_ov017_021d66e8[],data_ov017_021d66e4[];
extern "C" Entry3 data_ov017_021d67d0[],data_ov017_021d67d8[],data_ov017_021d67d4[];
extern "C" void* AllocatorUnion_AllocateFourByteAligned(void*,unsigned);
extern "C" void _ZN13SafeAllocator11CreateTypeAEPvj(void*,void*,unsigned);
extern "C" void VRAM_SaveStateAndReserveImagePaletteBytes(void*,unsigned,unsigned);
extern "C" unsigned NNS_GfdAllocFrmTexVram(unsigned,int,unsigned);
extern "C" void _Z28RestoreTextureImageVRAMStatePKj(void*);
extern "C" void _Z30RestoreTexturePaletteVRAMStatePK23TexturePaletteVRAMState(void*);
// Original: arm9/ov017 @ 0x021A0FA4; symbol: func_ov017_021a0fa4; size: 0x170.
extern "C" void Graphics_InitializeIndexedAllocatorsAndVRAMReservations(char* self) {
 unsigned size;
 for(int i=0;(size=data_ov017_021d67a4[i].v)!=0;i++) {
  void* mem=AllocatorUnion_AllocateFourByteAligned(data_02114e20,size);
  _ZN13SafeAllocator11CreateTypeAEPvj(self+0x38+data_ov017_021d67a0[i].v*20,mem,size);
 }
 _Z28RestoreTextureImageVRAMStatePKj(self+0x2a78);
 _Z30RestoreTexturePaletteVRAMStatePK23TexturePaletteVRAMState(self+0x2ad0);
 NNS_GfdAllocFrmTexVram(0x20000,0,0);
 for(int i=0;data_ov017_021d66e4[i].v;i++) {
  VRAM_SaveStateAndReserveImagePaletteBytes(self+0x2cc+data_ov017_021d66e0[i].v*0x70,data_ov017_021d66e4[i].v,data_ov017_021d66e8[i].v);
 }
 _Z28RestoreTextureImageVRAMStatePKj(self+0x2aa8);
 for(int i=0;data_ov017_021d67d4[i].v;i++) {
  VRAM_SaveStateAndReserveImagePaletteBytes(self+0x2cc+data_ov017_021d67d0[i].v*0x70,data_ov017_021d67d4[i].v,data_ov017_021d67d8[i].v);
 }
 VRAM_SaveStateAndReserveImagePaletteBytes(self+0xe9c,0x8000,0x400);
 VRAM_SaveStateAndReserveImagePaletteBytes(self+0xf0c,0x4000,0x400);
}

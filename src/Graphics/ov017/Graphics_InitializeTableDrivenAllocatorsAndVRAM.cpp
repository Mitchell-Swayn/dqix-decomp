#include <globaldefs.h>
ARM
struct AllocatorUnion; struct State;
extern "C" AllocatorUnion data_02114e20;
struct Pair { unsigned value,pad; };
struct Triple { unsigned value,pad[2]; };
extern "C" Pair data_ov017_021d6710[],data_ov017_021d6714[];
extern "C" Triple data_ov017_021d67b8[],data_ov017_021d67c0[],data_ov017_021d67bc[],data_ov017_021d6770[],data_ov017_021d6778[],data_ov017_021d6774[];
extern "C" void* AllocatorUnion_AllocateFourByteAligned(AllocatorUnion*,unsigned);
extern "C" void _ZN13SafeAllocator11CreateTypeAEPvj(void*,void*,unsigned);
extern "C" void VRAM_SaveStateAndReserveImagePaletteBytes(State*,unsigned,unsigned);
extern "C" unsigned NNS_GfdAllocFrmTexVram(unsigned,int,unsigned);
extern "C" void _Z28RestoreTextureImageVRAMStatePKj(const unsigned*);
extern "C" void _Z30RestoreTexturePaletteVRAMStatePK23TexturePaletteVRAMState(const void*);
// Original: arm9/ov017 @ 0x021A07F4; symbol: func_ov017_021a07f4; size: 0x170.
extern "C" void Graphics_InitializeTableDrivenAllocatorsAndVRAM(char* p) {
 unsigned size;
 for(int i=0;(size=data_ov017_021d6714[i].value)!=0;++i) {
  void* memory=AllocatorUnion_AllocateFourByteAligned(&data_02114e20,size);
  _ZN13SafeAllocator11CreateTypeAEPvj(p+0x38+data_ov017_021d6710[i].value*0x14,memory,size);
 }
 _Z28RestoreTextureImageVRAMStatePKj((unsigned*)(p+0x2a78));
 _Z30RestoreTexturePaletteVRAMStatePK23TexturePaletteVRAMState(p+0x2ad0);
 NNS_GfdAllocFrmTexVram(0x20000,0,0);
 for(int i=0;data_ov017_021d67bc[i].value!=0;++i) {
  VRAM_SaveStateAndReserveImagePaletteBytes((State*)(p+0x2cc+data_ov017_021d67b8[i].value*0x70),data_ov017_021d67bc[i].value,data_ov017_021d67c0[i].value);
 }
 _Z28RestoreTextureImageVRAMStatePKj((unsigned*)(p+0x2aa8));
 for(int i=0;data_ov017_021d6774[i].value!=0;++i) {
  VRAM_SaveStateAndReserveImagePaletteBytes((State*)(p+0x2cc+data_ov017_021d6770[i].value*0x70),data_ov017_021d6774[i].value,data_ov017_021d6778[i].value);
 }
 VRAM_SaveStateAndReserveImagePaletteBytes((State*)(p+0xe9c),0x8000,0x400);
 VRAM_SaveStateAndReserveImagePaletteBytes((State*)(p+0xf0c),0x4000,0x400);
}

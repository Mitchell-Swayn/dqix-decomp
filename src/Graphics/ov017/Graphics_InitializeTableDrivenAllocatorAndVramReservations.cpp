#include <globaldefs.h>
ARM
struct AllocatorUnion;struct State;
extern "C" void* AllocatorUnion_AllocateFourByteAligned(AllocatorUnion*,unsigned);
extern "C" void _ZN13SafeAllocator11CreateTypeAEPvj(void*,void*,unsigned);
extern "C" void VRAM_SaveStateAndReserveImagePaletteBytes(State*,unsigned,unsigned);
extern "C" unsigned NNS_GfdAllocFrmTexVram(unsigned,int,unsigned);
extern "C" void _Z28RestoreTextureImageVRAMStatePKj(void*);
extern "C" void _Z30RestoreTexturePaletteVRAMStatePK23TexturePaletteVRAMState(void*);
extern "C" char data_02114e20[];
struct Pair { unsigned value,pad; };
struct Triple { unsigned value,pad1,pad2; };
extern "C" Pair data_ov017_021d6788[],data_ov017_021d678c[];
extern "C" Triple data_ov017_021d66b0[],data_ov017_021d66b8[],data_ov017_021d66b4[],data_ov017_021d6728[],data_ov017_021d6730[],data_ov017_021d672c[];
// Original: arm9/ov017 @ 0x021A0DD0; symbol: func_ov017_021a0dd0; size: 0x170.
extern "C" void Graphics_InitializeTableDrivenAllocatorAndVramReservations(char* p) {
 unsigned size;
 for(int i=0;(size=data_ov017_021d678c[i].value)!=0;i++) {
  void* memory=AllocatorUnion_AllocateFourByteAligned((AllocatorUnion*)data_02114e20,size);
  _ZN13SafeAllocator11CreateTypeAEPvj(p+0x38+data_ov017_021d6788[i].value*20,memory,size);
 }
 _Z28RestoreTextureImageVRAMStatePKj(p+0x2a78);
 _Z30RestoreTexturePaletteVRAMStatePK23TexturePaletteVRAMState(p+0x2ad0);
 NNS_GfdAllocFrmTexVram(0x20000,0,0);
 for(int i=0;data_ov017_021d66b4[i].value;i++) {
  VRAM_SaveStateAndReserveImagePaletteBytes((State*)(p+0x2cc+data_ov017_021d66b0[i].value*0x70),data_ov017_021d66b4[i].value,data_ov017_021d66b8[i].value);
 }
 _Z28RestoreTextureImageVRAMStatePKj(p+0x2aa8);
 for(int i=0;data_ov017_021d672c[i].value;i++) {
  VRAM_SaveStateAndReserveImagePaletteBytes((State*)(p+0x2cc+data_ov017_021d6728[i].value*0x70),data_ov017_021d672c[i].value,data_ov017_021d6730[i].value);
 }
 VRAM_SaveStateAndReserveImagePaletteBytes((State*)(p+0xe9c),0x8000,0x400);
 VRAM_SaveStateAndReserveImagePaletteBytes((State*)(p+0xf0c),0x4000,0x400);
}

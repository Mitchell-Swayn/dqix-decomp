#include <globaldefs.h>
ARM
struct AllocatorUnion;struct State;struct SafeAllocator;
extern "C" void* AllocatorUnion_AllocateFourByteAligned(AllocatorUnion*,unsigned);
extern "C" void _ZN13SafeAllocator11CreateTypeAEPvj(void*,void*,unsigned);
extern "C" void VRAM_SaveStateAndReserveImagePaletteBytes(State*,unsigned,unsigned);
extern "C" unsigned NNS_GfdAllocFrmTexVram(unsigned,int,unsigned);
extern "C" void _Z25SaveTextureImageVRAMStatePj(void*);
extern "C" void _Z27SaveTexturePaletteVRAMStateP23TexturePaletteVRAMState(void*);
extern "C" void AllocateTenZeroedAllocatorBlocksAndExtraBuffer(unsigned char*,SafeAllocator*,int);
extern "C" char data_02114e20[];
struct Pair { unsigned value,pad; };
struct Triple { unsigned value,pad1,pad2; };
struct Block {short pad,index; char rest[0x5e8];};
extern "C" Pair data_ov017_021d6984[],data_ov017_021d6988[];
extern "C" Triple data_ov017_021d6924[],data_ov017_021d692c[],data_ov017_021d6928[];
// Original: arm9/ov017 @ 0x021A02F0; symbol: func_ov017_021a02f0; size: 0x180.
extern "C" void Graphics_AllocateResourceBlocksAndSaveVramStates(char* p) {
 unsigned size;
 for(int i=0;(size=data_ov017_021d6988[i].value)!=0;i++) {
  void* memory=AllocatorUnion_AllocateFourByteAligned((AllocatorUnion*)data_02114e20,size);
  _ZN13SafeAllocator11CreateTypeAEPvj(p+0x38+data_ov017_021d6984[i].value*20,memory,size);
 }
 _Z25SaveTextureImageVRAMStatePj(p+0x2a78);
 _Z27SaveTexturePaletteVRAMStateP23TexturePaletteVRAMState(p+0x2aa0);
 NNS_GfdAllocFrmTexVram(0x20000,0,0);
 NNS_GfdAllocFrmTexVram(0x20000,0,0);
 for(int i=0;data_ov017_021d6928[i].value;i++) {
  VRAM_SaveStateAndReserveImagePaletteBytes((State*)(p+0x2cc+data_ov017_021d6924[i].value*0x70),data_ov017_021d6928[i].value,data_ov017_021d692c[i].value);
  if(i==1) {
   _Z25SaveTextureImageVRAMStatePj(p+0x2ad8);
   _Z27SaveTexturePaletteVRAMStateP23TexturePaletteVRAMState(p+0x2b00);
  }
 }
 _Z25SaveTextureImageVRAMStatePj(p+0x2aa8);
 _Z27SaveTexturePaletteVRAMStateP23TexturePaletteVRAMState(p+0x2ad0);
 for(int i=0;i<4;i++) {
  int offset=i*0x5ec;
  AllocateTenZeroedAllocatorBlocksAndExtraBuffer((unsigned char*)(p+0x12c8+offset),(SafeAllocator*)(p+0x38+(i+1)*20),(int)(p+0x2cc+(i+1)*0x70));
  *(short*)(p+offset+0x12ca)=i;
 }
}

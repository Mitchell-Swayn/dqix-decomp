#include <globaldefs.h>
ARM
extern "C" void* AllocatorUnion_AllocateFourByteAligned(void*,unsigned);
extern "C" void _ZN13SafeAllocator11CreateTypeAEPvj(void*,void*,unsigned);
extern "C" void VRAM_SaveStateAndReserveImagePaletteBytes(void*,unsigned,unsigned);
extern "C" void _Z28RestoreTextureImageVRAMStatePKj(void*);
extern "C" void _Z30RestoreTexturePaletteVRAMStatePK23TexturePaletteVRAMState(void*);
extern "C" char data_02114e20[];
struct Pair { int v; int pad; };
struct Triple { int v; int pad[2]; };
extern "C" Pair data_ov017_021d66c8[],data_ov017_021d66cc[];
extern "C" Triple data_ov017_021d6818[],data_ov017_021d6820[],data_ov017_021d681c[];
extern "C" Triple data_ov017_021d6800[],data_ov017_021d6808[],data_ov017_021d6804[];
// Original: arm9/ov017 @ 0x021A0630; symbol: func_ov017_021a0630; size: 0x160.
extern "C" void Graphics_AllocatePoolsAndReserveVram(char* p) {
 int i;
 for(i=0;data_ov017_021d66cc[i].v;i++) {
 unsigned size=data_ov017_021d66cc[i].v;
 void* mem=AllocatorUnion_AllocateFourByteAligned(data_02114e20,size);
 _ZN13SafeAllocator11CreateTypeAEPvj(p+0x38+data_ov017_021d66c8[i].v*20,mem,size);
 }
 _Z28RestoreTextureImageVRAMStatePKj(p+0x2a78);
 _Z30RestoreTexturePaletteVRAMStatePK23TexturePaletteVRAMState(p+0x2ad0);
 for(i=0;data_ov017_021d681c[i].v;i++)
 VRAM_SaveStateAndReserveImagePaletteBytes(p+0x2cc+data_ov017_021d6818[i].v*0x70,data_ov017_021d681c[i].v,data_ov017_021d6820[i].v);
 _Z28RestoreTextureImageVRAMStatePKj(p+0x2aa8);
 for(i=0;data_ov017_021d6804[i].v;i++)
 VRAM_SaveStateAndReserveImagePaletteBytes(p+0x2cc+data_ov017_021d6800[i].v*0x70,data_ov017_021d6804[i].v,data_ov017_021d6808[i].v);
 VRAM_SaveStateAndReserveImagePaletteBytes(p+0xe9c,0x8000,0x400);
 VRAM_SaveStateAndReserveImagePaletteBytes(p+0xf0c,0x4000,0x400);
}

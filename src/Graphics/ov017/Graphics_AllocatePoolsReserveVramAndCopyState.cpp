#include <globaldefs.h>
ARM
#pragma auto_inline on
struct Block { unsigned value[10]; };
struct Two {unsigned value[2];};
struct Pair {unsigned value,pad;};
struct Triple {unsigned value,pad[2];};
extern "C" {
extern char data_02114e20[];
extern Pair data_ov017_021d689c[],data_ov017_021d68a0[];
extern Triple data_ov017_021d6758[],data_ov017_021d6760[],data_ov017_021d675c[];
extern Triple data_ov017_021d6850[],data_ov017_021d6858[],data_ov017_021d6854[];
void* AllocatorUnion_AllocateFourByteAligned(void*,unsigned);
void _ZN13SafeAllocator11CreateTypeAEPvj(void*,void*,unsigned);
void VRAM_SaveStateAndReserveImagePaletteBytes(void*,unsigned,unsigned);
unsigned NNS_GfdAllocFrmTexVram(unsigned,int,unsigned);
void _Z28RestoreTextureImageVRAMStatePKj(void*);
void _Z30RestoreTexturePaletteVRAMStatePK23TexturePaletteVRAMState(void*);
}
// Original: arm9/ov017 @ 0x021A0C0C; symbol: Graphics_InitializeAllocatorAndVramReservations; size: 0x160.
extern "C" void Graphics_AllocatePoolsReserveVramAndCopyState(char* p){
unsigned size;
for(int i=0;(size=data_ov017_021d68a0[i].value)!=0;i++){
void* mem=AllocatorUnion_AllocateFourByteAligned(data_02114e20,size);
_ZN13SafeAllocator11CreateTypeAEPvj(p+0x38+data_ov017_021d689c[i].value*0x14,mem,size);
}
_Z28RestoreTextureImageVRAMStatePKj(p+0x2a78);
_Z30RestoreTexturePaletteVRAMStatePK23TexturePaletteVRAMState(p+0x2ad0);
NNS_GfdAllocFrmTexVram(0x20000,0,0);
for(int i=0;data_ov017_021d675c[i].value;i++)
VRAM_SaveStateAndReserveImagePaletteBytes(p+0x2cc+data_ov017_021d6758[i].value*0x70,data_ov017_021d675c[i].value,data_ov017_021d6760[i].value);
_Z28RestoreTextureImageVRAMStatePKj(p+0x2aa8);
for(int i=0;data_ov017_021d6854[i].value;i++)
VRAM_SaveStateAndReserveImagePaletteBytes(p+0x2cc+data_ov017_021d6850[i].value*0x70,data_ov017_021d6854[i].value,data_ov017_021d6858[i].value);
*(Block*)(p+0xf0c)=*(Block*)(p+0xbfc);
*(Block*)(p+0xf34)=*(Block*)(p+0xc24);
*(unsigned*)(p+0xf5c)=*(unsigned*)(p+0xc4c);
*(unsigned*)(p+0xf60)=*(unsigned*)(p+0xc50);
*(Two*)(p+0xf64)=*(Two*)(p+0xc54);
*(Two*)(p+0xf6c)=*(Two*)(p+0xc5c);
*(unsigned*)(p+0xf74)=*(unsigned*)(p+0xc64);
*(unsigned*)(p+0xf78)=*(unsigned*)(p+0xc68);
}

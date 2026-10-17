#include <globaldefs.h>
ARM
struct Pair {unsigned value,pad;};
struct Triple {unsigned value,pad[2];};
extern "C" {
extern char data_02114e20[];
extern Pair data_ov017_021d6830[],data_ov017_021d6834[];
extern Triple data_ov017_021d66f8[],data_ov017_021d6700[],data_ov017_021d66fc[];
extern Triple data_ov017_021d6740[],data_ov017_021d6748[],data_ov017_021d6744[];
void* AllocatorUnion_AllocateFourByteAligned(void*,unsigned);
void _ZN13SafeAllocator11CreateTypeAEPvj(void*,void*,unsigned);
void VRAM_SaveStateAndReserveImagePaletteBytes(void*,unsigned,unsigned);
void _Z28RestoreTextureImageVRAMStatePKj(void*);
void _Z30RestoreTexturePaletteVRAMStatePK23TexturePaletteVRAMState(void*);
}
// Original: arm9/ov017 @ 0x021A0C0C; symbol: func_ov017_021a0c0c; size: 0x160.
extern "C" void Graphics_InitializeAllocatorAndVramReservations(char* p){
unsigned size;
for(int i=0;(size=data_ov017_021d6834[i].value)!=0;i++){
void* mem=AllocatorUnion_AllocateFourByteAligned(data_02114e20,size);
_ZN13SafeAllocator11CreateTypeAEPvj(p+0x38+data_ov017_021d6830[i].value*0x14,mem,size);
}
_Z28RestoreTextureImageVRAMStatePKj(p+0x2a78);
_Z30RestoreTexturePaletteVRAMStatePK23TexturePaletteVRAMState(p+0x2ad0);
for(int i=0;data_ov017_021d66fc[i].value;i++)
VRAM_SaveStateAndReserveImagePaletteBytes(p+0x2cc+data_ov017_021d66f8[i].value*0x70,data_ov017_021d66fc[i].value,data_ov017_021d6700[i].value);
_Z28RestoreTextureImageVRAMStatePKj(p+0x2aa8);
for(int i=0;data_ov017_021d6744[i].value;i++)
VRAM_SaveStateAndReserveImagePaletteBytes(p+0x2cc+data_ov017_021d6740[i].value*0x70,data_ov017_021d6744[i].value,data_ov017_021d6748[i].value);
VRAM_SaveStateAndReserveImagePaletteBytes(p+0xe9c,0x8000,0x400);
VRAM_SaveStateAndReserveImagePaletteBytes(p+0xf0c,0x4000,0x400);
}

#include <globaldefs.h>
ARM
struct State;
extern "C" void VRAM_SaveStateAndReserveImagePaletteBytes(State* p,unsigned imageAmount,unsigned paletteAmount);
extern "C" void TextureVRAM_SnapshotAllocationBounds(char *p);
// Original: arm9/ov005 @ 0x02153B20; symbol: func_ov005_02153b20; size: 0x84.
extern "C" void Graphics_ReserveAndSnapshotPaletteBlocks(char* p) {
 for (int i=0;i<24;i++) {
  VRAM_SaveStateAndReserveImagePaletteBytes((State*)(p+0x304+i*0x70),0x120,0x20);
  TextureVRAM_SnapshotAllocationBounds(p+0x304+i*0x70);
 }
 VRAM_SaveStateAndReserveImagePaletteBytes((State*)(p+0xd84),0x120,0x20);
 TextureVRAM_SnapshotAllocationBounds(p+0xd84);
 VRAM_SaveStateAndReserveImagePaletteBytes((State*)(p+0x294),0x3000,0x400);
 TextureVRAM_SnapshotAllocationBounds(p+0x294);
}

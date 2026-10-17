#include <globaldefs.h>
ARM
extern "C" {
unsigned DisableMainBGVRAMBanks(); unsigned DisableMainObjVRAMBanks(); unsigned DisableMainBGExtendedPaletteVRAMBanks(); unsigned DisableMainObjExtendedPaletteVRAMBanks(); unsigned DisableTextureImageVRAMBanks(); unsigned DisableTexturePaletteVRAMBanks(); unsigned DisableClearTextureVRAMBanks(); unsigned DisableSubBGVRAMBanks(); unsigned DisableSubObjVRAMBanks(); unsigned DisableSubBGExtendedPaletteVRAMBanks(); unsigned DisableSubObjExtendedPaletteVRAMBanks(); unsigned DisableArm7WorkVRAMBanks(); unsigned DisableLCDCMappedVRAMBanks(); void MapVRAMBanksToArm7WorkRAM(int); void Graphics_ClearVramOamAndPalettes(); extern unsigned data_ov031_02290d68[];
}
// Original: arm9/ov031 @ 0x0223DDA8; symbol: func_ov031_0223dda8; size: 0xB4.
extern "C" void Graphics_SaveVramMappingsAndClearDisplayMemory() {
 data_ov031_02290d68[0]=DisableMainBGVRAMBanks();
 data_ov031_02290d68[1]=DisableMainObjVRAMBanks();
 data_ov031_02290d68[2]=DisableMainBGExtendedPaletteVRAMBanks();
 data_ov031_02290d68[3]=DisableMainObjExtendedPaletteVRAMBanks();
 data_ov031_02290d68[4]=DisableTextureImageVRAMBanks();
 data_ov031_02290d68[5]=DisableTexturePaletteVRAMBanks();
 data_ov031_02290d68[6]=DisableClearTextureVRAMBanks();
 data_ov031_02290d68[7]=DisableSubBGVRAMBanks();
 data_ov031_02290d68[8]=DisableSubObjVRAMBanks();
 data_ov031_02290d68[9]=DisableSubBGExtendedPaletteVRAMBanks();
 data_ov031_02290d68[10]=DisableSubObjExtendedPaletteVRAMBanks();
 data_ov031_02290d68[11]=DisableArm7WorkVRAMBanks();
 data_ov031_02290d68[12]=DisableLCDCMappedVRAMBanks();
 MapVRAMBanksToArm7WorkRAM(data_ov031_02290d68[11]);
 Graphics_ClearVramOamAndPalettes();
}

#include <globaldefs.h>
ARM
extern "C" {
// Original data: arm9/ov031 @ 0x2290d68; symbol: data_ov031_02290d68.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 52 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
unsigned DisableMainBGVRAMBanks(); unsigned DisableMainObjVRAMBanks(); unsigned DisableMainBGExtendedPaletteVRAMBanks(); unsigned DisableMainObjExtendedPaletteVRAMBanks(); unsigned DisableTextureImageVRAMBanks(); unsigned DisableTexturePaletteVRAMBanks(); unsigned DisableClearTextureVRAMBanks(); unsigned DisableSubBGVRAMBanks(); unsigned DisableSubObjVRAMBanks(); unsigned DisableSubBGExtendedPaletteVRAMBanks(); unsigned DisableSubObjExtendedPaletteVRAMBanks(); unsigned DisableArm7WorkVRAMBanks(); unsigned DisableLCDCMappedVRAMBanks(); void MapVRAMBanksToArm7WorkRAM(int); void Graphics_ClearVramOamAndPalettes(); extern unsigned GraphicsRestoreVramMappingsAndClearOffsets_UnknownRoleZeroInitializedStorage[];
}
// Original: arm9/ov031 @ 0x0223DDA8; symbol: func_ov031_0223dda8; size: 0xB4.
extern "C" void Graphics_SaveVramMappingsAndClearDisplayMemory() {
 GraphicsRestoreVramMappingsAndClearOffsets_UnknownRoleZeroInitializedStorage[0]=DisableMainBGVRAMBanks();
 GraphicsRestoreVramMappingsAndClearOffsets_UnknownRoleZeroInitializedStorage[1]=DisableMainObjVRAMBanks();
 GraphicsRestoreVramMappingsAndClearOffsets_UnknownRoleZeroInitializedStorage[2]=DisableMainBGExtendedPaletteVRAMBanks();
 GraphicsRestoreVramMappingsAndClearOffsets_UnknownRoleZeroInitializedStorage[3]=DisableMainObjExtendedPaletteVRAMBanks();
 GraphicsRestoreVramMappingsAndClearOffsets_UnknownRoleZeroInitializedStorage[4]=DisableTextureImageVRAMBanks();
 GraphicsRestoreVramMappingsAndClearOffsets_UnknownRoleZeroInitializedStorage[5]=DisableTexturePaletteVRAMBanks();
 GraphicsRestoreVramMappingsAndClearOffsets_UnknownRoleZeroInitializedStorage[6]=DisableClearTextureVRAMBanks();
 GraphicsRestoreVramMappingsAndClearOffsets_UnknownRoleZeroInitializedStorage[7]=DisableSubBGVRAMBanks();
 GraphicsRestoreVramMappingsAndClearOffsets_UnknownRoleZeroInitializedStorage[8]=DisableSubObjVRAMBanks();
 GraphicsRestoreVramMappingsAndClearOffsets_UnknownRoleZeroInitializedStorage[9]=DisableSubBGExtendedPaletteVRAMBanks();
 GraphicsRestoreVramMappingsAndClearOffsets_UnknownRoleZeroInitializedStorage[10]=DisableSubObjExtendedPaletteVRAMBanks();
 GraphicsRestoreVramMappingsAndClearOffsets_UnknownRoleZeroInitializedStorage[11]=DisableArm7WorkVRAMBanks();
 GraphicsRestoreVramMappingsAndClearOffsets_UnknownRoleZeroInitializedStorage[12]=DisableLCDCMappedVRAMBanks();
 MapVRAMBanksToArm7WorkRAM(GraphicsRestoreVramMappingsAndClearOffsets_UnknownRoleZeroInitializedStorage[11]);
 Graphics_ClearVramOamAndPalettes();
}

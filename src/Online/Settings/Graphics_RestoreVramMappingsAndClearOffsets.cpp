#include <globaldefs.h>
ARM
#include <System/VRAM.h>
// Original data: arm9/ov031 @ 0x2290d68; symbol: data_ov031_02290d68.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 52 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" int GraphicsRestoreVramMappingsAndClearOffsets_UnknownRoleZeroInitializedStorage[];
extern "C" void Graphics_ClearVramOamAndPalettes();
// Original: arm9/ov031 @ 0x0223DE5C; symbol: Graphics_RestoreVramMappingsAndClearOffsets; size: 0xf0.
// Restores saved VRAM mapping and clears main and sub scroll and blending registers.
extern "C" void Graphics_RestoreVramMappingsAndClearOffsets(){
DisableMainBGVRAMBanks();DisableMainObjVRAMBanks();DisableSubBGVRAMBanks();DisableSubObjVRAMBanks();Graphics_ClearVramOamAndPalettes();
MapVRAMBanksToMainBG(GraphicsRestoreVramMappingsAndClearOffsets_UnknownRoleZeroInitializedStorage[0]);
MapVRAMBanksToMainObj(GraphicsRestoreVramMappingsAndClearOffsets_UnknownRoleZeroInitializedStorage[1]);
MapVRAMBanksToMainBGExtendedPalette(GraphicsRestoreVramMappingsAndClearOffsets_UnknownRoleZeroInitializedStorage[2]);
MapVRAMBanksToMainObjExtendedPalette(GraphicsRestoreVramMappingsAndClearOffsets_UnknownRoleZeroInitializedStorage[3]);
MapVRAMBanksToTextureImage(GraphicsRestoreVramMappingsAndClearOffsets_UnknownRoleZeroInitializedStorage[4]);
MapVRAMBanksToTexturePalette(GraphicsRestoreVramMappingsAndClearOffsets_UnknownRoleZeroInitializedStorage[5]);
MapVRAMBanksToClearTextures(GraphicsRestoreVramMappingsAndClearOffsets_UnknownRoleZeroInitializedStorage[6]);
MapVRAMBanksToSubBG(GraphicsRestoreVramMappingsAndClearOffsets_UnknownRoleZeroInitializedStorage[7]);
MapVRAMBanksToSubObj(GraphicsRestoreVramMappingsAndClearOffsets_UnknownRoleZeroInitializedStorage[8]);
MapVRAMBanksToSubBGExtendedPalette(GraphicsRestoreVramMappingsAndClearOffsets_UnknownRoleZeroInitializedStorage[9]);
MapVRAMBanksToSubObjExtendedPalette(GraphicsRestoreVramMappingsAndClearOffsets_UnknownRoleZeroInitializedStorage[10]);
MapVRAMBanksToLCDC(GraphicsRestoreVramMappingsAndClearOffsets_UnknownRoleZeroInitializedStorage[12]);
 *(volatile unsigned short*)0x4000050=0;*(volatile unsigned short*)0x4001050=0;
*(volatile unsigned*)0x4000010=0;
*(volatile unsigned*)0x4000014=0;
*(volatile unsigned*)0x4000018=0;
*(volatile unsigned*)0x400001c=0;
*(volatile unsigned*)0x4001010=0;
*(volatile unsigned*)0x4001014=0;
*(volatile unsigned*)0x4001018=0;
*(volatile unsigned*)0x400101c=0;

}

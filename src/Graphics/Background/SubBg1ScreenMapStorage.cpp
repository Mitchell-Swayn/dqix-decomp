// Original BSS: arm9/main @ 0x02105FD8; symbol: data_02105fd8; size: 0x600.
// Zero-filled at load; contents are mutable at runtime.
// 768 16-bit screen entries for the sub-engine BG1 32-by-24 tile view.
// Graphics_ClearSubBackgroundCharacterBuffers and
// Graphics_FillBackgroundStagingSlotAndMarkDirty clear/fill exactly 0x600 bytes.
// Graphics_UpdateSelectedBackgroundTileBuffer supplies width32/height24 and
// Graphics_UploadDirtySubBackgroundScreenMaps uploads this buffer to BG1 screen
// memory. This stores tile-map entries, separate from character pixel data.
extern "C" {
unsigned short GraphicsClearSubBackgroundCharacterBuffers_UnknownRoleZeroInitializedStorage[32 * 24];
}

// Original BSS: arm9/main @ 0x021065D8; symbol: data_021065d8; size: 0x1000.
// Zero-filled at load; contents are mutable at runtime.
// 2048 16-bit screen entries for the sub-engine BG0 64-by-32 tile view.
// Graphics_ClearSubBackgroundCharacterBuffers and
// Graphics_FillBackgroundStagingSlotAndMarkDirty clear/fill exactly 0x1000 bytes.
// Graphics_UpdateSelectedBackgroundTileBuffer supplies width64/height32 and
// Graphics_UploadDirtySubBackgroundScreenMaps uploads this buffer to BG0 screen
// memory. The flat array preserves the screen-block arrangement of its consumer.
extern "C" {
unsigned short GraphicsClearSubBackgroundCharacterBuffers_UnknownRoleZeroInitializedStorage_Variant2[64 * 32];
}

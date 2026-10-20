// Original BSS: arm9/ov032 @ 0x02200180; symbol: data_ov032_02200180.
// Byte arena for the BGM sound resource heap; zero-filled at overlay load.
// Bgm_LoadArchiveIntoLargeOverlayBuffer passes this base and 0xA2000 bytes
// through ResourceHandle_AllocateLoadAndReadValue to
// ResourceAllocator_CreateAlignedHeapRegion(start, size). The latter constructs
// the allocator header and HMRF heap inside the caller-provided byte region.
// ResourceHandle_InitializeFromOverlayDataAnd57000Buffer uses a smaller 0x57000
// capacity at this same base. Runtime archive and allocator contents vary.
// The extent is the entire original ov032 BSS, not ROM-stored asset bytes.
// Existing interior reference labels are retained as linker aliases. Their
// addresses do not establish independent objects or a stable arena subdivision.
extern "C" {
__declspec(align(32)) unsigned char BgmLoadArchiveIntoLargeOverlayBuffer_UnknownRoleZeroInitializedStorage[0xA2000];
}

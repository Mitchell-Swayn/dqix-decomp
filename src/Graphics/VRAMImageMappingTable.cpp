// Texture image mapping triples: first block start, second block start,
// and first block size; each quantity is an address or size shifted by 12.
// The second and third fields also have linker aliases because fallback callers
// reference their original interior addresses.
// Original data: arm9/main @ 0x20ed668; symbol: data_020ed668.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0000.
// Observed span: 2 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern const unsigned short MemoryMapTextureImage_UnknownRoleInitializedBytes[48] = {
    0x0000, 0x0000, 0x0000,
    0x6800, 0x0000, 0x0000,
    0x6820, 0x0000, 0x0000, 0x6800, 0x0000, 0x0000,
    0x6840, 0x0000, 0x0000, 0x6800, 0x6840, 0x0020,
    0x6820, 0x0000, 0x0000, 0x6800, 0x0000, 0x0000,
    0x6860, 0x0000, 0x0000, 0x6800, 0x6860, 0x0020,
    0x6820, 0x6860, 0x0020, 0x6800, 0x6860, 0x0040,
    0x6840, 0x0000, 0x0000, 0x6800, 0x6840, 0x0020,
    0x6820, 0x0000, 0x0000, 0x6800, 0x0000, 0x0000,
};

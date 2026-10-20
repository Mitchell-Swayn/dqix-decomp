// Buffer allocation/clear byte counts, indexed by object byte0x1f and word0x18.
// The two row/category meanings remain unresolved; stride and units are observed.
extern "C" {
// Original data: arm9/main @ 0x20e7b98; symbol: data_020e7b98.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0008000000100000001000000020000000020000000800000020000000800000.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern const unsigned int GraphicsClearScreenBuffer_UnknownRoleInitializedBytes[2][4] = {
    {2 * 1024, 4 * 1024, 4 * 1024, 8 * 1024},
    {512, 2 * 1024, 8 * 1024, 32 * 1024}
};
}
typedef char BufferAllocationElementWidth[sizeof(unsigned int) == 4 ? 1 : -1];
typedef char BufferAllocationTableSize[sizeof(GraphicsClearScreenBuffer_UnknownRoleInitializedBytes) == 32 ? 1 : -1];

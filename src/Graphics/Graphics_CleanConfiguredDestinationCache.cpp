#include <globaldefs.h>
void CleanInvalidateCacheRange(const void*, unsigned int);
extern "C" {
// Original data: arm9/main @ 0x20e7b98; symbol: data_020e7b98.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0008000000100000001000000020000000020000000800000020000000800000.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern const volatile unsigned int GraphicsClearScreenBuffer_UnknownRoleInitializedBytes[2][4];
// Original: arm9/main @ 0x0204B04C; symbol: func_0204b04c; size: 0x3C.
void Graphics_CleanConfiguredDestinationCache(unsigned char* entry, void* destination)
{
    if (destination == 0) destination = *reinterpret_cast<void**>(entry + 0x14);
    if (destination == 0) return;
    unsigned char category = entry[0x1f];
    const volatile unsigned int* row = GraphicsClearScreenBuffer_UnknownRoleInitializedBytes[category];
    int index = *reinterpret_cast<int*>(entry + 0x18);
    unsigned int length = row[index];
    CleanInvalidateCacheRange(destination, length);
}
}

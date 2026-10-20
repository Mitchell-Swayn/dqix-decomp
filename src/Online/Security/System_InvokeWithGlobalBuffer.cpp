#include <globaldefs.h>
THUMB
// Original data: arm9/ov031 @ 0x224e9a0; symbol: data_ov031_0224e9a0.
// Runtime CRC-32 lookup table. InitializeReflectedCRC32Table fills 256 word entries using reflected polynomial 0xedb88320; func_ov031_0221e2e4 indexes words by (crc ^ inputByte) & 255.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 1024 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char SystemInvokeWithGlobalBuffer_RuntimeCRC32LookupTable[];
extern "C" int WirelessSetup_UpdateReflectedCrc32(int a, void *first, int second, int fourth, void *extra);
// Original: arm9/ov031 @ 0x0221E2BC; symbol: func_ov031_0221e2bc; size: 0x28.
extern "C" unsigned char System_InvokeWithGlobalBuffer(void *first, int second) {
    int result = WirelessSetup_UpdateReflectedCrc32(-1, first, second, 0, SystemInvokeWithGlobalBuffer_RuntimeCRC32LookupTable);
    int mask = ~0;
    return (unsigned char)(result ^ mask);
}

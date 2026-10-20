// Original data: arm9/ov031 @ 0x224e9a0; symbol: data_ov031_0224e9a0.
// Runtime CRC-32 lookup table. InitializeReflectedCRC32Table fills 256 word entries using reflected polynomial 0xedb88320; func_ov031_0221e2e4 indexes words by (crc ^ inputByte) & 255.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 1024 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Runtime CRC-32 lookup table. InitializeReflectedCRC32Table fills 256 word entries using reflected polynomial 0xedb88320; func_ov031_0221e2e4 indexes words by (crc ^ inputByte) & 255.
extern "C" {
unsigned int SystemInvokeWithGlobalBuffer_RuntimeCRC32LookupTable[256];
}

#include <globaldefs.h>
ARM
extern "C" void Memory_CopyBytesThroughSdkByteCopy(const void *, void *, unsigned int);
extern "C" void Util_Update64ByteBlockHash(void *, const void *, unsigned int);
// Original data: arm9/ov031 @ 0x22497a4; symbol: data_ov031_022497a4.
// MD5 block padding: one high bit followed by zero octets.
// Initial values: hex 80000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000.
// Observed span: 64 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char SystemExpandEncodedBufferHeaderAndPayload_MD5BlockPaddingOneHighBitFollowedByZeroOctets;
// Original: arm9/ov031 @ 0x0220B0E0; symbol: System_ExpandEncodedBufferHeaderAndPayload; size: 0x68.
// Decodes an eight-byte prefix, inserts table bytes according to its six-bit header field, then decodes and copies the expanded buffer.
extern "C" void System_ExpandEncodedBufferHeaderAndPayload(void *output, void *input) {
 Memory_CopyBytesThroughSdkByteCopy(input, (char *)output + 0x10, 8);
 int bits = (*(unsigned int *)((char *)output + 0x10) >> 3) & 0x3f;
 unsigned int count = bits < 0x38 ? 0x38 - bits : 0x78 - bits;
 Util_Update64ByteBlockHash(output, &SystemExpandEncodedBufferHeaderAndPayload_MD5BlockPaddingOneHighBitFollowedByZeroOctets, count);
 Util_Update64ByteBlockHash(output, input, 8);
 Memory_CopyBytesThroughSdkByteCopy(input, output, 0x10);
}

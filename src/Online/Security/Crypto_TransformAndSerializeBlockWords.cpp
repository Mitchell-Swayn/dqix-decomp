#include <globaldefs.h>
ARM
extern "C" void Util_StoreWordsMostSignificantByteFirst(unsigned char*, const unsigned int*, unsigned);
extern "C" void Crypto_UpdateSha1Context(void*, const void*, int);
// Original data: arm9/ov031 @ 0x22498e4; symbol: data_ov031_022498e4.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 80.
// Observed span: 1 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char CryptoTransformAndSerializeBlockWords_UnknownRoleInitializedBytes;
// Original: arm9/ov031 @ 0x0220B9AC; symbol: Crypto_TransformAndSerializeBlockWords; size: 0x68.
// Stores an initial word span in big-endian order, computes the wraparound distance to byte position 0x38/0x78, applies an ov031 transform using the shared table, then stores another span and the trailing words.
extern "C" void Crypto_TransformAndSerializeBlockWords(unsigned char* self, unsigned char* destination) {
    Util_StoreWordsMostSignificantByteFirst(destination, (const unsigned int*)(self + 0x14), 8);
    int position = (*(unsigned int*)(self + 0x18) >> 3) & 0x3f;
    int span = position < 0x38 ? 0x38 - position : 0x78 - position;
    Crypto_UpdateSha1Context(self, &CryptoTransformAndSerializeBlockWords_UnknownRoleInitializedBytes, span);
    Crypto_UpdateSha1Context(self, destination, 8);
    Util_StoreWordsMostSignificantByteFirst(destination, (const unsigned int*)self, 0x14);
}

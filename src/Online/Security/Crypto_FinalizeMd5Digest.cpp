#pragma thumb on
#pragma optimize_for_size off
#pragma optimization_level 4
extern "C" void Memory_CopyWordsAsBytes(unsigned char*, const unsigned*, unsigned);
extern "C" void Crypto_UpdateMd5Context(unsigned*, const unsigned char*, unsigned);
extern "C" void Crypto_FillMd5ScratchBytes(void*, int, unsigned);
// Original data: arm9/ov031 @ 0x0224B194; symbol: data_ov031_0224b194.
// MD5 padding begins with 0x80 followed by zero bytes; see docs/data-symbols/ov031.md.
extern "C" const unsigned char CryptoFinalizeMd5Digest_UnknownRoleInitializedBytes[];
// Original: arm9/ov031 @ 0x02221F24; symbol: func_ov031_02221f24; size: 0x54.
// Appends MD5 padding and the saved bit count, serializes the digest, and clears the context.
extern "C" void Crypto_FinalizeMd5Digest(unsigned char* digest, unsigned* context)
{
    unsigned char bitCount[8];
    Memory_CopyWordsAsBytes(bitCount, context + 4, 8);
    unsigned index = (context[4] >> 3) & 63;
    unsigned padding = index < 56 ? 56 - index : 120 - index;
    Crypto_UpdateMd5Context(context, CryptoFinalizeMd5Digest_UnknownRoleInitializedBytes, padding);
    Crypto_UpdateMd5Context(context, bitCount, 8);
    Memory_CopyWordsAsBytes(digest, context, 16);
    Crypto_FillMd5ScratchBytes(context, 0, 88);
}

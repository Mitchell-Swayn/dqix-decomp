// AES key schedule round constants; powers of x in GF(2^8), high byte packing.
// Original data: arm9/ov031 @ 0x22460e8; symbol: data_ov031_022460e8.
// AES key schedule round constants; powers of x in GF(2^8), high byte packing.
// Initial values: hex 00000001000000020000000400000008000000100000002000000040000000800000001b00000036.
// Observed span: 40 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" const unsigned int CryptoExpandAesEncryptionRoundKeys_AESKeyScheduleRoundConstants[10] = {
    0x01000000U, 0x02000000U, 0x04000000U, 0x08000000U, 0x10000000U, 0x20000000U, 0x40000000U, 0x80000000U,
    0x1b000000U, 0x36000000U,
};

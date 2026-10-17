// Searches the table at context+4 for a byte key at record offset 0xD.
// Original: arm9/ov003 @ 0x0215F4A4; symbol: func_ov003_0215f4a4; size: 0x40.
extern "C" unsigned char* FindByteKeyInTwentyByteRecords(const unsigned char* context, int key) {
    const unsigned char* table = *(const unsigned char* const*)(context + 4);
    short count = *(const short*)(table + 6);
    unsigned char* record = *(unsigned char* const*)table;
    for (short i = 0; i < count; ++i, record += 0x14) {
        if (record[0xD] == key) return record;
    }
    return 0;
}

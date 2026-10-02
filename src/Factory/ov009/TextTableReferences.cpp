// 02189a4c visits 0x20-byte records from a table header at context + 0x114.
// References are initially unsigned offsets; 0xffffffff is the absent marker.
// The same storage holds pointers after this callback has relocated the table.
union TextTableReference {
    unsigned int offset;
    const char* pointer;
};

struct TextPatternRecord {
    TextTableReference references[7];
    unsigned char unknown_1c[2];
    unsigned char referenceCount;
    unsigned char unknown_1f;
};

struct TextPatternTable {
    unsigned int flagsAndCount;
    TextPatternRecord* records;
    const char* referenceBase;
};

typedef char TextPatternRecordSizeCheck[sizeof(TextPatternRecord) == 0x20 ? 1 : -1];

extern "C" bool func_ov009_0218a420(TextPatternTable* table,
                                   TextPatternRecord* record)
{
    for (int i = 0; i < record->referenceCount; ++i) {
        bool absent = true;
        // Preserve MWCC's conversion from a pointer encoded relative to zero,
        // also used by the existing serialized-record relocation source.
        unsigned int offset = record->references[i].pointer - (const char*)0;
        if (offset != 0xffffffff && table->referenceBase != 0)
            absent = false;
        record->references[i].pointer = absent ? 0 : table->referenceBase + offset;
    }
    return true;
}

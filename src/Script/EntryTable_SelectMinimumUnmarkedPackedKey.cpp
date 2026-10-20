#include <globaldefs.h>
ARM
typedef struct PackedEntry { unsigned key0:9; unsigned key1:9; unsigned key2:9; unsigned reserved:5; unsigned words[2]; } PackedEntry;
typedef struct EntryTable { PackedEntry* entries; unsigned short reserved; unsigned short count; unsigned word8; unsigned char* marked; } EntryTable;
// Original: arm9/main @ 0x020A171C; symbol: func_020a171c; size: 0x11C.
// Selects the unmarked entry with the smallest nonzero selected nine-bit key,
// marks its index in the bitmap, and returns its twelve-byte record.
extern "C" PackedEntry* EntryTable_SelectMinimumUnmarkedPackedKey(EntryTable* table, int mode, int secondary)
{
    unsigned short minimum = 0xffff;
    unsigned short selected = 0;
    int index;
    for (index = 0; index < table->count; ++index) {
        unsigned char bit = (unsigned char)(1 << (index % 8));
        PackedEntry* entry;
        unsigned short key;
        if (!(table->marked[index / 8] & bit)) {
        entry = &table->entries[index];
        key = 0xffff;
        if (mode == 1) key = (unsigned short)entry->key0;
        else if (mode == 2) {
            key = secondary == 0 ? (unsigned short)entry->key1 : (unsigned short)entry->key2;
        }
        if (minimum > key && key != 0) {
            minimum = key;
            selected = (unsigned short)index;
        }
        }
    }
    if (minimum != 0xffff) {
    int bit = selected % 8;
    int byte = selected / 8;
    unsigned char mask = 1 << bit;
    unsigned int value = table->marked[byte];
    value |= mask;
    table->marked[byte] = value;
    return &table->entries[selected];
    }
    return 0;
}

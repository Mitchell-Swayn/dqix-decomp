#include <globaldefs.h>
ARM
extern "C" {
struct Entry { unsigned int bits : 9; unsigned int other : 23; unsigned int field4; unsigned int field8; };
struct Table { Entry *entries; unsigned short field4; unsigned short count; };
// Original: arm9/main @ 0x020A15BC; symbol: func_020a15bc; size: 0x58.
Entry *ScriptEntryTable_FindByPrimaryKey(Table *table, int id) {
    if (id <= 0) return 0;
    unsigned short key = id;
    for (int i = 0; i < table->count; i++) {
        if (table->entries[i].bits == key) return &table->entries[i];
    }
    return 0;
}
}

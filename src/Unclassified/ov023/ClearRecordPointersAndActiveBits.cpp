#pragma thumb off
// Field layout is established by instructions; object semantics remain uncertain.
struct Entry {
    unsigned pointer;
    char pad[10];
    unsigned char flags;
    char tail;
};
struct Table {
    unsigned count;
    Entry* entries;
    short capacity;
};
// Original: arm9/ov023 @ 0x021E1518; symbol: func_ov023_021e1518; size: 0x4c.
extern "C" void ClearRecordPointersAndActiveBits(Table* obj) {
    Entry* entries=obj->entries;
    short count=obj->capacity;
    for(short i=0; i<count; i++) {
        Entry* e=&entries[i];
        e->pointer=0;
        e->flags &= ~1;
    }
    obj->count=0;
}

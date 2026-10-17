#include <globaldefs.h>
ARM
extern "C" void __clear(void*,unsigned);
extern "C" int GameState_Copy176BytesAtOffset7540(const void*);
extern "C" bool GameState_CopyB0ByteStateBufferToOutput(void*);
struct Entry { short id; unsigned short flags:1; unsigned short rest:15; };
struct Record { short id; char pad[20]; short value; char rest[8]; };
struct Table { int pad; Record* records; short x; unsigned short count; };
struct Object { Table* table; char pad[28]; Entry* entries; unsigned short count; };
// ARM9 ov006 0x02154138 func_ov006_02154138
// Original: arm9/ov006 @ 0x02154138; symbol: func_ov006_02154138; size: 0x134.
extern "C" short GameState_CountAndStoreFlaggedEntries(Object* p) {
    char flags[472];
    unsigned int state[44];
    if (!p->table) return 0;
    unsigned short total=0;
    __clear(flags,472);
    for (unsigned short i=0;i<p->count;i++) flags[p->entries[i].id] |= p->entries[i].flags;
    for (unsigned short i=0;i<p->table->count;i++) {
        Record* r=p->table->records+(short)i;
        if (r && r->value<0) flags[r->id] |= 2;
    }
    for (unsigned short i=1;i<472;i++) if (flags[i]==3) total++;
    GameState_CopyB0ByteStateBufferToOutput(state);
    state[4]=(state[4]&0x7fffff)|(total<<23);
    GameState_Copy176BytesAtOffset7540(state);
    return total;
}

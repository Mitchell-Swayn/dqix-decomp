#include <globaldefs.h>
ARM
extern "C" {
struct Record { unsigned int a, b, index; };
struct Group { unsigned int a; Record *records; };
struct Item { unsigned char a, value; unsigned char pad[6]; };
struct State { unsigned char pad0[8]; Item *items; Group *groups; unsigned char pad10[0x60]; unsigned int record; unsigned int group; unsigned char pad78[12]; unsigned char flags : 1; unsigned char other : 7; };
// Original: arm9/main @ 0x020479B8; symbol: func_020479b8; size: 0x44.
unsigned int ReadSelectedGroupedItemValueWhenFlagsSet(State *p) {
    if (!(p->flags)) return 0;
    return p->items[p->groups[p->group].records[p->record].index].value;
}
}

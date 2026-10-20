#include <globaldefs.h>

ARM
extern "C" {
struct State { unsigned char pad[16]; unsigned int first:10; unsigned int second:10; unsigned int other:12; unsigned char pad14[4]; short count; };
// Original: arm9/main @ 0x020DE234; symbol: func_020de234; size: 0x70.
unsigned int ZoneSerializedRecord_GetPreferredAttribute(State *p, int which) {
    if (p->count <= 0) return 999;
    if (which == 0) {
        unsigned int value = p->first;
        return value != 999 ? (unsigned short)value : (unsigned short)p->second;
    }
    unsigned int value = p->second;
    return value != 999 ? (unsigned short)value : (unsigned short)p->first;
}
}

#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021D994C; symbol: func_ov023_021d994c; size: 0x3C.
extern "C" void* PartyGrowthPanel_FindMemberRecord(void* object, unsigned char value) {
    unsigned char* record = *(unsigned char**)((char*)object + 0x120);
    int i = 0;
    while (i < *(unsigned char*)((char*)object + 0x11e)) {
        unsigned char first = *record;
        if (first == value) return record;
        ++i;
        record = record + 0x99c;
    }
    return 0;
}

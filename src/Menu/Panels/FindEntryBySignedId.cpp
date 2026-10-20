#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021DB08C; symbol: func_ov023_021db08c; size: 0x48.
extern "C" void *FindEntryBySignedId(void *table, int id) {
    if (id < 0) return 0;
    int i = 0;
    while (i < *(unsigned short *)((unsigned char *)table + 6)) {
        unsigned char *entries = *(unsigned char **)table;
        unsigned char *entry = entries + i * 8;
        if (id == *(short *)entry) return entry;
        ++i;
    }
    return 0;
}

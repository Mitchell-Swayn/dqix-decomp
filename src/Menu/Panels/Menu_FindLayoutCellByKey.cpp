#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021E2450; symbol: FindFixedSizeRecordBySignedHalfwordKey; size: 0x60.
// Searches the 0x14-byte entries for a matching signed first halfword and returns the matching entry or null.
extern "C" void *Menu_FindLayoutCellByKey(void *obj, int key) {
    char *entries = *(char **)((char *)obj + 0xc);
    if (entries == 0) return 0;
    unsigned short count = *(unsigned short *)((char *)obj + 0x16);
    if (count == 0) return 0;
    unsigned short i = 0;
    while (i < count) {
        char *entry = entries + i * 0x14;
        if (*(short *)entry == key) return entry;
        i = (unsigned short)(i + 1);
    }
    return 0;
}

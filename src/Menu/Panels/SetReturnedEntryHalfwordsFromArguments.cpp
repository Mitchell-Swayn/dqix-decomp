#include <globaldefs.h>
ARM
extern "C" void *Menu_ResolveFirstLayoutCellForGroup(void *, void *);
// Original: arm9/ov023 @ 0x021E2CA8; symbol: func_ov023_021e2ca8; size: 0x20.
extern "C" void *SetReturnedEntryHalfwordsFromArguments(void *first, void *second, unsigned short value4, unsigned short value5) {
    void *entry = Menu_ResolveFirstLayoutCellForGroup(first, second);
    if (entry) {
        *(unsigned short *)((char *)entry + 4) = value4;
        *(unsigned short *)((char *)entry + 6) = value5;
    }
    return entry;
}

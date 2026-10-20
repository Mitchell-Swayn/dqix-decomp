#include <globaldefs.h>
ARM
extern "C" char *MenuLayout_FindGroupByKey(char *, int);
// Original: arm9/ov023 @ 0x021DB544; symbol: func_ov023_021db544; size: 0x20.
extern "C" char *MenuLayout_SetGroupPositionOffsets(char *p, int key, unsigned short first, unsigned short second) {
    char *record = MenuLayout_FindGroupByKey(p, key);
    if (record) {
        *(unsigned short *)(record + 8) = first;
        *(unsigned short *)(record + 0xa) = second;
    }
    return record;
}

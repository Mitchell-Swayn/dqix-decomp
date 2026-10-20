#include <globaldefs.h>
ARM
// Original: arm9/ov004 @ 0x021538B4; symbol: func_ov004_021538b4; size: 0x3C.
extern "C" void *Menu_FindCategoryCounterByKind(void *records, int id) {
    for (unsigned char i = 0; i < 20; ) {
        unsigned char *record = (unsigned char *)records + i * 6;
        if (*(short *)record == id) return record;
        int next = i + 1;
        i = next & 0xFF;
    }
    return 0;
}

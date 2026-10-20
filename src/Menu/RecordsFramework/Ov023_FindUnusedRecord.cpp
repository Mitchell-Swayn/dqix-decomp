#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021FA03C; symbol: func_ov023_021fa03c; size: 0x3C.
extern "C" void *Ov023_FindUnusedRecord(char *object) {
    int i = 0;
    while (i < *(unsigned short *)(object + 0x20)) {
        char *record = *(char **)(object + 0x24) + i * 0x28;
        if (*(unsigned char *)(record + 2) == 0) return record;
        i++;
    }
    return 0;
}

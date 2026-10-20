#include <globaldefs.h>
ARM
// Original: arm9/ov003 @ 0x0215E824; symbol: func_ov003_0215e824; size: 0x38.
extern "C" void *TextEntry_FindControlByIdentifier(void *list, int value) {
    unsigned char *entry = *(unsigned char **)list;
    int count = *(short *)((unsigned char *)list + 6);
    int i = 0;
    while (i < count) {
        short found = *(short *)(entry + 0x10);
        if (found == value) return entry;
        i++;
        entry = entry + 0x14;
    }
    return 0;
}

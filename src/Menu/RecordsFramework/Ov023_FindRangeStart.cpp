#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021F6DD8; symbol: func_ov023_021f6dd8; size: 0x38.
extern "C" unsigned int Ov023_FindRangeStart(char *object, unsigned int offset) {
    char *node = *(char **)(object + 0x28);
    while (node != 0) {
        unsigned int start = *(unsigned int *)(node + 4);
        char *next = *(char **)(node + 0x0c);
        unsigned int end = start + offset;
        if (next == 0) return start;
        if (end <= *(unsigned int *)next) return start;
        node = next;
    }
    return 0;
}

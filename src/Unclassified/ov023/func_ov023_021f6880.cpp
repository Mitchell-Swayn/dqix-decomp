#include <globaldefs.h>
ARM
extern "C" unsigned short ReadHalfwordAtOffset6(void *);
// Original: arm9/ov023 @ 0x021F6880; symbol: func_ov023_021f6880; size: 0x38.
extern "C" void *func_ov023_021f6880(void **head, unsigned short value) {
    void *node = *head;
    while (node != 0) {
        if (ReadHalfwordAtOffset6(node) == value) return node;
        node = *(void **)((char *)node + 0x18);
    }
    return 0;
}

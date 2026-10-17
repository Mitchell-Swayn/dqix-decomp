#include <globaldefs.h>
extern "C" unsigned *func_ov023_021e1bac(void *, int, int, int);
// Original: arm9/ov023 @ 0x021E1B0C; symbol: func_ov023_021e1b0c; size: 0x50.
extern "C" void OV023_BuildLinkedNodeChain(unsigned **head, int a, int b, int c) {
    unsigned *node = func_ov023_021e1bac(head, a, b, c);
    if (!node) return;
    *head = node;
    while (node) {
        unsigned *next = func_ov023_021e1bac(head, a, b, c);
        *node = (unsigned)next;
        node = next;
    }
}

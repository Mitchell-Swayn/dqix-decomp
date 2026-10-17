#include <globaldefs.h>
ARM
extern "C" void* func_ov023_021e18cc(void*, int, int, int, int);
// Original: arm9/ov023 @ 0x021E1814; symbol: func_ov023_021e1814; size: 0x5C.
extern "C" void BuildLinkedListFromFactory(void** head, int a, int b, int c, int d) {
    void* node = func_ov023_021e18cc(head, a, b, c, d);
    if (!node)
        return;
    *head = node;
    while (node) {
        void* next = func_ov023_021e18cc(head, a, b, c, d);
        *(void**)node = next;
        node = next;
    }
}

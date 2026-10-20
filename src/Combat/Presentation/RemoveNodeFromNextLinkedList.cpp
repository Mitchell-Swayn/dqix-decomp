#include <globaldefs.h>
ARM
// Original: arm9/ov025 @ 0x021E244C; symbol: func_ov025_021e244c; size: 0x48.
extern "C" void RemoveNodeFromNextLinkedList(void **head, void *target) {
    void *node = *head;
    void *previous = 0;
    while (node != 0) {
        if (node == target) {
            if (previous != 0)
                *(void **)((unsigned char *)previous + 8) = *(void **)((unsigned char *)node + 8);
            else
                *head = *(void **)((unsigned char *)node + 8);
            *(void **)((unsigned char *)target + 8) = 0;
            return;
        }
        previous = node;
        node = *(void **)((unsigned char *)node + 8);
    }
}

#include <globaldefs.h>
ARM
extern "C" void *func_ov023_021e170c(void *, unsigned int, unsigned int, unsigned int);
// Original: arm9/ov023 @ 0x021E15B4; symbol: func_ov023_021e15b4; size: 0x50.
extern "C" void Grotto_BuildLinkedNodeChain(void **head, unsigned int a, unsigned int b, unsigned int c) {
    void *node = func_ov023_021e170c(head, a, b, c);
    if (node == 0) return;
    *head = node;
    goto check_node;
loop_body:
    {
        void *next = func_ov023_021e170c(head, a, b, c);
        *(void **)node = next;
        node = next;
    }
check_node:
    if (node != 0) goto loop_body;
}

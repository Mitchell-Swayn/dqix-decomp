#include <globaldefs.h>
ARM
struct Node {
    virtual void fn0() = 0;
    virtual void fn1() = 0;
    virtual void fn2() = 0;
    virtual void fn3() = 0;
    virtual void fn4() = 0;
    virtual void fn5() = 0;
    char padding[0x14];
    Node *next;
};
// Original: arm9/ov023 @ 0x021F69EC; symbol: func_ov023_021f69ec; size: 0x2C.
extern "C" void Util_CallVtableSlot5ForLinkedNodes(void *head) {
    Node *node = *(Node **)head;
    while (node) {
        node->fn5();
        node = node->next;
    }
}

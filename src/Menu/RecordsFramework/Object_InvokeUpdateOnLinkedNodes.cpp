#include <globaldefs.h>
ARM
struct Node {
    virtual void first();
    virtual void second();
    virtual void update();
    char pad[0x14];
    Node *next;
};
// Original: arm9/ov023 @ 0x021F69BC; symbol: Object_InvokeUpdateOnLinkedNodes; size: 0x2C.
// Walks object[0] as a linked list, calls each node virtual slot 2, and follows node+0x18.
extern "C" void Object_InvokeUpdateOnLinkedNodes(void *object) {
    Node *node = *(Node **)object;
    while (node) {
        node->update();
        node = node->next;
    }
}

#include <globaldefs.h>
ARM
struct Node { Node* next; Node* prev; };
// Original: arm9/ov031 @ 0x0223FF38; symbol: func_ov031_0223ff38; size: 0x44.
extern "C" Node* Util_RemoveHeadFromCircularList(Node** head) {
    Node* node = *head;
    if (node == 0)
        goto done;
    if (node == node->next) {
        *head = 0;
        goto done;
    }
    node->next->prev = node->prev;
    node->prev->next = node->next;
    *head = node->prev;
done:
    return node;
}

#include <globaldefs.h>
ARM
extern "C" unsigned int GetOverlaySharedWord();
struct Node { unsigned unknown; unsigned id; Node *previous; Node *next; };
struct List { unsigned count; Node *head; Node *tail; };
// Original: arm9/ov031 @ 0x0220EEA0; symbol: func_ov031_0220eea0; size: 0xBC.
extern "C" void MoveNodeToSharedListTail(Node *node) {
    char *shared = (char *)GetOverlaySharedWord();
    List *list = *(List **)(shared + 0x2270);
    if (!node || !list) return;
    if (*(unsigned *)(shared + 0x2274) <= 12) return;
    Node *current = list->head;
    while (current) {
        if (current == node) {
            if (current->previous) current->previous->next = current->next;
            else list->head = current->next;
            if (current->next) current->next->previous = current->previous;
            else list->tail = current->previous;
            break;
        }
        current = current->next;
    }
    node->next = 0;
    node->previous = list->tail;
    list->tail = node;
    if (node->previous) node->previous->next = node;
    else list->head = node;
    if (!current) {
        node->id = list->count;
        ++list->count;
    }
}

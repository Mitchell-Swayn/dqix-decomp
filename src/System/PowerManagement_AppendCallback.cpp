#include <globaldefs.h>
#pragma optimization_level 1
#pragma optimize_for_size off
struct Node { unsigned pad[2]; Node* next; };
// Original: arm9/main @ 0x020CEE68; symbol: func_020cee68; size: 0x4C.
extern "C" void PowerManagement_AppendCallback(Node** head, Node* node) {
    if (!head) return;
    Node* p = *head;
    if (!p) {
        node->next = 0;
        *head = node;
        return;
    }
    Node* next = p->next;
    if (next) {
        do {
            p = next;
            next = p->next;
        } while (next);
    }
    node->next = next;
    p->next = node;
}

#include <globaldefs.h>
ARM
struct Node { unsigned char pad[1]; unsigned char priority; unsigned char pad2[6]; Node* next; };
// Original: arm9/ov025 @ 0x021E23E8; symbol: func_ov025_021e23e8; size: 0x64.
extern "C" Node* Util_UnlinkLowestPriorityNode(Node** head) {
    Node* current = *head;
    Node* previous = 0;
    unsigned char lowest = 0xff;
    Node* selected = 0;
    Node* selectedPrevious = 0;
    while (current) {
        if (current->priority < lowest) {
            lowest = current->priority;
            selected = current;
            selectedPrevious = previous;
        }
        previous = current;
        current = current->next;
    }
    if (selected) {
        if (selectedPrevious) selectedPrevious->next = selected->next;
        else *head = selected->next;
    }
    return selected;
}

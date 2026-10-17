#include <globaldefs.h>
ARM
struct SortedNode { int value; SortedNode* volatile next; SortedNode* volatile previous; };
// Original: arm9/ov025 @ 0x021DF568; symbol: func_ov025_021df568; size: 0x64.
extern "C" SortedNode* Util_InsertSortedNodeByValue(SortedNode* head, SortedNode* node) {
    SortedNode* current = head;
    while (current) {
        if (node->value < current->value) {
            SortedNode* next = current->next;
            if (next) next->previous = node;
            node->previous = current;
            node->next = current->next;
            current->next = node;
            if (current == head) head = node;
            return head;
        }
        SortedNode* previous = current->previous;
        if (!previous) {
            current->previous = node;
            node->next = current;
            return head;
        }
        current = previous;
    }
    return head;
}

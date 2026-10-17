#include <globaldefs.h>
#pragma optimization_level 2
#pragma opt_strength_reduction off

struct Node {
    unsigned char id, unknown01[3];
    unsigned char major, minor, sub, unknown07, active, unknown09;
    unsigned char flagsLow : 2, first : 1, flagsMid : 3, second : 1, flagsHigh : 1;
    unsigned char unknown0b[0x39];
    unsigned short order;
    short attribute;
    unsigned char unknown48[0x1c];
    Node* previous; Node* next; Node* previousItem; Node* nextItem;
};
extern "C" Node* LinkedList_FindNodeByUnsignedKey(Node**, int);
// Original: arm9/main @ 0x0206DB48; symbol: func_0206db48; size: 0x220.
extern "C" ARM void SelectNodeRankFromEntryFlags(Node** head, Node* entry) {
    Node* item = LinkedList_FindNodeByUnsignedKey(head, entry->id);
    int rank;
    if (entry->first) rank = 0;
    else if (entry->second) rank = 1;
    else if (entry->attribute >= 0) rank = 2;
    else if (entry->minor && !entry->active) rank = 3;
    else if (entry->active) rank = 4;
    else rank = 5;
    if (item) {
        for (; item; item = item->nextItem) {
            int otherRank;
            if (item->first) otherRank = 0;
            else if (item->second) otherRank = 1;
            else if (item->attribute >= 0) otherRank = 2;
            else if (item->minor && !item->active) otherRank = 3;
            else if (item->active) otherRank = 4;
            else otherRank = 5;
            bool earlier = false;
            if (rank < otherRank) earlier = true;
            else if (rank == otherRank) {
                if (rank == 4 || rank == 1) {
                    int order = entry->major * 1000 + entry->minor * 10 + entry->sub;
                    int otherOrder = item->major * 1000 + item->minor * 10 + item->sub;
                    if (order == otherOrder && entry->order < item->order) earlier = true;
                    else if (order < otherOrder) earlier = true;
                } else if (entry->order < item->order) earlier = true;
            }
            if (earlier) break;
        }
        if (!item) return;
        if (!item->previousItem) {
            if (item->previous) item->previous->next = entry;
            if (item->next) item->next->previous = entry;
            entry->previous = item->previous;
            entry->next = item->next;
            item->previous = 0;
            item->next = 0;
            if (!entry->previous) *head = entry;
        }
        if (item->previousItem) item->previousItem->nextItem = entry;
        entry->previousItem = item->previousItem;
        entry->nextItem = item;
        item->previousItem = entry;
    } else {
        if (*head) (*head)->previous = entry;
        entry->next = *head;
        *head = entry;
    }
}

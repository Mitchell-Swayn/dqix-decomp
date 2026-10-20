#include <globaldefs.h>
struct Node { unsigned short unknown; unsigned char active, head; Node *next; };
struct List { Node *first,*last; };
// Original: arm9/main @ 0x020469F8; symbol: func_020469f8; size: 0x44.
extern "C" ARM void LinkedList_PrependAndMarkNodeActive(List *list,Node *node) {
 Node *old=list->first;
 if (old && list->last) { old->head=0; node->next=list->first; list->first=node; }
 else { list->first=node; list->last=node; node->next=0; }
 node->active=1;
}

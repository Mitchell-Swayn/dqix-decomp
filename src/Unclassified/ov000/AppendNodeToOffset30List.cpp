#include <globaldefs.h>
struct Node { unsigned char pad[0x30]; Node* next; };
struct List { unsigned char p[8]; unsigned char count; unsigned char q[7]; Node* head; };
#pragma force_active on
// Original: arm9/ov000 @ 0x02160068; symbol: func_ov000_02160068; size: 0x2C.
// Describes observed operations; underlying field roles remain uncertain.
extern "C" void AppendNodeToOffset30List(List* list, Node* node)
{
    Node** link=&list->head; while (*link) link=&(*link)->next; *link=node; ++list->count;
}

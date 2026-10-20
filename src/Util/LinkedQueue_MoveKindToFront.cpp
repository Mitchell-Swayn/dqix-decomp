#pragma optimize_for_size off
#include <globaldefs.h>
ARM
struct Node { signed char kind;unsigned char pad[3];Node* next; };struct List {Node* first;Node* last;};
// Original: arm9/main @ 0x02046B8C; symbol: func_02046b8c; size: 0xEC.
extern "C" void LinkedQueue_MoveKindToFront(List* list,int kind) {Node* previous;Node* moved;Node* cursor=list->first;for(Node* node=cursor;node;node=node->next){}previous=0;moved=0;while(cursor){Node* next=cursor->next;if(cursor->kind==kind){if(previous)previous->next=next;else list->first=next;cursor->next=0;if(moved){Node* tail=moved;Node* step;while((step=tail->next)!=0)tail=step;tail->next=cursor;}else moved=cursor;}else previous=cursor;cursor=next;}if(!moved)return;Node* tail=moved;Node* step;while((step=tail->next)!=0)tail=step;tail->next=list->first;list->first=moved;tail=moved;while((step=tail->next)!=0)tail=step;list->last=tail;tail=list->first;while(tail)tail=tail->next; }

#include "globaldefs.h"
#pragma optimize_for_size off
ARM
struct Node{int a,b;Node*next;};struct Object{int a;unsigned short count,pad;Node*head;void*bits;unsigned char ready;};extern "C" void* memset(void*,int,unsigned);extern "C" Node* EntryTable_SelectMinimumUnmarkedPackedKey(Object*,int,int);
// Original: arm9/main @ 0x020A1614; symbol: func_020a1614; size: 0x84.
extern "C" void ScriptEntryTable_SortByPrimaryKey(Object*p){p->head=0;memset(p->bits,0,(p->count-1)/8+1);Node*n;p->head=EntryTable_SelectMinimumUnmarkedPackedKey(p,1,0);n=p->head;if(n){while(n){Node*next=EntryTable_SelectMinimumUnmarkedPackedKey(p,1,0);n->next=next;n=next;}}p->ready=1;}

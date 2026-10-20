#include <globaldefs.h>
struct Node{unsigned char pad[0x18];short index;short padding;Node* next;};extern "C" Node* ScriptRecordTable_FindNextPrimaryOrder(Node**,int);
// Original: arm9/main @ 0x0207214C; symbol: func_0207214c; size: 0x40.
extern "C" ARM void ScriptRecordTable_LinkEligibleByPrimaryOrder(Node** head){*head=ScriptRecordTable_FindNextPrimaryOrder(head,-1);Node* node=*head;if(node){while(node){Node* next=ScriptRecordTable_FindNextPrimaryOrder(head,node->index);node->next=next;node=next;}}}

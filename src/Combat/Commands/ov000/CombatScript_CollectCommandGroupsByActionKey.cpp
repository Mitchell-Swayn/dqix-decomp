#include <globaldefs.h>
ARM
struct KeyNode { unsigned short* keys; unsigned short count; unsigned short unknown; unsigned word; KeyNode* next; };
// Original: arm9/ov000 @ 0x02169AA4; symbol: CombatScript_CollectCommandGroupsByActionKey; size: 0x60.
// Collects a node once per matching key, stopping the inner scan at the requested match count.
// The original continues to the next node after that inner break.
extern "C" int CombatScript_CollectCommandGroupsByActionKey(KeyNode* node,int key,KeyNode** output,int capacity) {
 int matches=0;
 for(;node;node=node->next) {
 for(int i=0;i<node->count;++i) {
 if(key==node->keys[i]) {
 output[matches++]=node;
 if(matches==capacity)break;
 }
 }
 }
 return matches;
}

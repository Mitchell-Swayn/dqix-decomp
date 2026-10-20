#include <globaldefs.h>
ARM
#pragma optimization_level 4
struct KeyNode { unsigned char pad[0x20]; unsigned short key; unsigned char gap[0xe]; KeyNode* next; };
// Original: arm9/ov000 @ 0x021628C8; symbol: func_ov000_021628c8; size: 0x40.
// Copies each linked record's unsigned halfword key into the output and returns its count.
extern "C" int CombatScene_CollectCommandActorIndices(unsigned char* object,int index,int* output) {
 // The table address is formed before selecting its forty-byte entry.
 unsigned address=*(unsigned*)(object+0x29c)+0x821c;
 address+=index*40;
 KeyNode* node=*(KeyNode**)(address+0x10);
 int count=0;
 while(node) { output[count++]=node->key;node=node->next; }
 return count;
}

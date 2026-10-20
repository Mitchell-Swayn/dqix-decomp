#include <globaldefs.h>
ARM
struct LinkedIdNode {char pad[0x20];unsigned short id;char unknown[14];LinkedIdNode* next;};
struct LinkedIdEntry {char pad[0x10];LinkedIdNode* first;char unknown[20];};
// Original: arm9/ov000 @ 0x02162864; symbol: func_ov000_02162864; size: 0x64.
// Returns the entry index whose linked list contains the halfword ID, or -1.
extern "C" int CombatScene_FindCommandContainingActor(char* self,int id){
 LinkedIdEntry* entries;
 char* owner=*(char**)(self+0x29c);int count=*(int*)(owner+0x8e24);
 for(int index=0;index<count;++index){entries=(LinkedIdEntry*)(owner+0x821c);LinkedIdEntry* entry=entries+index;if(entry){for(LinkedIdNode* node=entry->first;node;node=node->next)if(node->id==id)return index;}}
 return -1;
}

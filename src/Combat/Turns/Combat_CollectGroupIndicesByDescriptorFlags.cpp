#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" char* _ZN9GameState19GetCombatantByIndexEi(void*,int);
extern "C" int Combat_IsCombatantExcludedFromSelection(char*);
extern "C" bool GameObject_IsDead(void*);
struct Group{unsigned char first;unsigned char low:4;unsigned char count:2;unsigned char high:2;unsigned char pad[4],ids[8];unsigned char size:4;unsigned char hi:4;unsigned char tail[9];};
struct GroupOwner{char padding[0x81b0];Group data;};
// Original: arm9/ov000 @ 0x0215EB1C; symbol: Combat_CollectGroupIndicesByDescriptorFlags; size: 0x100.
extern "C" int Combat_CollectGroupIndicesByDescriptorFlags(char* self,short* output,int capacity,unsigned flags){
GroupOwner *record;int count=0;
 for(int group=0;group<((GroupOwner*)self)->data.count;++group){record=(GroupOwner*)(self+group*24);for(int entry=0;entry<record->data.size;++entry){int id=(short)(record->data.ids[entry]+192);char *object=_ZN9GameState19GetCombatantByIndexEi(_ZN9GameState11GetInstanceEv(),id);if(!object)continue;if(!(flags&16)&&Combat_IsCombatantExcludedFromSelection(object))continue;if((flags&1)&&GameObject_IsDead(object))continue;output[count++]=id;if(count==capacity)return count;}}return count;
}

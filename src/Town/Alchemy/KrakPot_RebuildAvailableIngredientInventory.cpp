#include <globaldefs.h>
#include "GameState/GameState.h"
ARM
struct GameState;
struct S;
struct Owner;
struct IndexList { unsigned char pad0[12]; short ids[0x98]; unsigned char counts[0x98]; unsigned char pad1[0xf78-0x1d4]; unsigned char objects[4]; unsigned char count; };
extern "C" {
void* memcpy(void*,const void*,unsigned);
void* memset(void*,int,unsigned);
void* _ZN9GameState11GetInstanceEv();
void* GameState_GetIndexList(GameState*);
GameObject* GameState_GetObjectWithFlag100(GameState*,int);
unsigned int Inventory_GetGroupItemIds(S*,unsigned int);
unsigned int Inventory_GetGroupQuantities(unsigned char*,unsigned int);
int Inventory_GetGroupCapacity(short*,unsigned int);
void Memory_WriteWordAtOffset0(unsigned int*,unsigned int);
void Memory_WriteThreeWordsAtOffset4(unsigned int*,unsigned int,unsigned int,unsigned int);
void Util_AddCountToGroupedHalfwordEntry(Owner*,unsigned,int,int);
// Original data: arm9/ov006 @ 0x215fffe; symbol: data_ov006_0215fffe.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 100130009000c00050006000700040009800.
// Observed span: 18 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov006.md.
extern unsigned short KrakPotAllocateMenuResources_UnknownRoleInitializedBytes[];
// Original data: arm9/ov006 @ 0x2160010; symbol: data_ov006_02160010.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0000000001000000040000000200000005000000030000000600000007000000.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov006.md.
extern unsigned KrakPotRebuildAvailableIngredientInventory_UnknownRoleInitializedBytes[];
}
// Original: arm9/ov006 @ 0x02158DE0; symbol: func_ov006_02158de0; size: 0x1F8.
// Rebuilds nine grouped ID/count arrays from index-list entries and object slots.
extern "C" void KrakPot_RebuildAvailableIngredientInventory(unsigned char* self) {
 unsigned short limits[9];
 memcpy(limits,KrakPotAllocateMenuResources_UnknownRoleInitializedBytes,18);
 for(unsigned char i=0;i<9;++i) {
  unsigned n=limits[i];
  memset((*(short***)(self+0x48))[i],-1,n*2);
  memset((*(unsigned char***)(self+0x4c))[i],0,n);
  (*(unsigned short**)(self+0x50))[i]=0;
 }
 GameState* state=(GameState*)_ZN9GameState11GetInstanceEv();
 unsigned char* list=(unsigned char*)GameState_GetIndexList((GameState*)state);
 for(unsigned short i=0;i<0x98;++i)
  Util_AddCountToGroupedHalfwordEntry((Owner*)self,8,*(short*)(list+12+i*2),((IndexList*)list)->counts[i]);
 for(unsigned char i=0;i<((IndexList*)list)->count;++i) {
  unsigned char* obj=(unsigned char*)GameState_GetObjectWithFlag100(state,((IndexList*)list)->objects[i]);
  if(obj) {
   short* slots=(short*)(*(unsigned char**)(obj+0x150)+0x454);
   for(unsigned char j=0;j<8;++j)
    Util_AddCountToGroupedHalfwordEntry((Owner*)self,8,slots[j],1);
  }
 }
 for(unsigned char i=0;i<8;++i) {
  unsigned group=KrakPotRebuildAvailableIngredientInventory_UnknownRoleInitializedBytes[i];
  int n=Inventory_GetGroupCapacity((short*)(list+0x1d4),group);
  short* ids=(short*)Inventory_GetGroupItemIds((S*)(list+0x1d4),group);
  unsigned char* counts=(unsigned char*)Inventory_GetGroupQuantities(list+0x1d4,group);
  for(short j=0;j<n;++j)
   Util_AddCountToGroupedHalfwordEntry((Owner*)self,i,ids[j],counts[j]);
 }
 Memory_WriteWordAtOffset0((unsigned int*)(self+0x74),(unsigned int)(self+0x14c));
 Memory_WriteThreeWordsAtOffset4((unsigned int*)(self+0x74),*(unsigned*)(self+0x48),*(unsigned*)(self+0x4c),*(unsigned*)(self+0x50));
}

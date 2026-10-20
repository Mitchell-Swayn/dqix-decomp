#include <globaldefs.h>
ARM
extern "C" {
void* _ZN9GameState11GetInstanceEv();
unsigned char* _ZN9GameState14GetProtagonistEv(void*);
unsigned char* GameState_GetObjectWithFlag100(void*,int);
unsigned char* GameState_GetIndexList(void*);
void Memory_FreeThroughAllocatorUnion(void*,void*);
void _ZN13SafeAllocator7DestroyEv(void*);
void* _ZNK13SafeAllocator18GetSignedAllocatorEv(void*);
unsigned char* GameObject_GetLinkedIndexedState(void*);
int GameObject_HasLinkedStatusNibble(char*);
void Inventory_LogFirstAcquisitionAndUpdateCounters(void*,unsigned char*);
void AllocatePerCountBufferAndBuildGP2State(void*,const short*,int);
int Inventory_AddItemCountWithNinetyNineLimit(void*,int,int);
int Inventory_GetItemCount(char*,int);
unsigned char* ZoneState2754_FindPrimaryRecordByKey(void*,int);
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned char Main_UnknownRoleZeroInitializedStorage_Variant3[];
}
struct ActorList { char pad[0xf78]; unsigned char ids[4]; unsigned char count; };
struct ItemDetail { char pad[0x454]; short slots[8]; };
// Original: arm9/main @ 0x0207CF30; symbol: func_0207cf30; size: 0x204.
extern "C" int GameState_AddItemsAndDistributeOverflow(unsigned char* p,short key,short count,int distribute) {
 int created=0;
 if(!*(void**)(p+0x2c)) { AllocatePerCountBufferAndBuildGP2State(p,&key,1); created=1; }
 int result=0;
 unsigned char* record=ZoneState2754_FindPrimaryRecordByKey(*(void**)(p+0x2c),key);
 if(record) {
  void* state=_ZN9GameState11GetInstanceEv();
  unsigned char* inventory=GameState_GetIndexList(state);
  short available=count;
  short total=0;
  if(distribute) {
   int space=99-Inventory_GetItemCount((char*)GameState_GetIndexList(state),key);
   if(space>count) space=count;
   available=space;
  }
  result=Inventory_AddItemCountWithNinetyNineLimit(inventory,key,(signed char)available);
  total+=available;
  if(result) {
   Inventory_LogFirstAcquisitionAndUpdateCounters(p,record);
   *(unsigned*)(p+0x30)=*(unsigned*)(record+4);
   *(void**)(p+0x34)=*(void**)(_ZN9GameState14GetProtagonistEv(state)+0x134);
  }
  if(total<count && distribute) {
   ActorList* list=(ActorList*)GameState_GetIndexList(state);
   for(int i=0;i<list->count;i++) {
    unsigned char* object=GameState_GetObjectWithFlag100(state,list->ids[i]);
    if(!object || GameObject_HasLinkedStatusNibble((char*)object)) continue;
    ItemDetail* detail=(ItemDetail*)GameObject_GetLinkedIndexedState(object);
    if(!detail) continue;
    for(int j=0;j<8;j++) {
     if(detail->slots[j]<=0) {
      detail->slots[j]=key;
      Inventory_LogFirstAcquisitionAndUpdateCounters(p,record);
      ++total;
      if(total==count) break;
     }
    }
    if(total==count) break;
   }
  }
 }
 if(created) {
  void* allocation=_ZNK13SafeAllocator18GetSignedAllocatorEv(p);
  _ZN13SafeAllocator7DestroyEv(p);
  Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3,allocation);
  *(void**)(p+0x2c)=0;
 }
 return result;
}

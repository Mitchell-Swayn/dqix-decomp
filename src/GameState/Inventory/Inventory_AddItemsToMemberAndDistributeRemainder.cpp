#include <globaldefs.h>
ARM
extern "C" void AllocatePerCountBufferAndBuildGP2State(void*,const short*,int);
extern "C" char* ZoneState2754_FindPrimaryRecordByKey(void*,int);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" char* GameState_GetObjectWithFlag100(void*,int);
extern "C" int GameObject_HasLinkedStatusNibble(char*);
extern "C" unsigned char* GameObject_GetLinkedIndexedState(void*);
extern "C" void Inventory_LogFirstAcquisitionAndUpdateCounters(unsigned,unsigned char*);
extern "C" int GameState_AddItemsAndDistributeOverflow(void*,int,int,int);
extern "C" int Inventory_AddGroupedItemQuantityAndCacheResult(char*,unsigned,unsigned,...);
extern "C" int Inventory_AddSpecialItemQuantityAndCacheResult(char*,unsigned,unsigned,...);
extern "C" void* _ZNK13SafeAllocator18GetSignedAllocatorEv(void*);
extern "C" void _ZN13SafeAllocator7DestroyEv(void*);
extern "C" void Memory_FreeThroughAllocatorUnion(void*,void*);
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char Main_UnknownRoleZeroInitializedStorage_Variant3[];
struct Flags {unsigned kind:4;unsigned pad:21;unsigned special:1;unsigned rest:6;};
// Original: arm9/main @ 0x0207CCF0; symbol: func_0207ccf0; size: 0x240.
extern "C" int Inventory_AddItemsToMemberAndDistributeRemainder(char* self,short key,short count,int member,unsigned char force,unsigned char mode,unsigned char special) {
 int temporary=0;
 if(!*(void**)(self+0x2c)) {AllocatePerCountBufferAndBuildGP2State(self,&key,1);temporary=1;}
 int result=-1;
 char* record=ZoneState2754_FindPrimaryRecordByKey(*(void**)(self+0x2c),key);
 if(record) {
  char* obj=GameState_GetObjectWithFlag100(_ZN9GameState11GetInstanceEv(),member);
  if(!obj)return result;
  if(GameObject_HasLinkedStatusNibble(obj))return result;
  short* slots=(short*)(GameObject_GetLinkedIndexedState(obj)+0x454);
  short filled=0;
  if(force && special && ((Flags*)(record+8))->special) {
   if(GameState_AddItemsAndDistributeOverflow(self,key,count,mode)){filled=(short)count;result=1;}
  } else if(((Flags*)(record+8))->kind==8) {
   for(int i=0;i<8;i++) {
    if(slots[i]>0)continue;
    slots[i]=key;
    filled++;
    result=0;
    Inventory_LogFirstAcquisitionAndUpdateCounters((unsigned)self,(unsigned char*)record);
    *(int*)(self+0x30)=*(int*)(record+4);
    *(int*)(self+0x34)=*(int*)(obj+0x134);
    if(filled==count)break;
   }
  }
  if((result==0 && filled<count)||force) {
   short remaining=(short)(count-filled);
   unsigned kind=((Flags*)(record+8))->kind;
   int simple=(kind<=7)?1:0;
   if(simple) {
    if(Inventory_AddGroupedItemQuantityAndCacheResult(self,key,(signed char)remaining))result=1;
   } else if(kind==9) {
    if(Inventory_AddSpecialItemQuantityAndCacheResult(self,key,(signed char)remaining))result=1;
   } else if(GameState_AddItemsAndDistributeOverflow(self,key,remaining,mode))result=1;
  }
 } else result=-2;
 if(temporary) {
  void* allocator=_ZNK13SafeAllocator18GetSignedAllocatorEv(self);
  _ZN13SafeAllocator7DestroyEv(self);
  Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3,allocator);
  *(void**)(self+0x2c)=0;
 }
 return result;
}

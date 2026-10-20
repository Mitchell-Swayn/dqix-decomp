#include <globaldefs.h>
ARM
extern "C" {
struct Context {short a,b,blocked,key,last;unsigned short serial,group,pad;char** list;unsigned allocator;};
// Original data: arm9/main @ 0x2108cec; symbol: data_02108cec.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern Context ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage;
int _ZNK6Script9Parameter5ToIntEv(const void*);
float _ZNK6Script9Parameter7ToFloatEv(void*);
void* _ZN6Script9Parameter9ToVec3fixEP8Vector3i(void*,void*);
char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);
void* _ZN9GameState11GetInstanceEv();
int _ZNK9GameState21IsMorningDayOrEveningEv(void*);
void* GameState_GetSerializedProgressState();
void Script_InitializeActorMotionDescriptor(char*);
void Script_InsertActorMotionDescriptorByPriority(void*,void*);
void LinkedList_UnlinkMatchedKeyFromDoublyLinkedNodes(char**,int);
int Script_GetPackedEntryState(volatile unsigned char*,int);
unsigned int Script_GetEntryActivationFlagMask(unsigned char*,int);
unsigned int Script_GetEntryHighFlagMask(unsigned char*,int);
}
inline bool HasState(unsigned char* obj,int index,int state){return Script_GetPackedEntryState(obj,index)==state;}
// Original: arm9/main @ 0x0206CBCC; symbol: func_0206cbcc; size: 0x38C.
extern "C" int Script_AllocateFilteredRankedEntry(char* params,int count){
 (ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage.serial)++;
 unsigned char* obj;
 int index=_ZNK6Script9Parameter5ToIntEv(params);
 int state=_ZNK6Script9Parameter5ToIntEv(params+8);
 int time=_ZNK6Script9Parameter5ToIntEv(params+16);
 int group=_ZNK6Script9Parameter5ToIntEv(params+24);
 int key=_ZNK6Script9Parameter5ToIntEv(params+32);
 if(ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage.key!=key){ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage.key=key;ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage.last=-1;ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage.blocked=-1;}
 if(ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage.blocked>0)return 1;
 obj=(unsigned char*)GameState_GetSerializedProgressState();
 if(ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage.last!=index&&ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage.last>-1){
  if(!HasState(obj,index,1)&&!HasState(obj,index,2)&&HasState(obj,ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage.last,3)&&HasState(obj,index,3)){
   if(ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage.last>index)return 1;
  }
 }
 switch(state){
 case -1:if(!HasState(obj,index,0))return 1;break;
 case 3:if(!HasState(obj,index,1))return 1;break;
 case 0:if(!HasState(obj,index,2))return 1;break;
 case 1:if(!Script_GetEntryActivationFlagMask(obj,index))return 1;break;
 case 2:if(!HasState(obj,index,3))return 1;break;
 case 4:if(!Script_GetEntryHighFlagMask(obj,index)||!HasState(obj,index,0))return 1;break;
 }
 void* game=_ZN9GameState11GetInstanceEv();
 if(time==1){if(_ZNK9GameState21IsMorningDayOrEveningEv(game))return 1;}
 else if(time==0){if(!_ZNK9GameState21IsMorningDayOrEveningEv(game))return 1;}
 if(group!=ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage.group){
  LinkedList_UnlinkMatchedKeyFromDoublyLinkedNodes(ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage.list,key);return 1;
 }
 obj=(unsigned char*)_ZN13SafeAllocator8AllocateEj(ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage.allocator,0x78);
 if(!obj)return 0;
 Script_InitializeActorMotionDescriptor((char*)obj);
 *(short*)(obj+0x46)=index;
 obj[10]=(obj[10]&~3)|((unsigned char)time&3);
 *(short*)(obj+2)=group;obj[0]=key;
 if(count<6){LinkedList_UnlinkMatchedKeyFromDoublyLinkedNodes(ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage.list,key);ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage.last=index;return 1;}
 char* next=(char*)_ZN6Script9Parameter9ToVec3fixEP8Vector3i(params+40,obj+16);
 *(short*)(obj+28)=(int)(4096.0f*_ZNK6Script9Parameter7ToFloatEv(next));
 if(count>9)obj[30]=_ZNK6Script9Parameter5ToIntEv(next+8);
 *(unsigned short*)(obj+0x44)=ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage.serial;
 Script_InsertActorMotionDescriptorByPriority(ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage.list,obj);
 ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage.last=index;return 1;
}

#include <globaldefs.h>
ARM
struct Context{char pad[10];unsigned short sequence;unsigned short zone,padE;char** list;unsigned allocator;};
// Original data: arm9/main @ 0x2108cec; symbol: data_02108cec.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" Context ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage;
extern "C" void* GameState_GetSerializedProgressState();
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void*);
extern "C" unsigned BitArray_ReadNonnegativeIndexMask(void*,unsigned char*,int);
extern "C" int Script_GetRemappedProgressFlagMask(char*,int);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" int _ZNK9GameState21IsMorningDayOrEveningEv(void*);
extern "C" void LinkedList_UnlinkMatchedKeyFromDoublyLinkedNodes(char**,int);
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);
extern "C" void Script_InitializeActorMotionDescriptor(char*);
extern "C" char* _ZN6Script9Parameter9ToVec3fixEP8Vector3i(char*,void*);
extern "C" float _ZNK6Script9Parameter7ToFloatEv(void*);
extern "C" void Script_InsertActorMotionDescriptorByPriority(char**,char*);
// Original: arm9/main @ 0x0206D4E0; symbol: func_0206d4e0; size: 0x254.
extern "C" int Script_AppendConditionalZoneVectorRecord(char* params,int argc){
 if(argc<9)return 0;
 ++ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage.sequence;
 int optional=0;if(argc%2==0)optional=1;
 int pairs=optional?(argc-8)/2:(argc-7)/2;
 char* flags=(char*)GameState_GetSerializedProgressState();
 for(int left=pairs;left>0;--left){
  int key=_ZNK6Script9Parameter5ToIntEv(params);
  char* expectedParam=params+8;params+=16;
  int expected=_ZNK6Script9Parameter5ToIntEv(expectedParam);
  if((key>>16)==1){unsigned actual=BitArray_ReadNonnegativeIndexMask(flags,(unsigned char*)flags+0x8c,(unsigned short)key);if((expected && !actual)||(!expected && actual))return 1;}
  else if((key>>16)==2){int actual=Script_GetRemappedProgressFlagMask(flags,(unsigned short)key);if((expected && !actual)||(!expected && actual))return 1;}
  else return 1;
 }
 int day=_ZNK6Script9Parameter5ToIntEv(params);
 void* state=_ZN9GameState11GetInstanceEv();
 if(day==1){if(_ZNK9GameState21IsMorningDayOrEveningEv(state))return 1;}
 else if(day==0){if(!_ZNK9GameState21IsMorningDayOrEveningEv(state))return 1;}
 int zone=_ZNK6Script9Parameter5ToIntEv(params+8);
 int key=_ZNK6Script9Parameter5ToIntEv(params+16);
 if(zone!=ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage.zone){LinkedList_UnlinkMatchedKeyFromDoublyLinkedNodes(ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage.list,key);return 1;}
 char* record=_ZN13SafeAllocator8AllocateEj(ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage.allocator,120);if(!record)return 0;
 Script_InitializeActorMotionDescriptor(record);
 *(unsigned short*)(record+2)=zone;*(unsigned char*)record=key;
 if(argc-2*pairs-optional<4){LinkedList_UnlinkMatchedKeyFromDoublyLinkedNodes(ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage.list,*(unsigned char*)record);return 1;}
 char* next=_ZN6Script9Parameter9ToVec3fixEP8Vector3i(params+24,record+16);
 *(short*)(record+28)=(int)(4096.0f*_ZNK6Script9Parameter7ToFloatEv(next));
 if(optional)*(unsigned char*)(record+30)=_ZNK6Script9Parameter5ToIntEv(next+8);
 *(unsigned short*)(record+0x44)=ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage.sequence;
 *(unsigned char*)(record+10)|=4;
 Script_InsertActorMotionDescriptorByPriority(ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage.list,record);
 return 1;
}

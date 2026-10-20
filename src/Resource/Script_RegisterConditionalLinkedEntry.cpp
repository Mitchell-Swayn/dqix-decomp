#include <globaldefs.h>
ARM
struct Node;
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void*);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" bool _ZNK9GameState21IsMorningDayOrEveningEv(void*);
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);
extern "C" void Script_InitializeActorMotionDescriptor(char*);
extern "C" void LinkedList_UnlinkMatchedKeyFromDoublyLinkedNodes(char**,int);
extern "C" unsigned char* _ZN6Script9Parameter9ToVec3fixEP8Vector3i(void*,void*);
extern "C" float _ZNK6Script9Parameter7ToFloatEv(void*);
extern "C" void Script_InsertActorMotionDescriptorByPriority(Node**,Node*);
struct Global {unsigned char current[3],pad[7];unsigned short sequence,group,pad2;char** head;unsigned allocator;};
// Original data: arm9/main @ 0x2108cec; symbol: data_02108cec.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" Global ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage;
struct Bits {unsigned char mode:2,rest:6;};
// Original: arm9/main @ 0x0206C2C0; symbol: func_0206c2c0; size: 0x228.
extern "C" int Script_RegisterConditionalLinkedEntry(unsigned char* args,int count) {
 ++ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage.sequence;
 char* rec;
 int a=_ZNK6Script9Parameter5ToIntEv(args);
 int b=_ZNK6Script9Parameter5ToIntEv(args+8);
 int c=_ZNK6Script9Parameter5ToIntEv(args+16);
 int d=_ZNK6Script9Parameter5ToIntEv(args+24);
 int e=_ZNK6Script9Parameter5ToIntEv(args+32);
 int f=_ZNK6Script9Parameter5ToIntEv(args+40);
 int high=d*1000+e*10+f;
 int current=ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage.current[2]*1000+ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage.current[1]*10+ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage.current[0];
 int low=a*1000+b*10+c;
 if(current<low || high<current) return 1;
 int mode=_ZNK6Script9Parameter5ToIntEv(args+48);
 void* game=_ZN9GameState11GetInstanceEv();
 if(mode==1) {
  if(_ZNK9GameState21IsMorningDayOrEveningEv(game)) return 1;
 } else if(mode==0) {
  if(!_ZNK9GameState21IsMorningDayOrEveningEv(game)) return 1;
 }
 int group=_ZNK6Script9Parameter5ToIntEv(args+56);
 int key=_ZNK6Script9Parameter5ToIntEv(args+64);
 if(group!=ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage.group) {
  LinkedList_UnlinkMatchedKeyFromDoublyLinkedNodes(ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage.head,key);
  return 1;
 }
 rec=_ZN13SafeAllocator8AllocateEj(ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage.allocator,120);
 if(!rec) return 0;
 Script_InitializeActorMotionDescriptor(rec);
 rec[4]=a;rec[5]=b;rec[6]=c;rec[7]=d;rec[8]=e;rec[9]=f;
 ((Bits*)(rec+10))->mode=(unsigned char)mode;
 *(short*)(rec+2)=group;
 rec[0]=key;
 if(count<10) {
  LinkedList_UnlinkMatchedKeyFromDoublyLinkedNodes(ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage.head,key);
  return 1;
 }
 unsigned char* next=_ZN6Script9Parameter9ToVec3fixEP8Vector3i(args+72,rec+16);
 *(short*)(rec+0x1c)=(int)(4096.0f*_ZNK6Script9Parameter7ToFloatEv(next));
 if(count>13) rec[0x1e]=_ZNK6Script9Parameter5ToIntEv(next+8);
 *(short*)(rec+0x44)=ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage.sequence;
 Script_InsertActorMotionDescriptorByPriority((Node**)ScriptQueueFilteredRecord_UnknownRoleZeroInitializedStorage.head,(Node*)rec);
 return 1;
}

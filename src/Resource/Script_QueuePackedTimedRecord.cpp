#include <globaldefs.h>
ARM
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void*);
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);
extern "C" void* GameState_GetSerializedProgressState();
extern "C" int Script_GetPackedEntryState(volatile unsigned char*,int);
extern "C" void DecodePackedScriptParametersToLists(unsigned,int,void*,void*,void*);
extern "C" void Quest_PrependOrderCondition(unsigned char*,unsigned char*);
// Original data: arm9/main @ 0x2109404; symbol: data_02109404.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2109418; symbol: data_02109418.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char ScriptQueuePackedTimedRecord_UnknownRoleZeroInitializedStorage[],QuestGetGlobalOrderState_UnknownRoleZeroInitializedStorage[];
struct Flag16 {unsigned short key:9,a:1,b:1,c:1,d:1,e:1,pad:2;};
struct Time32 {unsigned byte:8,hour:6,minute:5,pad:13;};
struct Node {unsigned short zone;Flag16 flags;Time32 time;void* lists[2];};
// Original: arm9/main @ 0x02094D88; symbol: func_02094d88; size: 0x25C.
extern "C" int Script_QueuePackedTimedRecord(char* params,int count) {
 int key=_ZNK6Script9Parameter5ToIntEv(params);
 int zone=_ZNK6Script9Parameter5ToIntEv(params+8);
 unsigned current=*(unsigned short*)(ScriptQueuePackedTimedRecord_UnknownRoleZeroInitializedStorage+8);
 if(zone!=current) {
  if(current>=0xc3b5 && current<=0xc4e5) {if(zone!=0xc3b5)return 0;}
  else return 1;
 }
 int byte=_ZNK6Script9Parameter5ToIntEv(params+16);
 int hour=_ZNK6Script9Parameter5ToIntEv(params+24);
 int minute=_ZNK6Script9Parameter5ToIntEv(params+32);
 if(hour*100+minute>*(unsigned char*)(ScriptQueuePackedTimedRecord_UnknownRoleZeroInitializedStorage+3)*100+*(unsigned char*)(ScriptQueuePackedTimedRecord_UnknownRoleZeroInitializedStorage+4))return 0;
 int flag=_ZNK6Script9Parameter5ToIntEv(params+40);
 volatile unsigned char* state=(volatile unsigned char*)GameState_GetSerializedProgressState();
 int index=_ZNK6Script9Parameter5ToIntEv(params+48);
 if(index>=0) {
  int ready=(Script_GetPackedEntryState(state,index)==3)?1:0;
  if(!ready)return 0;
 }
 Node* node=(Node*)_ZN13SafeAllocator8AllocateEj(*(unsigned*)(ScriptQueuePackedTimedRecord_UnknownRoleZeroInitializedStorage+0xc),16);
 node->zone=(unsigned short)zone;
 node->flags.key=(unsigned short)key;
 node->time.byte=byte;node->time.hour=hour;node->time.minute=minute;
 node->flags.a=(unsigned short)flag;
 node->flags.c=(unsigned short)_ZNK6Script9Parameter5ToIntEv(params+56);
 node->flags.b=(unsigned short)_ZNK6Script9Parameter5ToIntEv(params+64);
 int d=_ZNK6Script9Parameter5ToIntEv(params+72);
 char* final=params+80;
 node->flags.d=(unsigned short)d;
 node->flags.e=(unsigned short)_ZNK6Script9Parameter5ToIntEv(final);
 node->lists[0]=0;node->lists[1]=0;
 unsigned extra=0;
 DecodePackedScriptParametersToLists(*(unsigned*)(ScriptQueuePackedTimedRecord_UnknownRoleZeroInitializedStorage+0xc),count-11,final+8,node->lists,&extra);
 Quest_PrependOrderCondition((unsigned char*)QuestGetGlobalOrderState_UnknownRoleZeroInitializedStorage,(unsigned char*)node);
 return 1;
}

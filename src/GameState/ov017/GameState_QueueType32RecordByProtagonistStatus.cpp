#include <globaldefs.h>
ARM
#pragma optimization_level 4
struct GameResources; struct Node;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void GameState_ClearByteSlots(void*);
extern "C" void* _ZN9GameState14GetProtagonistEv(void*);
extern "C" void* _ZN9GameState21GetPartyMemberByIndexEi(void*,int);
extern "C" void* GameState_GetIndexList(void*);
extern "C" int ReadByteAtOffset252(void*);
extern "C" int ReadByteFieldAtOffset26C(void*);
extern "C" unsigned ReadWordFieldAtOffset1C();
extern "C" void AppendLinkedNodeAndMarkActive(unsigned*,unsigned);
extern "C" bool IsFirstSignedWordZero(const int*);
extern "C" int LinkedList_ContainsTag(Node**,int);
extern "C" bool Object_TestElement380Exceeds0(signed char*);
extern "C" int Object_TestByteKeyInListedMemberIndices(unsigned char*,unsigned);
extern "C" void* Object_GetGlobalDisplayManager();
extern "C" int InsertRecordByDescendingClassification(unsigned char*,short,int,int);
extern "C" GameResources* GameResources_GetInstance();
extern "C" void* OV017_GetEmbeddedField1C(void*);
extern "C" void InitializeType32Record(void*,int);
extern "C" void Unclassified_QueueRecordWithByteArguments(unsigned char,unsigned char);
// Original: arm9/ov017 @ 0x021BFF8C; symbol: func_ov017_021bff8c; size: 0x198.
extern "C" void GameState_QueueType32RecordByProtagonistStatus(char* self,int value) {

 if(!Object_TestByteKeyInListedMemberIndices((unsigned char*)GameState_GetIndexList(_ZN9GameState11GetInstanceEv()),0)) {
  int same,busy; void* state; char* hero; char* first; unsigned shared;
  same=0; busy=0;
  state=_ZN9GameState11GetInstanceEv();
  first=(char*)_ZN9GameState21GetPartyMemberByIndexEi(state,0);
  hero=(char*)_ZN9GameState14GetProtagonistEv(state);
  shared=ReadWordFieldAtOffset1C();
  char* resources=(char*)GameResources_GetInstance();
  void* obj=0;
  if(resources) obj=*(void**)(resources+0x3718);
  if(obj) OV017_GetEmbeddedField1C(obj);
  unsigned id=*(unsigned short*)(hero+0x1b2);
  if(id) {
   if(*(unsigned short*)(first+0x1b2)==id) same=1;
   else busy=1;
  } else if(LinkedList_ContainsTag(*(Node***)(self+0x36fc),3)) busy=1;
  if(!IsFirstSignedWordZero(*(int**)(self+0x36fc))) busy=1;
  else if(Object_TestElement380Exceeds0((signed char*)hero)) busy=1;
  else if(!ReadByteAtOffset252(hero)) busy=1;
  else if(*(unsigned*)(shared+0x998)) busy=1;
  else if(ReadByteFieldAtOffset26C(hero)) busy=1;
  unsigned char key=*(short*)(hero+4)&0xff;
  if(same) { Unclassified_QueueRecordWithByteArguments(key,5); GameState_ClearByteSlots(state); return; }
  if(busy) { Unclassified_QueueRecordWithByteArguments(key,4); GameState_ClearByteSlots(state); return; }
  Unclassified_QueueRecordWithByteArguments(key,1);
  InsertRecordByDescendingClassification((unsigned char*)Object_GetGlobalDisplayManager(),0x2712,-1,value);
 }
 InitializeType32Record(*(void**)(self+0x3b1c),value);
 AppendLinkedNodeAndMarkActive(*(unsigned**)(self+0x36fc),*(unsigned*)(self+0x3b1c));
}

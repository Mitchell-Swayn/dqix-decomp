#include <globaldefs.h>
ARM
#pragma optimization_level 4
struct GameResources; struct Node;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void GameState_ClearByteSlots(void*);
extern "C" void* _ZN9GameState14GetProtagonistEv(void*);
extern "C" void* _ZN9GameState21GetPartyMemberByIndexEi(void*,int);
extern "C" void* GameState_GetIndexList(void*);
extern "C" int GameObject_GetMovementInputEnabled(void*);
extern "C" int GameObject_GetLadderTraversalActive(void*);
extern "C" unsigned TextContext_GetSharedInstance();
extern "C" void LinkedQueue_AppendAndMarkActive(unsigned*,unsigned);
extern "C" bool LinkedQueue_IsEmpty(const int*);
extern "C" int LinkedList_ContainsTag(Node**,int);
extern "C" bool GameObject_HasQueuedActions(signed char*);
extern "C" int PartyRoster_ContainsActiveObjectIndex(unsigned char*,unsigned);
extern "C" void* NavigationMessage_GetGlobalInstance();
extern "C" int NavigationMessage_EnqueueWithFormattedMemberName(unsigned char*,short,int,int);
extern "C" GameResources* GameResources_GetInstance();
extern "C" void* FieldBattle_GetEncounterRequest(void*);
extern "C" void PartyTransition_InitializeDialogueRequest(void*,int);
extern "C" void Field_QueuePartyTransitionResponse(unsigned char,unsigned char);
// Original: arm9/ov017 @ 0x021BFF8C; symbol: func_ov017_021bff8c; size: 0x198.
extern "C" void PartyTransition_QueueDialogueIfProtagonistReady(char* self,int value) {

 if(!PartyRoster_ContainsActiveObjectIndex((unsigned char*)GameState_GetIndexList(_ZN9GameState11GetInstanceEv()),0)) {
  int same,busy; void* state; char* hero; char* first; unsigned shared;
  same=0; busy=0;
  state=_ZN9GameState11GetInstanceEv();
  first=(char*)_ZN9GameState21GetPartyMemberByIndexEi(state,0);
  hero=(char*)_ZN9GameState14GetProtagonistEv(state);
  shared=TextContext_GetSharedInstance();
  char* resources=(char*)GameResources_GetInstance();
  void* obj=0;
  if(resources) obj=*(void**)(resources+0x3718);
  if(obj) FieldBattle_GetEncounterRequest(obj);
  unsigned id=*(unsigned short*)(hero+0x1b2);
  if(id) {
   if(*(unsigned short*)(first+0x1b2)==id) same=1;
   else busy=1;
  } else if(LinkedList_ContainsTag(*(Node***)(self+0x36fc),3)) busy=1;
  if(!LinkedQueue_IsEmpty(*(int**)(self+0x36fc))) busy=1;
  else if(GameObject_HasQueuedActions((signed char*)hero)) busy=1;
  else if(!GameObject_GetMovementInputEnabled(hero)) busy=1;
  else if(*(unsigned*)(shared+0x998)) busy=1;
  else if(GameObject_GetLadderTraversalActive(hero)) busy=1;
  unsigned char key=*(short*)(hero+4)&0xff;
  if(same) { Field_QueuePartyTransitionResponse(key,5); GameState_ClearByteSlots(state); return; }
  if(busy) { Field_QueuePartyTransitionResponse(key,4); GameState_ClearByteSlots(state); return; }
  Field_QueuePartyTransitionResponse(key,1);
  NavigationMessage_EnqueueWithFormattedMemberName((unsigned char*)NavigationMessage_GetGlobalInstance(),0x2712,-1,value);
 }
 PartyTransition_InitializeDialogueRequest(*(void**)(self+0x3b1c),value);
 LinkedQueue_AppendAndMarkActive(*(unsigned**)(self+0x36fc),*(unsigned*)(self+0x3b1c));
}

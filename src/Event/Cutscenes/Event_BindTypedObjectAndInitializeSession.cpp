#include <globaldefs.h>
#include <GameState/GameState.h>
#include <World/Object3D.h>
ARM
extern "C" int GameState_ReadProtagonistObjectIndex(GameState*);
extern "C" void *ActorPool_GetGlobalInstance();
extern "C" unsigned int *ActorPool_GetActiveSlot(unsigned int **p,unsigned int i);
extern "C" void CutsceneActor_InitializeCommandSession(char* self);
extern "C" void CutsceneActor_SetObjectSlot(void *record, unsigned int value);
extern "C" char* Event_GetObjectSession(int i);
struct FourWordState { int first; int second; int enabled; int fourth; };
extern "C" void Event_ResetObjectBinding(FourWordState*);
extern "C" int Event_BindIndexedGameObjectReference(void *base, int index, unsigned type, unsigned value, unsigned valid);
extern "C" int Event_BindIndexedActorPoolReference(unsigned char* records, int index, unsigned int type, unsigned int payload, unsigned int count);
// Original data: arm9/ov001 @ 0x2165880; symbol: data_ov001_02165880.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" unsigned char EventGetObjectSession_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov001 @ 0x0215AB54; symbol: func_ov001_0215ab54; size: 0x160.
// Resolves a typed object slot, initializes its session, and records its radius.
extern "C" void Event_BindTypedObjectAndInitializeSession(int type, int value, int index) {
 GameState *state=GameState::GetInstance();
 int radius=0x1000;
 FourWordState *states=*(FourWordState**)(EventGetObjectSession_UnknownRoleZeroInitializedStorage+4);
 Event_ResetObjectBinding(states+index);
 if(type==0 || type==1 || (unsigned)(type-4)<=1) {
  GameObject *object=0;
  if(type==0) object=state->GetGameObjectByIndex(GameState_ReadProtagonistObjectIndex(state));
  else if(type==1) object=state->GetGameObjectByIndex(value);
  else if(type==4) object=state->GetGameObjectByIndex(0);
  else if(type==5) object=state->GetGameObjectByIndex(value);
  if(!object) return;
  Event_BindIndexedGameObjectReference(*(void**)(EventGetObjectSession_UnknownRoleZeroInitializedStorage+4),index,type,value,(unsigned)object);
  radius=((Object3D*)object)->GetRadius();
 } else if(type==2 || type==6) {
  unsigned int *object=ActorPool_GetActiveSlot((unsigned int**)ActorPool_GetGlobalInstance(),value);
  if(!object) return;
  Event_BindIndexedActorPoolReference(*(unsigned char**)(EventGetObjectSession_UnknownRoleZeroInitializedStorage+4),index,type,value,(unsigned)object);
 }
 char *record=Event_GetObjectSession(index);
 if(record) {
  CutsceneActor_InitializeCommandSession(record);
  CutsceneActor_SetObjectSlot(record,index);
  *(int*)(record+0x90)=radius;
 }
}

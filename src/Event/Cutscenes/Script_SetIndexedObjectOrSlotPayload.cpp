#include <globaldefs.h>
ARM
struct GameState; struct IntegerParameterView; struct FourWordState;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* _ZN9GameState20GetGameObjectByIndexEi(void*,int);
extern "C" int GameState_ReadProtagonistObjectIndex(GameState*);
extern "C" void* ActorPool_GetGlobalInstance();
extern "C" unsigned int* ActorPool_GetActiveSlot(unsigned int**,unsigned int);
extern "C" void Event_ResetObjectBinding(FourWordState*);
extern "C" int Script_ResolveEventObjectIndex(int);
extern "C" int Event_BindIndexedGameObjectReference(unsigned char*,int,unsigned,unsigned,void*);
extern "C" int Event_BindIndexedActorPoolReference(unsigned char*,int,unsigned,unsigned,unsigned);
extern "C" int Script_ReadParameterAsInteger(IntegerParameterView*);
// Original data: arm9/ov001 @ 0x2165880; symbol: data_ov001_02165880.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" unsigned char* EventGetObjectSession_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov001 @ 0x0215BDD0; symbol: func_ov001_0215bdd0; size: 0x164.
extern "C" int Script_SetIndexedObjectOrSlotPayload(unsigned char* args) {
 void* game=_ZN9GameState11GetInstanceEv();
 int value;
 int index=Script_ReadParameterAsInteger((IntegerParameterView*)args);
 value=Script_ReadParameterAsInteger((IntegerParameterView*)(args+8));
 int type=Script_ReadParameterAsInteger((IntegerParameterView*)(args+16));
 value=Script_ResolveEventObjectIndex(value);
 Event_ResetObjectBinding((FourWordState*)(EventGetObjectSession_UnknownRoleZeroInitializedStorage[1]+index*16));
 if(type==0 || type==1 || (unsigned)(type-4)<=1) {
  void* object=0;
  if(type==0) object=_ZN9GameState20GetGameObjectByIndexEi(game,GameState_ReadProtagonistObjectIndex((GameState*)game));
  else if(type==1) object=_ZN9GameState20GetGameObjectByIndexEi(game,value);
  else if(type==4) object=_ZN9GameState20GetGameObjectByIndexEi(game,0);
  else if(type==5) object=_ZN9GameState20GetGameObjectByIndexEi(game,value);
  if(!object) return 0;
  return Event_BindIndexedGameObjectReference(EventGetObjectSession_UnknownRoleZeroInitializedStorage[1],index,type,value,object);
 }
 else if(type==2 || type==6) {
  unsigned int* slot=ActorPool_GetActiveSlot((unsigned int**)ActorPool_GetGlobalInstance(),value);
  if(!slot) return 0;
  slot[0]|=0x10000;
  return Event_BindIndexedActorPoolReference(EventGetObjectSession_UnknownRoleZeroInitializedStorage[1],index,type,value,(unsigned)slot);
 }
 return 0;
}

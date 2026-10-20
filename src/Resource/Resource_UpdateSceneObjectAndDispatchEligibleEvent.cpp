#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Resource/GameResources.h>
#include <Resource/Brightness.h>
ARM
#pragma opt_common_subs off
#pragma opt_dead_assignments off
struct Scene { signed char mode; unsigned char pad[2]; unsigned char enabled; };
struct SceneOwner { Scene* scene; };
struct ResourceView { unsigned char pad[0x36fc]; SceneOwner* owner; };
extern "C" unsigned short* Zone3D_GetMainInstance();
extern "C" void Network_GetConnectionManager();
extern "C" void* GameState_GetFieldVisualObject(GameState*);
extern "C" int LinkedQueue_GetFrontKindOrInvalid(SceneOwner*);
extern "C" Scene* LinkedQueue_GetFrontNode(SceneOwner*);
extern "C" void FieldVisualActor_UpdateMotionAndPartyInteraction(void*);
extern "C" int GameResources_GetMaskedPrimaryFlags(GameResources*,unsigned);
extern "C" void Field_ResolveObjectZoneCollision(void*,int);
extern "C" void AccumulateTravelDistanceAndDecrementWorldCounter(void*);
extern "C" int Object3D_TestOpposedDirectionSustainedForFortyTicks(void*,int*,int*);
extern "C" int LinkedQueue_IsEmpty(SceneOwner*);
extern "C" void Field_QueueFixedDestinationConfirmation(GameResources*,int,int);
// Original: arm9/main @ 0x020A654C; symbol: func_020a654c; size: 0x158.
extern "C" void Resource_UpdateSceneObjectAndDispatchEligibleEvent(GameResources* resources) {
 GameState* state=GameState::GetInstance();
 unsigned short* selection;
 SceneOwner* owner=reinterpret_cast<ResourceView*>(resources)->owner;
 selection=Zone3D_GetMainInstance();
 Network_GetConnectionManager();
 void* object=GameState_GetFieldVisualObject(state);
 state->GetUnknownGameObject();
 int mode=LinkedQueue_GetFrontKindOrInvalid(owner);
 Scene* scene=LinkedQueue_GetFrontNode(owner);
 if(object && (mode!=10 || !scene->enabled) && (mode!=3 || IsBrightnessTransitionActive(resources))) {
  FieldVisualActor_UpdateMotionAndPartyInteraction(object);
  if(!GameResources_GetMaskedPrimaryFlags(resources,0x2020)) Field_ResolveObjectZoneCollision(object,1);
  if(*selection==10000) AccumulateTravelDistanceAndDecrementWorldCounter(object);
  if(!GameResources_GetMaskedPrimaryFlags(resources,0x2020)) {
   int event=0,kind=0;
   if(Object3D_TestOpposedDirectionSustainedForFortyTicks(object,&event,&kind)) {
    if(kind && kind==1) event=0x76c;
    if(event && LinkedQueue_IsEmpty(reinterpret_cast<ResourceView*>(resources)->owner)) Field_QueueFixedDestinationConfirmation(resources,event,0);
   }
  }
 }
}

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
extern "C" unsigned short* ReadGlobalValueAt020FB3F0();
extern "C" void Object_GetGlobalConnectionState();
extern "C" void* ReadSignedWordField32C(GameState*);
extern "C" int ReadIndirectByteOrMinusOne(SceneOwner*);
extern "C" Scene* Record_ReadInitialWord(SceneOwner*);
extern "C" void func_020a75ec(void*);
extern "C" int ReadMaskedWord(GameResources*,unsigned);
extern "C" void Unclassified_InvokeHelperWithFourZeroArguments(void*,int);
extern "C" void AccumulateTravelDistanceAndDecrementWorldCounter(void*);
extern "C" int Object3D_TestOpposedDirectionSustainedForFortyTicks(void*,int*,int*);
extern "C" int IsFirstSignedWordZero(SceneOwner*);
extern "C" void Resource_CreateKind39RecordAndAppend(GameResources*,int,int);
// Original: arm9/main @ 0x020A654C; symbol: func_020a654c; size: 0x158.
extern "C" void UpdateSceneObjectAndDispatchEligibleEvent(GameResources* resources) {
 GameState* state=GameState::GetInstance();
 unsigned short* selection;
 SceneOwner* owner=reinterpret_cast<ResourceView*>(resources)->owner;
 selection=ReadGlobalValueAt020FB3F0();
 Object_GetGlobalConnectionState();
 void* object=ReadSignedWordField32C(state);
 state->GetUnknownGameObject();
 int mode=ReadIndirectByteOrMinusOne(owner);
 Scene* scene=Record_ReadInitialWord(owner);
 if(object && (mode!=10 || !scene->enabled) && (mode!=3 || IsBrightnessTransitionActive(resources))) {
  func_020a75ec(object);
  if(!ReadMaskedWord(resources,0x2020)) Unclassified_InvokeHelperWithFourZeroArguments(object,1);
  if(*selection==10000) AccumulateTravelDistanceAndDecrementWorldCounter(object);
  if(!ReadMaskedWord(resources,0x2020)) {
   int event=0,kind=0;
   if(Object3D_TestOpposedDirectionSustainedForFortyTicks(object,&event,&kind)) {
    if(kind && kind==1) event=0x76c;
    if(event && IsFirstSignedWordZero(reinterpret_cast<ResourceView*>(resources)->owner)) Resource_CreateKind39RecordAndAppend(resources,event,0);
   }
  }
 }
}

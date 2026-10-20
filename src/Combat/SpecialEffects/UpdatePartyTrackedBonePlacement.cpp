#include <globaldefs.h>
#include <GameState/GameState.h>
#include <World/Object3D.h>
#include <Graphics/Model3D.h>
#include <Memory/SafeAllocator.h>
// Matches the owner-local typedef in Object_ReadWordAtOffset21C.cpp.
typedef unsigned int undefined4;
ARM
#pragma optimization_level 4
#pragma opt_rotateloops off
#pragma opt_unpromotetypes on
extern "C" void* __clear(void*,unsigned int);
extern "C" void* GameState_ReadUnknownB0(GameState*);
extern "C" unsigned BoneTrackingCamera_GetSourceObject(int);
extern "C" int Combat_CollectEligiblePartyIds(void*,short*,int,int);
extern "C" int Combat_ClassifySpecialEncounterSpecies(unsigned char*);
extern "C" unsigned PartySelection_GetMemberMask(unsigned char*,unsigned);
extern "C" GameObject* GameState_GetObjectWithFlag100(GameState*,int);
extern "C" void Object3D_SetNormalizedAngleAndUpdatePosition(char*,int);
extern "C" void GameObject_SetMotionStateAndRefreshAnimation(unsigned char*,unsigned char);
extern "C" void* BattleScene_GetCamera(unsigned char*);
extern "C" void GameState_SetUnknown3b0(GameState*,void*);
extern "C" void BattleScene_ConfigureOpeningCamera(void*,int);
extern "C" void BattleScene_RestoreCombatantHomeTransforms(unsigned char*);
extern "C" void BattleScene_FaceMonstersTowardCameraAndStaggerAnimations(char*,char*,int);
extern "C" void Combat_UpdateSelectedObjectVisibility(char*,int,int);
extern "C" void GameState_ClearObjectByIndex(GameState*,int);
extern "C" void GameState_ClearSpecialBattleSequenceFlag(int);
// Original data: arm9/ov026 @ 0x21de6a0; symbol: data_ov026_021de6a0.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 6662.
// Observed span: 2 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov026.md.
extern "C" unsigned char UpdatePartyTrackedBonePlacement_UnknownRoleInitializedBytes[];
extern "C" char UpdatePartyTrackedBonePlacement_FormatCD[];
// Original: arm9/ov026 @ 0x021DC040; symbol: func_ov026_021dc040; size: 0x400.
// Places selected party objects at tracked model bones, recenters them, then restores combat state when the model animation finishes.
extern "C" int UpdatePartyTrackedBonePlacement(SafeAllocator* allocator,char* combat,char* group,unsigned char* selection) {
 int second,first;
 GameState* state=GameState::GetInstance();
 void* linked=GameState_ReadUnknownB0(state);if(!linked)return 1;
 Object3D* primary=(Object3D*)BoneTrackingCamera_GetSourceObject((int)linked);if(!primary)return 1;
 Object3D* tracked=(Object3D*)state->GetGameObjectByIndex(0xcf);if(!tracked)return 1;
 tracked->UpdateTrackedBoneMatrices();
 Model3D* model=tracked->pModel_;
 if(model) {
  short ids[4];int count=Combat_CollectEligiblePartyIds(group,ids,4,0);
  if(Combat_ClassifySpecialEncounterSpecies((unsigned char*)group))count=1;
  if(count>0) {
   Vector3fix sum;__clear(&sum,12);
   int counts[2];__clear(counts,8);
   first=UpdatePartyTrackedBonePlacement_UnknownRoleInitializedBytes[0];second=UpdatePartyTrackedBonePlacement_UnknownRoleInitializedBytes[1];
   for(int i=0;i<count;i++) {
    if(!PartySelection_GetMemberMask(selection,(unsigned char)ids[i]))continue;
    GameObject* gameObject=GameState_GetObjectWithFlag100(state,ids[i]);
    if(!gameObject)continue;
    char* object=(char*)gameObject;
    if(!*(void**)(object+8))continue;
    unsigned short kind=(unsigned short)((*(unsigned*)(*(char**)(object+0x134)+0x3c)<<1)>>31);
    char names[2];names[0]=first;counts[kind]++;names[1]=second;
    kind=(unsigned short)((*(unsigned*)(*(char**)(object+0x134)+0x3c)<<1)>>31);
    char name[6];sprintf(name,UpdatePartyTrackedBonePlacement_FormatCD,names[kind],counts[kind]);
    Object3D::TrackedBoneMatrix* bone=tracked->GetTrackedBoneMatrix(model->GetBoneIndex(name));
    if(!bone)continue;
    Vector3fix pos;pos.x=*(int*)((char*)bone+0x28);pos.y=*(int*)((char*)bone+0x2c);pos.z=*(int*)((char*)bone+0x30);
    Vector3fixMultiplyScalar(&pos,0x10a,&pos);
    *(Vector3i*)(object+0x44)=pos;
    Object3D_SetNormalizedAngleAndUpdatePosition(object,fix32_Atan2(*(int*)((char*)bone+0x1c),*(int*)((char*)bone+0x24)));
    Vector3fix_Add(&sum,&pos,&sum);
   }
   Vector3fixMultiplyScalar(&sum,(int)(4096.0f*(1.0f/(float)count)),&sum);
   int offset=-sum.x;
   for(int i=0;i<count;i++) {
    if(PartySelection_GetMemberMask(selection,(unsigned char)ids[i])) {
     char* object=(char*)GameState_GetObjectWithFlag100(state,ids[i]);
     if(object) {Vector3i pos=*(Vector3i*)(object+0x44);pos.y=0xcc;pos.x+=offset;*(Vector3i*)(object+0x44)=pos;}
    }
   }
  }
 }
 if(*(signed char*)(combat+0x7712)==0 && !primary->HasAnimationStopped())return 0;
 if(*(signed char*)(combat+0x7712)!=6) {
  for(int i=0;i<4;i++)if(PartySelection_GetMemberMask(selection,(unsigned char)i)) {
   GameObject* gameObject=GameState_GetObjectWithFlag100(state,i);
   Object3D* object=(Object3D*)gameObject;
   if(object){object->RemoveAnimationPackageByID(3);GameObject_SetMotionStateAndRefreshAnimation((unsigned char*)object,0);Object3D_SetNormalizedAngleAndUpdatePosition((char*)object,0x3244);}
  }
  GameState_SetUnknown3b0(state,BattleScene_GetCamera((unsigned char*)combat));
  BattleScene_ConfigureOpeningCamera(combat,1);BattleScene_RestoreCombatantHomeTransforms((unsigned char*)combat);
  BattleScene_FaceMonstersTowardCameraAndStaggerAnimations(group,(char*)BattleScene_GetCamera((unsigned char*)combat),1);
  Combat_UpdateSelectedObjectVisibility(combat,0x26,0);Combat_UpdateSelectedObjectVisibility(combat,0x27,1);
  allocator->Reset();GameState_ClearObjectByIndex(state,0xcf);GameState_ClearSpecialBattleSequenceFlag((int)state);
 }
 return 1;
}

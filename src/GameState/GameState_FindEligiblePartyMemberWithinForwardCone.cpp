#pragma opt_propagation off
#include <globaldefs.h>
#include "GameState/GameState.h"
#include "World/Object3D.h"
#include "System/Matrix.h"
#include "Graphics/Vector.h"
#include <std_library_functions.h>
#pragma always_inline on
extern "C" void __clear(void*,unsigned int);
extern "C" int GameObject_GetFollowPredecessorMember(Object3D*),GameObject_GetAuthorityMotionState(Object3D*),GameObject_TestRemoteMemberStatusMask4000(Object3D*);
extern "C" unsigned char* GameObject_GetLinkedIndexedState(Object3D*);
extern "C" void GameObject_GetAuthorityPosition(Vector3fix*,Object3D*);
// Original: arm9/main @ 0x02079238; symbol: func_02079238; size: 0x188.
extern "C" ARM int GameState_FindEligiblePartyMemberWithinForwardCone(Object3D* source,int distance) {
 GameState* state=GameState::GetInstance();
 for(int i=0;i<4;++i) {
  Object3D* object=(Object3D*)state->GetPartyMemberByIndex(i);
  if(!object) {if(!i)return -1;continue;}
  if(GameObject_GetFollowPredecessorMember(object)!=-1)continue;
  if(source->GetField06()!=object->GetField06())continue;
  if(!GameObject_GetAuthorityMotionState(object) || ((unsigned char*)object)[0xc0]==6)continue;
  if(object->GetField06()!=source->GetField06())continue;
  if(GameObject_GetLinkedIndexedState(object)[0x56c])continue;
  if(**(unsigned int**)((char*)object+0x130)&1)continue;
  int stateByte=((unsigned char*)object)[0xc3];
  if(stateByte>0)continue;
  if(GameObject_TestRemoteMemberStatusMask4000(object))continue;
  Vector3fix copy,difference,forward,position;
  GameObject_GetAuthorityPosition(&position,object);
  struct ArrayVec3 {fix32_t values[3];};
  *(ArrayVec3*)&copy=*(const ArrayVec3*)&position;
  Vector3fix_Subtract(&copy,(Vector3fix*)((char*)source+0x44),&difference);
  int length=Vector3fix_Length(&difference);
  if(length<=distance) {
   short angle=*(short*)((char*)source+0xae);__clear(&forward,12);
   forward.x=fix32sin(angle);forward.z=fix32cos(angle);
   int dot=Vector3fix_InnerProduct(&difference,&forward);
   if(fix32_Divide(dot,length)>0xb50)return (short)i;
  }
 }
 return -1;
}

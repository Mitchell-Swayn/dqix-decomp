#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Graphics/Vector.h>
#include <System/Matrix.h>
#include <World/Object3D.h>
ARM
extern "C" ARM void Object_AdvanceYawTowardTargetAndAnimationState(Object3D*);
extern "C" void Object3D_AdvanceSpeedAndPosition(Object3D*);
extern "C" void AdvancePositionTowardTargetByLengthStep(unsigned char*);
extern "C" ARM void Object3D_UpdateVisibilityAndAlphaByKind(unsigned char*);
extern "C" void GameObject_UpdateCurrentPathNode(unsigned char*);
// Original data: arm9/main @ 0x20ef9d0; symbol: data_020ef9d0.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ff010203020101010108010101ff060606060606060608060606ff07070707070707070807070700080808080808080808080808060909090909090909080909 ...; full span in module reference.
// Observed span: 108 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" signed char Object3DAdvanceMotionAnimationAndLinkedPoint_UnknownRoleInitializedBytes[];
// Original: arm9/main @ 0x020332AC; symbol: func_020332ac; size: 0x1E0.
// Advances movement with tick-scaled acceleration, animation kind transitions,
// the byte countdown, linked-point selection, and effects.
extern "C" void Object3D_AdvanceMotionAnimationAndLinkedPoint(unsigned char* object) {
 if(!(((unsigned)object[0xe0]<<29)>>31)) {
  Object_AdvanceYawTowardTargetAndAnimationState((Object3D*)object);
  Object3D_AdvanceSpeedAndPosition((Object3D*)object);
  if(((unsigned)object[0xe0]<<27)>>31) {
   object[0xe0]&=~16;
   if(((unsigned)object[0xe0]<<26)>>31) {
    object[0xe0]&=~32;
    *(Vector3fix*)(object+0x44)=*(Vector3fix*)(object+0xd4);
   } else {
    Vector3fix delta,normal,step,result;
    Vector3fix_Subtract((Vector3fix*)(object+0xd4),(Vector3fix*)(object+0x44),&delta);
    int distance=Vector3fix_Length(&delta);
    if(distance>0) {
     GameState* state=GameState::GetInstance();
     int acceleration=*(short*)(object+0xb6)*state->GetTickCount();
     Vector3fixMultiplyScalar(&delta,fix32_Divide(4096,distance),&normal);
     if(*(short*)(object+0xb2)<=distance) {
      *(short*)(object+0xb2)+=acceleration;
      if(*(short*)(object+0xb4)<*(short*)(object+0xb2)) *(short*)(object+0xb2)=*(short*)(object+0xb4);
     } else {
      *(short*)(object+0xb2)-=acceleration;
      if(*(short*)(object+0xb2)<0) *(short*)(object+0xb2)=0;
     }
     int amount=*(short*)(object+0xb2)*state->GetTickCount();
     if(distance<amount) amount=distance;
     Vector3fixMultiplyScalar(&normal,amount,&step);
     Vector3fix_Add((Vector3fix*)(object+0x44),&step,&result);
     *(Vector3fix*)(object+0x44)=result;
    } else *(short*)(object+0xb2)=0;
   }
  }
  AdvancePositionTowardTargetByLengthStep(object);
  if(((Object3D*)object)->HasAnimationStopped() || ((Object3D*)object)->HasAnimationReachedEnd()) {
   object[0xbf]=object[0xbe];
   int next=Object3DAdvanceMotionAnimationAndLinkedPoint_UnknownRoleInitializedBytes[object[0xbe]*13];
   if(next>-1) object[0xbe]=next;
   Object3D_UpdateVisibilityAndAlphaByKind(object);
  }
 }
 int timer=object[0xc3];
 if(timer) {
  timer-=GameState::GetInstance()->GetTickCount();
  if(timer<0) timer=0;
  object[0xc3]=timer;
 }
 GameObject_UpdateCurrentPathNode(object);
 ((Object3D*)object)->AdvanceEffects();
}

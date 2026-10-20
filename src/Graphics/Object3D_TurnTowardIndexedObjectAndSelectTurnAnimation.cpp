#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Graphics/Vector.h>
extern "C" int Vector3fix_ComputeReverseXZHeading(const Vector3fix*,const Vector3fix*);
extern "C" void SetObjectAngleAndClearFlagC48000(Object3D*,int);
extern "C" const char Object_AdvanceYawTowardTargetAndAnimationState_TextRun[];
// Original: arm9/main @ 0x02033920; symbol: func_02033920; size: 0xA8.
extern "C" void Object3D_TurnTowardIndexedObjectAndSelectTurnAnimation(Object3D* p,int id,int turn) {GameState* state=GameState::GetInstance();if(id==*(short*)((char*)p+4))return;GameObject* target=state->GetGameObjectByIndex(id);if(!target)return;SetObjectAngleAndClearFlagC48000(p,Vector3fix_ComputeReverseXZHeading(&target->obj3D_.position_,&p->position_));if(!turn)return;if(*((unsigned char*)p+0xbe))return;int distance=fix32abs(fix32SignedAngleDistance(*(int*)((char*)p+0x54),*(short*)((char*)p+0xae)));if(distance<=0x1000)return;if(*(short*)((char*)p+0xb0)>0x10c)return;if(p->SetAnimationByName(Object_AdvanceYawTowardTargetAndAnimationState_TextRun,0x11))*(unsigned short*)((char*)p+0xc4)|=0x8000;}

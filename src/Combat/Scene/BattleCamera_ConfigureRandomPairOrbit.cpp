// Original: arm9/ov000 @ 0x0216DA34; symbol: BattleCamera_ConfigureRandomPairOrbit; size: 0x1BC.
#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Graphics/Vector.h>
#include <Util/Random.h>
ARM
struct Triple{int x,y,z;};struct Block{unsigned words[12];};struct CombatCoordinate3{int x,y,z;};
extern "C" {
void BattleCamera_ResetShotAndTransitions(unsigned char*,int,int,int);
void Math_BuildYUpBasisAndTranslation(const Vector3fix*,const Vector3fix*,Matrix4x3*);
void Camera_SetParentTransform(char*,Block*);void Camera_EnableParentTransform(int);
void Camera_SetOrbitParameters(void*,const Triple*);
extern const CombatCoordinate3 BattleCamera_ConfigureRandomPairOrbit_FormationTransformTemplate;
}
extern "C" void BattleCamera_ConfigureRandomPairOrbit(unsigned char* camera,int first,int second){
GameState* game=GameState::GetInstance();char* actor=(char*)game->GetCombatantByIndex(first);char* target=(char*)game->GetCombatantByIndex(second);if(!actor||!target)return;
BattleCamera_ResetShotAndTransitions(camera,1,1,1);Vector3fix actorPosition=*(Vector3fix*)(actor+0x44);Vector3fix targetPosition=*(Vector3fix*)(target+0x44);Vector3fix direction;Vector3fix center;
if(first!=second){Vector3fix_Subtract(&targetPosition,&actorPosition,&direction);Vector3fix_Normalize(&direction,&direction);Vector3fix_Add(&targetPosition,&actorPosition,&center);Vector3fixMultiplyScalar(&center,0x800,&center);}
else{int yaw=*(int*)(actor+0x54);int cos=fix32cos(yaw);direction.x=fix32sin(yaw);direction.y=0;direction.z=cos;center=actorPosition;}
Matrix4x3 transform;Math_BuildYUpBasisAndTranslation(&direction,&center,&transform);Camera_SetParentTransform((char*)camera,(Block*)&transform);Camera_EnableParentTransform((int)camera);
CombatCoordinate3 up=BattleCamera_ConfigureRandomPairOrbit_FormationTransformTemplate;int base;Random* random=*(Random**)(camera+0x21c);base=0;if(!NextRandomMax(random,2))base=0x3244;int angle;int toss=NextRandomMax(random,2);if(toss==0)angle=fix32ReduceAngle0To2Pi(base+0x4cc);else angle=fix32ReduceAngle0To2Pi(base-0x4cc);Triple orbit;orbit.x=angle;orbit.y=0x1000;orbit.z=0x8000;*(Vector3fix*)(camera+0x10)=*(Vector3fix*)&up;Camera_SetOrbitParameters(camera,&orbit);*(int*)(camera+0x23c)=-20;
}

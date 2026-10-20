#include <globaldefs.h>
#include <GameState/GameState.h>
#include <World/Object3D.h>
#include <Graphics/Vector.h>
struct MovementFlagE0 { unsigned char blocked:1; unsigned char rest:7; };
struct MovementFlagC2 { unsigned char low:5; unsigned char blocked:1; unsigned char high:2; };
struct MovementFlagC1 { unsigned char low:2; unsigned char blocked:1; unsigned char high:5; };
struct MovementCountdown { unsigned short remaining:15; unsigned short pending:1; };
// Original: arm9/main @ 0x0203348C; symbol: func_0203348c; size: 0x284.
// Advances an object's speed, facing-dependent displacement, Y wrap, and vertical residual.
// Proposed descriptive name: Object3D_AdvanceSpeedAndPosition.
extern "C" void Object3D_AdvanceSpeedAndPosition(Object3D *object)
{
 unsigned char *p=(unsigned char *)object;
 if(((MovementFlagE0 *)(p+0xe0))->blocked) return;
 if(((MovementFlagC2 *)(p+0xc2))->blocked) return;
 if(((MovementFlagC1 *)(p+0xc1))->blocked) return;
 GameState *game=GameState::GetInstance();
 unsigned int elapsed=game->GetEffectiveDeltaTime();
 unsigned int ticks=game->GetTickCount();
 MovementCountdown *countdown=(MovementCountdown *)(p+0xc4);
 bool active=countdown->remaining!=0;
 if(active) {
  if(elapsed>=countdown->remaining) countdown->remaining=0;
  else countdown->remaining-=elapsed;
 }
 int speed=*(short *)(p+0xb2);
 int acceleration=*(short *)(p+0xb6)*ticks;
 if(p[0xbe]==1) {
  int target=*(short *)(p+0xb4);
  if(speed<target) *(short *)(p+0xb2)=acceleration+speed;
  else if(speed-target<acceleration) *(short *)(p+0xb2)=target;
  else *(short *)(p+0xb2)=speed-acceleration;
 } else {
  if(speed>0) *(short *)(p+0xb2)=speed-acceleration;
  else *(short *)(p+0xb2)=0;
 }
 active=countdown->remaining!=0;
 if(active || *(int *)(p+0x124)!=0) speed=0;
 if(0.0f<(float)speed) {
  int limit;
  int yaw=object->rotation_.y;
  limit=*(short *)(p+0xb4);
  int angle=fix32abs(fix32SignedAngleDistance(yaw,*(short *)(p+0xae)));
  limit=FIX32_MULTIPLY(limit,0x1000-fix32_Divide(angle,0x3244));
  if(limit<speed) speed=limit;
  speed*=ticks;
  if(object->unknown_0_&0x100) yaw=*(short *)(p+0xae);
  Vector3fix direction;
  direction.x=fix32sin(yaw);direction.y=0;direction.z=fix32cos(yaw);
  Vector3fixMultiplyScalar(&direction,speed,&direction);
  Vector3fix translated;
  Vector3fix_Add(&object->position_,&direction,&translated);
  object->position_=translated;
 }
 Vector3fix position=object->position_;
 position.y-=*(short *)(p+0xac);
 if(position.y < -0x32000) position.y=0x32000;
 object->position_=position;
 if(*(int *)(p+0x124)!=0) {
  ++*(volatile unsigned short *)(p+0x12c);
  *(int *)(p+0x124)-=*(volatile unsigned short *)(p+0x12c)*0x51;
  if(*(int *)(p+0x124)<*(int *)(p+0x128)) {
   *(volatile unsigned short *)(p+0x12c)=0;
   *(int *)(p+0x124)=0;
   *(int *)(p+0x128)=0;
  }
 }
}

#include <globaldefs.h>
#include <GameState/GameState.h>
#include <World/Object3D.h>
#include <Graphics/Vector.h>
extern "C" char Object_AdvanceYawTowardTargetAndAnimationState_TextRun[];
extern "C" int strcmp(const char*,const char*);
extern "C" void GameObject_SetMotionStateAndRefreshAnimation(Object3D*,int);
struct Flags {unsigned short low:15;unsigned short pending:1;};
// Original: arm9/main @ 0x02033710; symbol: func_02033710; size: 0x124.
extern "C" ARM void Object_AdvanceYawTowardTargetAndAnimationState(Object3D* object){GameState* game=GameState::GetInstance();char* p=(char*)object;if((unsigned char)p[0xbe]==4||(unsigned char)p[0xbe]==6)return;int step=*(short*)(p+0xb0)*game->GetTickCount();Vector3i rotation=*(Vector3i*)(p+0x50);int distance=fix32SignedAngleDistance(rotation.y,*(short*)(p+0xae));bool reached=true;if(distance>0){if(distance<step)rotation.y=*(short*)(p+0xae);else{rotation.y+=step;reached=false;}}else if(distance<0){distance=-distance;if(distance<step)rotation.y=*(short*)(p+0xae);else{rotation.y-=step;reached=false;}}rotation.y=fix32ReduceAngle0To2Pi(rotation.y);*(Vector3i*)(p+0x50)=rotation;Flags* flags=(Flags*)(p+0xc4);if(reached&&flags->pending){unsigned mode=object->IsTransitioningAnimations();if(mode==0){flags->pending=0;mode=(unsigned char)p[0xbe];if(mode==0&&*(char**)(p+0x14)&&strcmp(*(char**)(p+0x14),Object_AdvanceYawTowardTargetAndAnimationState_TextRun)==0)GameObject_SetMotionStateAndRefreshAnimation(object,0);}}}

#include <globaldefs.h>
ARM
struct Object3D;struct Owner;struct GameState;
struct Vector {int x,y,z;};
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" Object3D* _ZN9GameState21GetPartyMemberByIndexEi(GameState*,int);
extern "C" void* Network_GetConnectionManager();
extern "C" bool Network_IsParentOrOffline(unsigned*);
extern "C" void GameObject_GetAuthorityPosition(Vector*,unsigned char*);
extern "C" void Vector3fix_Subtract(const Vector*,const Vector*,Vector*);
extern "C" void Vector3fix_Normalize(const Vector*,Vector*);
extern "C" int fix32_Atan2(int,int);
extern "C" void SetObjectAngleAndClearFlagC48000(Object3D*,int);
extern "C" void _Z24Vector3fixMultiplyScalarPK8Vector3iiPS_(const Vector*,int,Vector*);
extern "C" void Vector3fix_Add(const Vector*,const Vector*,Vector*);
extern "C" void GameObject_ChangeMotionStateAndRefreshAnimation(Owner*,unsigned);
extern "C" void* _ZN9GameState14GetProtagonistEv(void*);
extern "C" unsigned short _ZNK8Object3D10GetField06Ev(void*);
extern "C" void _ZN8Object3D11DisableFlagEi(void*,int);
extern "C" int Network_IsSessionActive(void*);
extern "C" void Network_QueueObjectDirectionAndPosition(unsigned,int,int,Vector,int,int,unsigned short);
// Original: arm9/main @ 0x02077A34; symbol: func_02077a34; size: 0x1AC.
extern "C" int GameObject_SetPartyMemberApproachTarget(unsigned char* self) {
 void* game=_ZN9GameState11GetInstanceEv();
 int angle;
 void* context;
 Object3D* member=_ZN9GameState21GetPartyMemberByIndexEi((GameState*)game,*(unsigned short*)(self+0x166));
 if(!member) return 0;
 self[0x17d]|=0x40;
 angle=0;
 context=Network_GetConnectionManager();
 if(Network_IsParentOrOffline((unsigned*)context)) {
  Vector position,delta,memberPosition;
  GameObject_GetAuthorityPosition(&memberPosition,(unsigned char*)member);
  struct CopyVector {int words[3];};
  *(CopyVector*)&position=*(CopyVector*)&memberPosition;
  Vector3fix_Subtract(&position,(Vector*)(self+0x44),&delta);
  Vector3fix_Normalize(&delta,&delta);
  angle=fix32_Atan2(delta.x,delta.z);
  SetObjectAngleAndClearFlagC48000((Object3D*)self,angle);
  _Z24Vector3fixMultiplyScalarPK8Vector3iiPS_(&delta,0xa000,&delta);
  Vector3fix_Add((Vector*)(self+0x44),&delta,(Vector*)(self+0x158));
 }
 *(short*)(self+0xb4)=0x1c2;
 *(short*)(self+0xb2)=0x1c2;
 GameObject_ChangeMotionStateAndRefreshAnimation((Owner*)self,1);
 unsigned short protagonistId=_ZNK8Object3D10GetField06Ev(_ZN9GameState14GetProtagonistEv(game));
 if(protagonistId==_ZNK8Object3D10GetField06Ev(self)) _ZN8Object3D11DisableFlagEi(self,0x80);
 self[0x17a]=0;
 if(Network_IsSessionActive(context) && Network_IsParentOrOffline((unsigned*)context)) {
  unsigned field=_ZNK8Object3D10GetField06Ev(self);
  short key=*(short*)(self+2);
  Vector* target=(Vector*)(self+0x158);
  int remainder=(*(short*)(self+4)-0x70)%12;
  if(remainder>=0 && remainder<12) Network_QueueObjectDirectionAndPosition(field,remainder,key,*target,angle,5,*(unsigned short*)(self+0x166));
 }
 return 1;
}

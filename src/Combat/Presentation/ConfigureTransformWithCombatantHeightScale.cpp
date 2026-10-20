#include <globaldefs.h>
ARM
extern "C" unsigned _fadd(unsigned,unsigned);
extern "C" unsigned _fdiv(unsigned,unsigned);
extern "C" unsigned _fsub(unsigned,unsigned);
extern "C" unsigned _fmul(unsigned,unsigned);
extern "C" unsigned _fflt(int);
extern "C" int _ffix(unsigned);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" char* _ZN9GameState19GetCombatantByIndexEi(void*,int);
extern "C" char* GameState_ReadUnknownB0(void*);
extern "C" void Camera_StartOrbitMovement(void*,const void*,int,int,int);
extern "C" int _Z24fix32SignedAngleDistanceii(int,int);
extern "C" int _ZNK8Object3D9GetHeightEv(void*);
extern "C" char* Combat_GetIndexedActionTarget(void*,int);
extern "C" unsigned char* BattleScene_GetActiveInstance();
extern "C" unsigned char BattleScene_GetGroupedResultPhase(unsigned char*);
struct Vec { int x,y,z; };
union FloatBits { float f; unsigned u; };
// Original: arm9/ov025 @ 0x021E6FF8; symbol: func_ov025_021e6ff8; size: 0x21C.
extern "C" int ConfigureTransformWithCombatantHeightScale(unsigned char* param,void* source) {
 void* state=_ZN9GameState11GetInstanceEv();
 char* object=GameState_ReadUnknownB0(state);
 unsigned char* control=BattleScene_GetActiveInstance();
 if(control) {control[0x6fd5]=1;if(BattleScene_GetGroupedResultPhase(control)) return 1;}
 Vec v=*(Vec*)(object+0x70);
 if(param[8]&1) {
 if(_Z24fix32SignedAngleDistanceii(v.x,*(int*)(param+0xc))>0) {
 int angle=*(int*)(param+0xc);
 while(angle<v.x) angle+=0x6488;
 v.x=angle;
 } else {
 int angle=*(int*)(param+0xc);
 while(v.x<angle) angle-=0x6488;
 v.x=angle;
 }
 }
 if(param[8]&2) v.y=*(int*)(param+0x10);
 if(param[8]&4) v.z=*(int*)(param+0x14);
 if(param[0x24]==2) {
 int height=1;
 char* record=Combat_GetIndexedActionTarget(source,0);
 if(record) {
 char* combatant=_ZN9GameState19GetCombatantByIndexEi(state,*(short*)(record+0xe));
 if(combatant) height=_ZNK8Object3D9GetHeightEv(combatant);
 }
 float scale=1.0f;
 if(height>=0x1800) {
 scale=1.0f+0.8f*((float)height/4096.0f-1.5f)/2.5f;
 if(scale>=1.8f) scale=1.8f;
 }
 float y=(float)v.y/4096.0f;
 float z=(float)v.z/4096.0f;
 y*=scale;z*=scale;
 v.y=(int)(4096.0f*y);
 v.z=(int)(4096.0f*z);
 }
 Camera_StartOrbitMovement(object,&v,*(int*)(param+0x18),*(int*)(param+0x1c),*(int*)(param+0x20));
 return 1;
}

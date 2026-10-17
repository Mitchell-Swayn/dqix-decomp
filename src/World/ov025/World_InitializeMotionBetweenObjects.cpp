#include <globaldefs.h>
ARM
struct Vec { int x,y,z; };
extern "C" {
void* _ZN9GameState11GetInstanceEv();
char* _ZN9GameState20GetGameObjectByIndexEi(void*,int);
int _ZNK8Object3D9GetRadiusEv(void*);
int Vector3fix_Distance(const Vec*,const Vec*);
void Vector3fix_Subtract(const Vec*,const Vec*,Vec*);
void Vector3fix_Normalize(const Vec*,Vec*);
void _Z24Vector3fixMultiplyScalarPK8Vector3iiPS_(const Vec*,int,Vec*);
void Vector3fix_Add(const Vec*,const Vec*,Vec*);
int fix32_Divide(int,int);
unsigned _fflt(int);
unsigned _fdiv(unsigned,unsigned);
int _ffix(unsigned);
int fix32_Atan2(int,int);
int _Z22fix32ReduceAngle0To2Pii(int);
void Object_SetUnsignedIntAtOffset50AndSetUnsignedIntAtOffset54AndSetUnsignedIntAtOffset58(void*,unsigned,unsigned,unsigned);
void* memset(void*,int,unsigned);
}
// Original: arm9/ov025 @ 0x021DF5E4; symbol: func_ov025_021df5e4; size: 0x1B0.
extern "C" void World_InitializeMotionBetweenObjects(char* self,int first,int second) {
 void* state=_ZN9GameState11GetInstanceEv();
 self[0x174]=first;
 self[0x175]=second;
 char* a=_ZN9GameState20GetGameObjectByIndexEi(state,*(unsigned char*)(self+0x174));
 char* b=_ZN9GameState20GetGameObjectByIndexEi(state,*(unsigned char*)(self+0x175));
 if(a && b) {
  Vec from=*(Vec*)(a+0x44);
  from.y=0;
  Vec to=*(Vec*)(b+0x44);
  to.y=0;
  int speed=0xc00;
  int distance=Vector3fix_Distance(&from,&to);
  int radius=_ZNK8Object3D9GetRadiusEv(a);
  if(distance<radius)return;
  Vector3fix_Subtract(&to,&from,(Vec*)(self+0x158));
  Vector3fix_Normalize((Vec*)(self+0x158),(Vec*)(self+0x158));
  Vec offset;
  _Z24Vector3fixMultiplyScalarPK8Vector3iiPS_((Vec*)(self+0x158),radius>>1,&offset);
  Vector3fix_Add(&from,&offset,(Vec*)(self+0x164));
  distance=Vector3fix_Distance((Vec*)(self+0x164),&to);
  self[0x18a]=_ffix(_fdiv(_fflt(fix32_Divide(distance,speed)),0x45800000))+1;
  if(*(unsigned char*)(self+0x18a)>10) {
   speed=fix32_Divide(distance,0xa000);
   self[0x18a]=10;
  }
  int angle=_Z22fix32ReduceAngle0To2Pii(fix32_Atan2(*(int*)(self+0x158),*(int*)(self+0x160)));
  Object_SetUnsignedIntAtOffset50AndSetUnsignedIntAtOffset54AndSetUnsignedIntAtOffset58(self,0,angle,0);
  Object_SetUnsignedIntAtOffset50AndSetUnsignedIntAtOffset54AndSetUnsignedIntAtOffset58(self+0xac,0,angle,0);
  _Z24Vector3fixMultiplyScalarPK8Vector3iiPS_((Vec*)(self+0x158),speed,(Vec*)(self+0x158));
  self[0x18b]=0;
  memset(self+0x176,0,20);
  if(*(unsigned char*)(self+0x18a))*(int*)(self+0x170)=0;
 }
}

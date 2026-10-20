#include <globaldefs.h>
#include <System/Matrix.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" unsigned _ZNK9GameState12GetTickCountEv(void*);
extern "C" void* memcpy(void*,const void*,unsigned);
extern "C" void _Z24Vector3fixMultiplyScalarPK8Vector3iiPS_(const Vector3fix*,int,Vector3fix*);
// Original: arm9/ov001 @ 0x02157C3C; symbol: func_ov001_02157c3c; size: 0x1DC.
extern "C" int Graphics_AdvanceTwoVectorLinearTransition(char* self,char* object){
 void* state=_ZN9GameState11GetInstanceEv();
 int ticks=_ZNK9GameState12GetTickCountEv(state)<<12;
 int duration=*(int*)(self+0x1c);
 if(duration==0){
  memcpy(object+0x4c,self+4,12);memcpy(object+0x58,self+0x10,12);*(int*)(object+0x38)=0;
  return 0;
 }
 if(*(int*)(object+0x38)<=0){
  Vector3fix delta;
  int divisor=duration<<13;
  Vector3fix_Subtract((Vector3fix*)(self+4),(Vector3fix*)(object+0x4c),&delta);
  *(int*)(object+0xb4)=fix32_Divide(delta.x,divisor);
  *(int*)(object+0xb8)=fix32_Divide(delta.y,divisor);
  *(int*)(object+0xbc)=fix32_Divide(delta.z,divisor);
  Vector3fix_Subtract((Vector3fix*)(self+0x10),(Vector3fix*)(object+0x58),&delta);
  *(int*)(object+0xc0)=fix32_Divide(delta.x,divisor);
  *(int*)(object+0xc4)=fix32_Divide(delta.y,divisor);
  *(int*)(object+0xc8)=fix32_Divide(delta.z,divisor);
  memcpy(object+0x110,object+0xb4,12);memcpy(object+0x11c,object+0xc0,12);
  *(int*)(object+0xa24)=*(int*)(self+0x20);
 }
 Vector3fix a=*(Vector3fix*)(object+0xb4),b=*(Vector3fix*)(object+0xc0);
 _Z24Vector3fixMultiplyScalarPK8Vector3iiPS_(&a,ticks,&a);
 _Z24Vector3fixMultiplyScalarPK8Vector3iiPS_(&b,ticks,&b);
 Vector3fix_Add((Vector3fix*)(object+0x4c),&a,(Vector3fix*)(object+0x4c));
 Vector3fix_Add((Vector3fix*)(object+0x58),&b,(Vector3fix*)(object+0x58));
 *(int*)(object+0xa24)=*(int*)(self+0x20);
 *(int*)(object+0x38)+=_ZNK9GameState12GetTickCountEv(state);
 if(*(int*)(object+0x38)>=(*(int*)(self+0x1c)<<1)){
  if(*(int*)(self+0x24)){memcpy(object+0x4c,self+4,12);memcpy(object+0x58,self+0x10,12);}
  *(int*)(object+0x38)=0;return 0;
 }
 return 1;
}

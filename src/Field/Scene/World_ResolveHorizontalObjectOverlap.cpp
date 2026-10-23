#include <globaldefs.h>
#include <System/Matrix.h>
ARM
extern "C" Vector3fix Actor_GetRepresentationPositionOrZero(char*);
extern "C" int _Z8fix32absi(int);
extern "C" int _ZNK8Object3D9GetRadiusEv(void*);
extern "C" char* Actor_GetMotionDescriptor(void*);
extern "C" int GameObject_GetCollisionDisplacementBypassMask(void*);
extern "C" void _Z24Vector3fixMultiplyScalarPK8Vector3iiPS_(const Vector3fix*,int,Vector3fix*);
extern "C" void Actor_SetRepresentationPosition(unsigned char*,unsigned,unsigned,unsigned);
extern "C" void _ZN8Vector3iaSERKS_(void*,const void*);
struct Triple{int x,y,z;};
// Original: arm9/ov017 @ 0x0218DD18; symbol: func_ov017_0218dd18; size: 0x238.
extern "C" int World_ResolveHorizontalObjectOverlap(char* object,char* other,int moveOther){
 Vector3fix position=*(Vector3fix*)(object+0x44);
 Vector3fix otherPosition=Actor_GetRepresentationPositionOrZero(other);
 Vector3fix deltaA,deltaB;
 if(_Z8fix32absi(otherPosition.y-position.y)>=8192)return 0;
 int ownRadius=(int)(0.5f*(float)_ZNK8Object3D9GetRadiusEv(object));
 int otherRadius=2048;
 if(*(void**)(other+24))otherRadius=_ZNK8Object3D9GetRadiusEv(*(void**)(other+24))/2;
 char* definition=Actor_GetMotionDescriptor(other);
 Vector3fix* offset=*(Vector3fix**)(definition+0x5c);
 if(offset){otherRadius=*(int*)((char*)offset+12);Vector3fix_Add(&otherPosition,offset,&otherPosition);}
 int radius=ownRadius+otherRadius;
 if(!radius)return 0;
 if(radius<_Z8fix32absi(position.x-otherPosition.x))return 0;
 if(radius<_Z8fix32absi(position.z-otherPosition.z))return 0;
 otherPosition.y=position.y;
 int distance=Vector3fix_Distance(&position,&otherPosition);
 if(radius<distance)return 0;
 if(*(unsigned*)other&0x40000)return 0;
 if(!GameObject_GetCollisionDisplacementBypassMask(object)){
  if(moveOther){
   radius-=(int)(0.2f*(0.5f*(float)_ZNK8Object3D9GetRadiusEv(object)));
   if(radius<distance)return 0;
   Vector3fix_Subtract(&otherPosition,&position,&deltaA);
   int scale=fix32_Divide(radius,distance);
   _Z24Vector3fixMultiplyScalarPK8Vector3iiPS_(&deltaA,scale,&deltaA);
   Vector3fix_Add(&position,&deltaA,&otherPosition);
   Actor_SetRepresentationPosition((unsigned char*)other,otherPosition.x,otherPosition.y,otherPosition.z);
  }else{
   Vector3fix_Subtract(&position,&otherPosition,&deltaB);
   if(distance<ownRadius)distance=ownRadius;
   int scale=fix32_Divide(radius,distance);
   _Z24Vector3fixMultiplyScalarPK8Vector3iiPS_(&deltaB,scale,&deltaB);
   Vector3fix_Add(&otherPosition,&deltaB,&position);
   _ZN8Vector3iaSERKS_(object+0x44,&position);
  }
 }
 return 1;
}

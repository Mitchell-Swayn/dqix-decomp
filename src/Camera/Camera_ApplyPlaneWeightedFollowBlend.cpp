#include <globaldefs.h>
#include <Graphics/Vector.h>
struct Triple {int x,y,z;};
ARM
extern "C" int Vector_ComputeSignedPlaneDistance(const Vector3fix*,const Vector4fix*);
extern "C" void Camera_SetTargetPreservingOrbit(void*,const Vector3fix*);
extern "C" void Camera_SetOrbitParameters(void*,const Triple*);
extern "C" void* __clear(void*,unsigned);
inline int Multiply(int a,int b){return (int)(((long long)a*b+2048)>>12);}
inline int Interpolate(int a,int b,int t){int u;int v=Multiply(b,t);u=Multiply(a,(int)(4096u-t));return u+v;}
// Original: arm9/main @ 0x020A299C; symbol: Camera_ApplyPlaneWeightedFollowBlend; size: 0x19C.
// Interpolates angles and position across a signed plane-distance transition.
extern "C" int Camera_ApplyPlaneWeightedFollowBlend(char* self,const Vector3fix* original,char* object){
 if(!(*(unsigned char*)(self+0x245)&4))if(!(*(unsigned char*)(self+0x245)&8))return 0;
 Vector3fix position=*(Vector3fix*)(object+0x44);
 Triple angles;__clear(&angles,12);
 int distance=Vector_ComputeSignedPlaneDistance(&position,(const Vector4fix*)(self+0x298));
 if(distance>0){
 int weight=fix32_Divide(fix32abs(distance),*(int*)(self+0x2a8));
 if(weight>4096)weight=4096;
 if(*(unsigned char*)(self+0x245)&4){
  int delta=fix32SignedAngleDistance(*(int*)(self+0x220),*(int*)(self+0x2ac));
  int offset=Multiply(delta,weight);
  angles.x=fix32ReduceAngle0To2Pi(*(int*)(self+0x220)+offset);
 }else if(*(unsigned char*)(self+0x245)&8)angles.x=*(int*)(self+0x220);
 angles.y=Interpolate(*(int*)(self+0x224),*(int*)(self+0x2b0),weight);
 angles.z=Interpolate(*(int*)(self+0x228),*(int*)(self+0x2b4),weight);
 Vector3fix scaledOriginal,scaledTarget,target,result;
 Vector3fix_Add((Vector3fix*)(self+0x10),(Vector3fix*)(self+0x2b8),&target);
 Vector3fixMultiplyScalar(original,4096-weight,&scaledOriginal);
 Vector3fixMultiplyScalar(&target,weight,&scaledTarget);
 Vector3fix_Add(&scaledOriginal,&scaledTarget,&result);
 Camera_SetTargetPreservingOrbit(self,&result);
 Camera_SetOrbitParameters(self,&angles);
 return 1;
 }return 0;
}

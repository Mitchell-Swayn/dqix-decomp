#pragma opt_propagation off
#include <Graphics/Vector.h>
struct ManualCamera { int unknown0; Vector3i eye,target; unsigned char unknown1c[0x1fc]; int mode; };
extern "C" {
// Original data: arm9/main @ 0x2114e30; symbol: data_02114e30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned short KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage[];
int Input_TestKeyMask(unsigned short*,unsigned short);
void Camera_AddWrappedOrbitHeading(void*,int);
int Camera_GetOrbitDistance(void*);
int Camera_GetOrbitHeight(void*);
void Camera_SetClampedOrbitHeight(void*,int);
void Camera_AdjustOrbitDistancePreservingPitch(void*,int);
void Vector_SubtractStoredOriginFromEndpoint(void*,Vector3i*);
void Camera_MeasureOrbitFromEyeAndTarget(void*);
void Camera_SetTargetPreservingOrbit(void*,const Vector3i*);
}
// Manual camera controls: mode selects orbit, translation, or modified distance/height changes.
// Eye and target offsets follow the existing endpoint/heading helpers; button masks follow Input_TestKeyMask.
// Original: arm9/main @ 0x020A2D14; symbol: func_020a2d14; size: 0x854.
extern "C" void Camera_ApplyManualInput(ManualCamera* self) {
 if(!self->mode)return;
 Vector3i position=self->target;
 int a=Input_TestKeyMask(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,1);
 int b=Input_TestKeyMask(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,2);
 int x=Input_TestKeyMask(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x400);
 int y=Input_TestKeyMask(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x800);
 int r=Input_TestKeyMask(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x200);
 int l=Input_TestKeyMask(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x100);
 int up=Input_TestKeyMask(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x40);
 int down=Input_TestKeyMask(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x80);
 int left=Input_TestKeyMask(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x20);
 int right=Input_TestKeyMask(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x10);
 int slow=Input_TestKeyMask(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,8);
 float speed=1.0f;
 if(slow)speed=0.1f;
 if(self->mode==2 && !x && !y)return;
 if((self->mode==1 && !l && self->mode==1 && !r) || (self->mode==2 && !y)) {
  if(left)Camera_AddWrappedOrbitHeading(self,-(int)(0.05f*speed*4096.0f));
  if(right)Camera_AddWrappedOrbitHeading(self,(int)(0.05f*speed*4096.0f));
  if(up) {
   int length=Camera_GetOrbitDistance(self);
   int height=Camera_GetOrbitHeight(self);
   int heightSquared=(int)(((long long)height*height+0x800)>>12);
   int lengthSquared=(int)(((long long)length*length+0x800)>>12);
   int horizontal=fix32_Sqrt(lengthSquared-heightSquared);
   Vector3i offset={0,0,0};offset.y=height;offset.x=horizontal;
   Matrix4x3 rotation=RotationMatrixZ((int)(178.72223f*speed));
   Mat4x3_ApplyToVector(&offset,&rotation,&offset);
   Camera_SetClampedOrbitHeight(self,offset.y);
  }
  if(down) {
   int length=Camera_GetOrbitDistance(self);
   int height=Camera_GetOrbitHeight(self);
   int heightSquared=(int)(((long long)height*height+0x800)>>12);
   int lengthSquared=(int)(((long long)length*length+0x800)>>12);
   int horizontal=fix32_Sqrt(lengthSquared-heightSquared);
   Vector3i offset={0,0,0};offset.y=height;offset.x=horizontal;
   Matrix4x3 rotation=RotationMatrixZ(fix32ReduceAngle0To2Pi((int)(-178.72223f*speed)));
   Mat4x3_ApplyToVector(&offset,&rotation,&offset);
   Camera_SetClampedOrbitHeight(self,offset.y);
  }
 }
 float distance=(float)Camera_GetOrbitDistance(self)/10.0f/4096.0f;
 int moved=0;
 if((self->mode==1 && l) || (self->mode==2 && y)) {
  Vector3i direction;
  Vector_SubtractStoredOriginFromEndpoint(self,&direction);
  direction.y=0;
  Vector3fix_Normalize(&direction,&direction);
  Vector3fixMultiplyScalar(&direction,(int)(0.2f*speed*distance*4096.0f),&direction);
  int angle=0;
  if(up && left){angle=0xc91;moved=1;}
  else if(up && right){angle=0x57f7;moved=1;}
  else if(down && left){angle=0x25b3;moved=1;}
  else if(down && right){angle=0x3ed5;moved=1;}
  else if(up){moved=1;}
  else if(down){angle=0x3244;moved=1;}
  else if(left){angle=0x1922;moved=1;}
  else if(right){angle=0x4b66;moved=1;}
  if(moved){
   Matrix4x3 rotation=RotationMatrixY(angle);
   Mat4x3_ApplyToVector(&direction,&rotation,&direction);
   Vector3fix_Add(&position,&direction,&position);
  }
 }
 if(self->mode==1 && r) {
  Vector3i direction;
  Vector3i eye=position;
  Vector_SubtractStoredOriginFromEndpoint(self,&direction);
  direction.y=0;
  Vector3fix_Normalize(&direction,&direction);
  Vector3fixMultiplyScalar(&direction,(int)(0.2f*speed*distance*4096.0f),&direction);
  int angle=0;
  if(up && left){angle=0xc91;moved=1;}
  else if(up && right){angle=0x57f7;moved=1;}
  else if(down && left){angle=0x25b3;moved=1;}
  else if(down && right){angle=0x3ed5;moved=1;}
  else if(up){moved=1;}
  else if(down){angle=0x3244;moved=1;}
  else if(left){angle=0x1922;moved=1;}
  else if(right){angle=0x4b66;moved=1;}
  if(moved){
   Matrix4x3 rotation=RotationMatrixY(angle);
   Mat4x3_ApplyToVector(&direction,&rotation,&direction);
   Vector3fix_Add(&eye,&direction,&eye);
   self->target=eye;
   Camera_MeasureOrbitFromEyeAndTarget(self);
   self->eye=self->eye;
   return;
  }
  int changed=0;
  int delta=(int)(0.2f*speed*distance*4096.0f);
  if(x){eye.y+=delta;changed=1;}
  if(y){eye.y-=delta;changed=1;}
  if(changed){self->target=eye;Camera_MeasureOrbitFromEyeAndTarget(self);self->eye=self->eye;return;}
 }
 if(self->mode==1) {
  int delta=(int)(0.3f*speed*distance*4096.0f);
  if(a)Camera_AdjustOrbitDistancePreservingPitch(self,delta);
  if(b)Camera_AdjustOrbitDistancePreservingPitch(self,-delta);
 }
 if(self->mode==1) {
  int delta=(int)(0.2f*speed*distance*4096.0f);
  if(x)position.y+=delta;
  if(y)position.y-=delta;
 }
 if(self->mode==2 && !moved) {
  int vertical=(int)(0.2f*speed*distance*4096.0f);
  int length=(int)(0.3f*speed*distance*4096.0f);
  if(y && l)position.y+=vertical;
  else if(y && r)position.y-=vertical;
  else if(l)Camera_AdjustOrbitDistancePreservingPitch(self,length);
  else if(r)Camera_AdjustOrbitDistancePreservingPitch(self,-length);
 }
 Camera_SetTargetPreservingOrbit(self,&position);
}

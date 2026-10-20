#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x210a010; symbol: data_0210a010.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 612 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage[];
extern "C" void Camera_InitializeTargetFollowingState(char*);
extern "C" void Camera_SetTargetCoordinates(char*,int,int,int);
extern "C" void ComputeRotatedEndpointFromAngleHeightAndLength(char*,int,int,int);
extern "C" void Camera_UpdateRenderView(void*);
extern "C" void Camera_DisableTargetFollowing(char*);
extern "C" void Graphics_InitializeCameraIfPresent(char*);
extern "C" void _ZN8Object3D4DrawEb(void*,bool);
struct Bits{unsigned char low:1;unsigned char enabled:1;unsigned char high:6;};
// Original: arm9/ov006 @ 0x02154E58; symbol: func_ov006_02154e58; size: 0x18C.
extern "C" void Graphics_DrawFourObjectsWithConditionalCameraSetup(char* self){
 unsigned flags=*(unsigned short*)(self+0xae2);
 if(!(flags&0x1000))return;
 if((flags&0x48) && ((flags&8)||(*(unsigned short*)(self+0x1258)&4))){
  if(*(signed char*)(self+0x1261)!=2)return;
  if(!((Bits*)(self+0x127f))->enabled)return;
 }
 if(*(signed char*)(self+0x1261)==2 && ((Bits*)(self+0x127f))->enabled && (*(unsigned short*)(self+0x1258)&4)){
  *(unsigned*)(RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage+0xa0)=0x46501313;
  volatile unsigned short* bg=(volatile unsigned short*)0x04000008;
  bg[0]&=~3;bg[1]=(bg[1]&~3)|1;bg[2]=(bg[2]&~3)|2;
  if(self+0x5cc){
   Camera_InitializeTargetFollowingState(self+0x5cc);
   Camera_SetTargetCoordinates(self+0x5cc,0,-7823,0);
   ComputeRotatedEndpointFromAngleHeightAndLength(self+0x5cc,0,0x2bae,0x9199);
   Camera_UpdateRenderView(self+0x5cc);
   Camera_DisableTargetFollowing(self+0x5cc);
  }
  *(unsigned char*)(self+0x12bd)=0;
 }else Graphics_InitializeCameraIfPresent(self+0x5cc);
 _ZN8Object3D4DrawEb(self+0x238,true);
 _ZN8Object3D4DrawEb(self+0x2e4,true);
 _ZN8Object3D4DrawEb(self+0x390,true);
 _ZN8Object3D4DrawEb(self+0x43c,true);
}

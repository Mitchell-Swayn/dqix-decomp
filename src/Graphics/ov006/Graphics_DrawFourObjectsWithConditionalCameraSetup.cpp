#include <globaldefs.h>
ARM
extern "C" char data_0210a010[];
extern "C" void InitializeStoredVectorsAndInterpolationDefaults(char*);
extern "C" void WriteThreeWordsAtOffsets10Through18(char*,int,int,int);
extern "C" void ComputeRotatedEndpointFromAngleHeightAndLength(char*,int,int,int);
extern "C" void Camera_UpdateRenderView(void*);
extern "C" void ClearWordFieldAtOffset238(char*);
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
  *(unsigned*)(data_0210a010+0xa0)=0x46501313;
  volatile unsigned short* bg=(volatile unsigned short*)0x04000008;
  bg[0]&=~3;bg[1]=(bg[1]&~3)|1;bg[2]=(bg[2]&~3)|2;
  if(self+0x5cc){
   InitializeStoredVectorsAndInterpolationDefaults(self+0x5cc);
   WriteThreeWordsAtOffsets10Through18(self+0x5cc,0,-7823,0);
   ComputeRotatedEndpointFromAngleHeightAndLength(self+0x5cc,0,0x2bae,0x9199);
   Camera_UpdateRenderView(self+0x5cc);
   ClearWordFieldAtOffset238(self+0x5cc);
  }
  *(unsigned char*)(self+0x12bd)=0;
 }else Graphics_InitializeCameraIfPresent(self+0x5cc);
 _ZN8Object3D4DrawEb(self+0x238,true);
 _ZN8Object3D4DrawEb(self+0x2e4,true);
 _ZN8Object3D4DrawEb(self+0x390,true);
 _ZN8Object3D4DrawEb(self+0x43c,true);
}

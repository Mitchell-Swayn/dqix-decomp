#include <globaldefs.h>
ARM
extern "C" void* memcpy(void*,const void*,unsigned);
extern "C" void* memset(void*,int,unsigned);
extern "C" int _ffix(unsigned);
extern "C" unsigned _fflt(int);
extern "C" unsigned _fsub(unsigned,unsigned);
extern "C" int Camera_GetOrbitHeading(void*);
extern "C" void GameState_CopyObjectValueAndUpdateTwoModeFlags(unsigned*,unsigned,unsigned);
extern "C" void Object_SelectNamedAnimationIfEntryPresent(unsigned char*,const char*);
extern "C" void Camera_EnableOrbitInput(void*);
extern "C" void Camera_DisableOrbitInput(void*);
// Original data: arm9/main @ 0x20efc18; symbol: data_020efc18.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ff.
// Observed span: 1 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" signed char MotionSelectAnimationFromAngleAndTickState_UnknownRoleInitializedBytes;
extern "C" char Motion_SelectAnimationFromAngleAndTickState_TextTalkDownR[],Motion_SelectAnimationFromAngleAndTickState_TextTalkDownL[],Motion_SelectAnimationFromAngleAndTickState_TextTalkLDown[],Motion_SelectAnimationFromAngleAndTickState_TextTalkRDown[],Motion_SelectAnimationFromAngleAndTickState_TextReturn[];
// Original: arm9/main @ 0x0203CA24; symbol: func_0203ca24; size: 0x1B4.
extern "C" void Motion_SelectAnimationFromAngleAndTickState(char* self,void* other) {
 Camera_DisableOrbitInput(other);
 int angle=Camera_GetOrbitHeading(other);
 int upper=_ffix(_fsub(0x46c91000,_fflt(0x648)));
 char name[20];
 memset(name,0,19);
 int mode=MotionSelectAnimationFromAngleAndTickState_UnknownRoleInitializedBytes;
 if((mode>-1 && mode==0)||angle<0x648||upper<=angle) {
  if(*(int*)(self+0x98)>*(int*)(self+4))memcpy(name,Motion_SelectAnimationFromAngleAndTickState_TextTalkDownR,11);
  else memcpy(name,Motion_SelectAnimationFromAngleAndTickState_TextTalkDownL,11);
  MotionSelectAnimationFromAngleAndTickState_UnknownRoleInitializedBytes=0;
 } else if((mode>-1 && mode==1)||angle<0x3244) {
  memcpy(name,Motion_SelectAnimationFromAngleAndTickState_TextTalkLDown,11);MotionSelectAnimationFromAngleAndTickState_UnknownRoleInitializedBytes=1;
 } else {
  memcpy(name,Motion_SelectAnimationFromAngleAndTickState_TextTalkRDown,11);MotionSelectAnimationFromAngleAndTickState_UnknownRoleInitializedBytes=2;
 }
 if(*(unsigned*)(self+0x5c)&0x20) {
  memcpy((void*)((unsigned)name+11),Motion_SelectAnimationFromAngleAndTickState_TextReturn,7);
  name[19]=0;
  --*(unsigned char*)(self+0x94);
  if(!*(unsigned char*)(self+0x94)) {
   GameState_CopyObjectValueAndUpdateTwoModeFlags((unsigned*)self,0,0);
   *(unsigned char*)(self+0x94)=15;
   Camera_EnableOrbitInput(other);
   MotionSelectAnimationFromAngleAndTickState_UnknownRoleInitializedBytes=-1;
  }
 }
 Object_SelectNamedAnimationIfEntryPresent((unsigned char*)self,name);
}

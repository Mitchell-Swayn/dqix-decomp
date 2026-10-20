#include <globaldefs.h>
#include <Resource/GameResources.h>
ARM
struct State;
extern "C" void _Z17SetMainBrightnessP13GameResourcesii(void*,int,int);
extern "C" unsigned TextContext_GetSharedInstance();
extern "C" void Graphics_ClearAndStageSharedBuffers(char*);
extern "C" void LinkedQueue_RemoveNodeAndResetStatus(int*,int);
extern "C" void* ColorAnimation_GetGlobalInstance();
extern "C" void ColorAnimation_StartTimedTransition(State*,unsigned);
extern "C" void Resource_CompletePendingStateAndClearFlags();
extern "C" void FieldEvent_ReleaseResourcesAndResumeFieldControl(void*);
// Original: arm9/ov001 @ 0x021564B0; symbol: func_ov001_021564b0; size: 0x84.
// Completes a ready graphics transition, unlinks its node, and resets brightness and flags.
extern "C" unsigned CompleteSceneGraphicsTransitionWhenReady(char *self) {
 GameResources *resources=GameResources_GetInstance();
 if(*((unsigned char*)resources+0x42e2)) {
  LinkedQueue_RemoveNodeAndResetStatus(*(int**)((char*)resources+0x36fc),*(int*)((char*)resources+0x3718));
  ColorAnimation_StartTimedTransition((State*)ColorAnimation_GetGlobalInstance(),15);
  _Z17SetMainBrightnessP13GameResourcesii(resources,0,15);
  char *graphics=(char*)TextContext_GetSharedInstance();
  Graphics_ClearAndStageSharedBuffers(graphics);
  *(unsigned char*)(graphics+0x19be)=0;
  ((void(*)(char*))Resource_CompletePendingStateAndClearFlags)(self);
  FieldEvent_ReleaseResourcesAndResumeFieldControl(self);
  self[1]=1;
 }
 return *(unsigned short*)(self+10);
}

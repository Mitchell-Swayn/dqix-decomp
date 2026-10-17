#include <globaldefs.h>
struct State { char header[0x118]; char member118[0xb4]; unsigned char done; unsigned char transitioning; };
extern "C" void* GameResources_GetInstance();
extern "C" void* Object_GetGlobalConnectionState();
extern "C" int TestContextModeAndZeroSlot();
extern "C" void _Z13SetBrightnessP13GameResourcesii(void*,int,int);
extern "C" int _Z28IsBrightnessTransitionActiveP13GameResources(void*);
extern "C" void func_ov011_021848a8(State*);
extern "C" void func_ov011_02184a84(State*);
extern "C" void func_ov011_02184ae4(State*);
extern "C" void func_ov023_021f68dc(void*,void*);
extern "C" void Graphics_ResetOverlayBackgroundState(State*);
// Original: arm9/ov011 @ 0x02184694; symbol: func_ov011_02184694; size: 0xAC.
extern "C" unsigned func_ov011_02184694(State* self) {
 void* resources=GameResources_GetInstance();
 Object_GetGlobalConnectionState();
 if(!self->transitioning) {
  if(TestContextModeAndZeroSlot()) {
   self->transitioning=1;
   if(resources) _Z13SetBrightnessP13GameResourcesii(resources,-16,10);
  }
  func_ov011_021848a8(self);
  func_ov011_02184a84(self);
  func_ov011_02184ae4(self);
  func_ov023_021f68dc(self->member118,self);
 } else if(resources && !_Z28IsBrightnessTransitionActiveP13GameResources(resources)) {
  Graphics_ResetOverlayBackgroundState(self);
  self->done=1;
 }
 return self->done==0;
}

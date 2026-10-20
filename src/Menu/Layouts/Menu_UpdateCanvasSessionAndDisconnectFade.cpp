#include <globaldefs.h>
struct State { char header[0x118]; char member118[0xb4]; unsigned char done; unsigned char transitioning; };
extern "C" void* GameResources_GetInstance();
extern "C" void* Network_GetConnectionManager();
extern "C" int Field_IsHostDisconnectPending();
extern "C" void _Z13SetBrightnessP13GameResourcesii(void*,int,int);
extern "C" int _Z28IsBrightnessTransitionActiveP13GameResources(void*);
extern "C" void Menu_UpdateSb2ScriptExecution(State*);
extern "C" void Menu_UpdateActiveOrFallbackCallback(State*);
extern "C" void Menu_DispatchCompletedChoiceActions(State*);
extern "C" void MenuRecordList_RunUpdatePassesAndDispatchSelection(void*,void*);
extern "C" void Graphics_ResetOverlayBackgroundState(State*);
// Original: arm9/ov011 @ 0x02184694; symbol: func_ov011_02184694; size: 0xAC.
extern "C" unsigned Menu_UpdateCanvasSessionAndDisconnectFade(State* self) {
 void* resources=GameResources_GetInstance();
 Network_GetConnectionManager();
 if(!self->transitioning) {
  if(Field_IsHostDisconnectPending()) {
   self->transitioning=1;
   if(resources) _Z13SetBrightnessP13GameResourcesii(resources,-16,10);
  }
  Menu_UpdateSb2ScriptExecution(self);
  Menu_UpdateActiveOrFallbackCallback(self);
  Menu_DispatchCompletedChoiceActions(self);
  MenuRecordList_RunUpdatePassesAndDispatchSelection(self->member118,self);
 } else if(resources && !_Z28IsBrightnessTransitionActiveP13GameResources(resources)) {
  Graphics_ResetOverlayBackgroundState(self);
  self->done=1;
 }
 return self->done==0;
}

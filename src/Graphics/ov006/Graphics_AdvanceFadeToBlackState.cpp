#include <globaldefs.h>
ARM
struct GameState; struct GameResources;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" GameResources* GameState_ReadPResources(GameState*);
extern "C" void _Z13SetBrightnessP13GameResourcesii(void*,int,int);
extern "C" int _Z28IsBrightnessTransitionActiveP13GameResources(void*);
extern "C" void DispatchObjectStateOneOrTwoUnlessFlag4(int,unsigned);
extern "C" void SetLinkedFlagStateAndResetOwner(void**);
extern "C" unsigned char data_02109bf4[];
// Original: arm9/ov006 @ 0x0215F2B4; symbol: func_ov006_0215f2b4; size: 0x94.
extern "C" void Graphics_AdvanceFadeToBlackState(unsigned char* self) {
 GameResources* resources=GameState_ReadPResources((GameState*)_ZN9GameState11GetInstanceEv());
 if(self[0x390]==0) {
  if(*(void***)(self+0x18)) SetLinkedFlagStateAndResetOwner(*(void***)(self+0x18));
  _Z13SetBrightnessP13GameResourcesii(resources,-16,16);
  if(!(*(unsigned short*)(self+0x394)&2)) DispatchObjectStateOneOrTwoUnlessFlag4((int)data_02109bf4,15);
  self[0x390]++;
 } else if(self[0x390]==1) {
  if(!_Z28IsBrightnessTransitionActiveP13GameResources(resources)) {
   self[0x38f]=13;
   self[0x390]=0;
  }
 }
}

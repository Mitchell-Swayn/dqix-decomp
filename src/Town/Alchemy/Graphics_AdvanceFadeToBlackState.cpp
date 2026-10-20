#include <globaldefs.h>
ARM
struct GameState; struct GameResources;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" GameResources* GameState_ReadPResources(GameState*);
extern "C" void _Z13SetBrightnessP13GameResourcesii(void*,int,int);
extern "C" int _Z28IsBrightnessTransitionActiveP13GameResources(void*);
extern "C" void Bgm_StopActiveSequenceUnlessBlocked(int,unsigned);
extern "C" void Window_HideAndResetOptionSelection(void**);
// Original data: arm9/main @ 0x2109bf4; symbol: data_02109bf4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage_Variant2[];
// Original: arm9/ov006 @ 0x0215F2B4; symbol: func_ov006_0215f2b4; size: 0x94.
extern "C" void Graphics_AdvanceFadeToBlackState(unsigned char* self) {
 GameResources* resources=GameState_ReadPResources((GameState*)_ZN9GameState11GetInstanceEv());
 if(self[0x390]==0) {
  if(*(void***)(self+0x18)) Window_HideAndResetOptionSelection(*(void***)(self+0x18));
  _Z13SetBrightnessP13GameResourcesii(resources,-16,16);
  if(!(*(unsigned short*)(self+0x394)&2)) Bgm_StopActiveSequenceUnlessBlocked((int)Main_UnknownRoleZeroInitializedStorage_Variant2,15);
  self[0x390]++;
 } else if(self[0x390]==1) {
  if(!_Z28IsBrightnessTransitionActiveP13GameResources(resources)) {
   self[0x38f]=13;
   self[0x390]=0;
  }
 }
}

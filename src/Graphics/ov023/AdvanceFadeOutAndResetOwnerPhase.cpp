#include <globaldefs.h>
ARM
extern "C" {void* _ZN9GameState11GetInstanceEv();void* GameState_ReadPResources(void*);void GameState_SetUnknown3b0(void*,void*);void _Z13SetBrightnessP13GameResourcesii(void*,int,int);int _Z28IsBrightnessTransitionActiveP13GameResources(void*);bool TestNonnegativeIdentifierWithByteOverride(char*);extern char data_02109bf4[];}
// Original: arm9/ov023 @ 0x021E3F34; symbol: func_ov023_021e3f34; size: 0x8C.
extern "C" void AdvanceFadeOutAndResetOwnerPhase(unsigned char* p){
void* game=_ZN9GameState11GetInstanceEv();void* resources=GameState_ReadPResources(game);
if(p[0x4e4]==0){_Z13SetBrightnessP13GameResourcesii(resources,-16,15);p[0x4e4]++;}
if(_Z28IsBrightnessTransitionActiveP13GameResources(resources))return;
if(TestNonnegativeIdentifierWithByteOverride(data_02109bf4))return;
GameState_SetUnknown3b0(game,*(void**)(p+0x138));
p[0x4e4]=0;p[0x4e7]=*(signed char*)(p+0x4e6);(*(signed char*)(p+0x4e6))=-1;
}

#include <globaldefs.h>
ARM
struct GameState;struct GameResources;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" GameResources* GameState_ReadPResources(GameState*);
extern "C" void _Z13SetBrightnessP13GameResourcesii(void*,int,int);
extern "C" int _Z28IsBrightnessTransitionActiveP13GameResources(void*);
// Original: arm9/ov006 @ 0x0215B0FC; symbol: func_ov006_0215b0fc; size: 0xA4.
extern "C" void Graphics_AdvanceBrightnessTransitionFromInput(unsigned char* p){
 GameResources* res=GameState_ReadPResources((GameState*)_ZN9GameState11GetInstanceEv());
 if(p[0x390]==0){
 if(*(unsigned short*)(*(unsigned char**)(p+0x10)+0xae2)&0x1008)p[0x390]++;
 }else if(p[0x390]==1){
 _Z13SetBrightnessP13GameResourcesii(res,0,8);
 p[0x390]++;
 }else if(p[0x390]==2){
 if(_Z28IsBrightnessTransitionActiveP13GameResources(res))return;
 p[0x38f]=4;p[0x390]=0;
 if(*(unsigned short*)(p+0x394)&2){p[0x397]=2;p[0x38f]=2;}
 }
}

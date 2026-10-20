#include <globaldefs.h>
ARM
extern "C" char* GameResources_GetInstance(...);
extern "C" char* _ZN16BackgroundLoader11GetInstanceEv(...);
extern "C" int _Z13SetBrightnessP13GameResourcesii(...);
extern "C" int _Z28IsBrightnessTransitionActiveP13GameResources(...);
extern "C" int _ZN16BackgroundLoader17GetNumQueuedTasksEv(...);
extern "C" int Field_ReloadZoneActorsEntranceAndMonsterModels(...);
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
// Original: arm9/ov017 @ 0x021C16CC; symbol: GameState_WaitForFadeAndQueuedTasksThenComplete; size: 0xc0.
// GameState WaitForFadeAndQueuedTasksThenComplete from listed field operations and calls.
extern "C" void GameState_WaitForFadeAndQueuedTasksThenComplete(char* self){char* resources=GameResources_GetInstance();void* loader=_ZN16BackgroundLoader11GetInstanceEv();if(*(signed char*)(self+8)==0){_Z13SetBrightnessP13GameResourcesii(resources,-16,15);++*(signed char*)(self+8);}else if(*(signed char*)(self+8)==1){if(_Z28IsBrightnessTransitionActiveP13GameResources(resources))return;if(_ZN16BackgroundLoader17GetNumQueuedTasksEv(loader)>0)return;Field_ReloadZoneActorsEntranceAndMonsterModels(resources);if(!B(P(resources,0x3734),2))_Z13SetBrightnessP13GameResourcesii(resources,0,15);if(B(self,9))_Z13SetBrightnessP13GameResourcesii(resources,-16,0);B(self,1)=1;}}

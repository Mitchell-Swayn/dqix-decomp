#include <globaldefs.h>
ARM
struct GameResources;struct State;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void _Z22UnlockAndSetBrightnessP13GameResourcesii(GameResources*,int,int);
extern "C" int Overlay_EnsureCurrentItemAndProcess();
extern "C" unsigned char Resource_GetFlag42E2(void*);
extern "C" GameResources* GameResources_GetInstance();
extern "C" int StaffRoll_DispatchPhase(State*,int);
// Original: arm9/ov001 @ 0x02155D54; symbol: func_ov001_02155d54; size: 0x7C.
extern "C" unsigned Graphics_UpdateOwnerFadeAndSelectNextState(unsigned char* p){
 _ZN9GameState11GetInstanceEv();
 GameResources* resources=GameResources_GetInstance();
 State* child=*(State**)(p+0x160);
 if(child)p[0x164]=StaffRoll_DispatchPhase(child,2)!=0;
 if(Resource_GetFlag42E2(p)){
 _Z22UnlockAndSetBrightnessP13GameResourcesii(resources,-16,30);
 *(int*)(p+0x15c)=1;
 return 14;
 }
 if(Overlay_EnsureCurrentItemAndProcess()!=1)return *(unsigned short*)(p+10);
 return 15;
}

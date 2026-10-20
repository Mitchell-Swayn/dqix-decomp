#include <globaldefs.h>
ARM
#include <std_library_functions.h>
#define I(p,o) (*(int*)((p)+(o)))
#define U(p,o) (*(unsigned*)((p)+(o)))
#define H(p,o) (*(unsigned short*)((p)+(o)))
#define S(p,o) (*(short*)((p)+(o)))
#define B(p,o) (*(unsigned char*)((p)+(o)))
#define C(p,o) (*(signed char*)((p)+(o)))
#define V(p,o) (*(char**)((p)+(o)))
extern "C" char* GameResources_GetInstance();extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();extern "C" unsigned DisplayContext_GetGlobalInstance();extern "C" void DisplayContext_IgnoreHook();extern "C" void DisplayContext_IgnoreCommand(unsigned,int,int,int,int);extern "C" int DisplayContext_ReportRequestComplete();extern "C" void _ZN16BackgroundLoader14RemoveAllLocksEv(void*);extern "C" void PowerManagement_HandleLidStateAndResourceTransitions();extern "C" void BattleMenu_InitializeController(void*,void*);extern "C" void Memory_InitializePoolsAndFortyTransformStates(char*,unsigned);extern "C" int BattleMenu_LoadControllerResources(void*);extern "C" void BattleScene_EnableFlags(unsigned char*,unsigned);
// Original: arm9/ov000 @ 0x02166978; symbol: Resource_WaitForDisplayTransitionAndInitializePools; size: 0x11C.
extern "C" void BattleScene_InitializeMenuAfterDisplayTransition(char* self){
char* resources=GameResources_GetInstance();void* loader=_ZN16BackgroundLoader11GetInstanceEv();C(self,0x5711)=0;for(;;){int state=C(self,0x5711);if(!state){unsigned display=DisplayContext_GetGlobalInstance();DisplayContext_IgnoreHook();DisplayContext_IgnoreCommand(display,101,500,0,0);C(self,0x5711)=1;}else if(state==1){if(((int(*)(unsigned))DisplayContext_ReportRequestComplete)(DisplayContext_GetGlobalInstance())){C(self,0x5711)=-1;break;}}_ZN16BackgroundLoader14RemoveAllLocksEv(loader);PowerManagement_HandleLidStateAndResourceTransitions();}BattleMenu_InitializeController(self+0x3760,resources+0x128);Memory_InitializePoolsAndFortyTransformStates(self+0x3760,(unsigned)(self+0x1c));V(self,0x5254)=self+0x30;while(!BattleMenu_LoadControllerResources(self+0x3760)){_ZN16BackgroundLoader14RemoveAllLocksEv(loader);PowerManagement_HandleLidStateAndResourceTransitions();}volatile unsigned* display=(volatile unsigned*)0x04000000;*display=(*display&~0x1f00)|0x1100;I(self,0x55f8)=1;BattleScene_EnableFlags((unsigned char*)self,32);
}

#include <globaldefs.h>
ARM
struct GameResources; struct State;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" void _ZN16BackgroundLoader10RemoveTaskEi(void*,int);
extern "C" void Window_PopCanvasesAndResetSelection(State*,int);
extern "C" void* SystemState_GetGlobalFlags();
extern "C" void SystemState_ClearFlags(unsigned*,unsigned);
extern "C" GameResources* GameResources_GetInstance();
extern "C" void GameResources_ClearPrimaryFlags(unsigned*,unsigned);
struct Flags { unsigned char unused:3,done:1,rest:4; };
// Original: arm9/ov008 @ 0x0218B240; symbol: func_ov008_0218b240; size: 0xC0.
extern "C" void Filesystem_RemoveFourOwnerLoadTasksAndMarkComplete(unsigned char* self) {
 if(((Flags*)(self+0xec0))->done) return;
 _ZN9GameState11GetInstanceEv();
 void* loader=_ZN16BackgroundLoader11GetInstanceEv();
 self[0xec0]&=~1;
 Window_PopCanvasesAndResetSelection((State*)(self+0x18),1);
 self[0xe99]=2; self[0xe9a]=0; self[0xe9b]=2; self[0xe9c]=0;
 SystemState_ClearFlags((unsigned*)SystemState_GetGlobalFlags(),0x2f);
 GameResources_ClearPrimaryFlags((unsigned*)GameResources_GetInstance(),0x10);
 _ZN16BackgroundLoader10RemoveTaskEi(loader,*(int*)(self+0xea0));
 _ZN16BackgroundLoader10RemoveTaskEi(loader,*(int*)(self+0xeb4));
 _ZN16BackgroundLoader10RemoveTaskEi(loader,*(int*)(self+0xea4));
 _ZN16BackgroundLoader10RemoveTaskEi(loader,*(int*)(self+0xea8));
 *(int*)(self+0xea0)=-1;
 *(int*)(self+0xeb4)=-1;
 *(int*)(self+0xea4)=-1;
 *(int*)(self+0xea8)=-1;
 self[0xec0]|=8;
}

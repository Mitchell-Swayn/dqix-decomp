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
extern "C" void* _ZN9GameState11GetInstanceEv();extern "C" void* GameState_ReadPResources(void*);extern "C" unsigned TextContext_GetSharedInstance();extern "C" void TextWindow_ResetGlyphBuffersAndFrameContexts(void*);extern "C" unsigned Window_IsVisible(void*);extern "C" void Window_HideAndResetOptionSelection(void**);extern "C" void _Z16SetSubBrightnessP13GameResourcesii(void*,int,int);extern "C" int _Z31IsSubBrightnessTransitionActiveP13GameResources(void*);extern "C" void InitializeThreeStateBytesOnce(void*);extern "C" void Menu_UpdateQueuedRecordPanel(unsigned char*);extern "C" void Menu_DestroyQueuedRecordPanelResources(void*);extern "C" void _ZN13SafeAllocator5ResetEv(void*);
// Original: arm9/ov003 @ 0x02158214; symbol: Graphics_AdvanceSubscreenPanelShutdown; size: 0x120.
extern "C" void Alltrades_AdvanceRewardPanelShutdown(char* self){
void* resources=GameState_ReadPResources(_ZN9GameState11GetInstanceEv());int phase=B(self,0x1f9);if(phase==0){I(self,0x32c)=0;TextWindow_ResetGlyphBuffersAndFrameContexts((void*)TextContext_GetSharedInstance());S(self,0x1ee)=-1;S(self,0x1ec)=S(self,0x1ee);if(V(self,0x1c)&&Window_IsVisible(V(self,0x1c)))Window_HideAndResetOptionSelection((void**)V(self,0x1c));B(self,0x1f9)=3;if(V(self,0x204)){_Z16SetSubBrightnessP13GameResourcesii(resources,-16,0);B(self,0x1f9)=1;}}else if(phase==1){if(!_Z31IsSubBrightnessTransitionActiveP13GameResources(resources)){InitializeThreeStateBytesOnce(V(self,0x204));B(self,0x1f9)=2;}}else if(phase==2){Menu_UpdateQueuedRecordPanel((unsigned char*)V(self,0x204));if(H(V(self,0x204),0x438)&4){Menu_DestroyQueuedRecordPanelResources(V(self,0x204));_ZN13SafeAllocator5ResetEv(V(self,0)+0x64);I(self,0x204)=0;I(self,0x200)=0;B(self,0x1f9)=3;}}else if(phase==3){B(self,0x1f8)=5;B(self,0x1f9)=0;}
}

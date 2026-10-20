#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_GetObjectWithFlag100(void*,int);
extern "C" char* GameState_GetIndexList(void*);
extern "C" void _ZN8Object3D11MakeVisibleEv(void*);
extern "C" void _Z22UnlockAndSetBrightnessP13GameResourcesii(void*,int,int);
extern "C" int _Z28IsBrightnessTransitionActiveP13GameResources(void*);
extern "C" void* TextContext_GetSharedInstance();
extern "C" void TextWindow_ResetGlyphBuffersAndFrameContexts(void*);
extern "C" bool SystemState_TestAnyFlags(const unsigned*,unsigned);
extern "C" unsigned char* NavigationMessage_GetGlobalInstance();
extern "C" unsigned* SystemState_GetGlobalFlags();
extern "C" void Window_HideAndResetOptionSelection(void*);
extern "C" void* GameResources_GetInstance();
// Original: arm9/ov003 @ 0x02165730; symbol: func_ov003_02165730; size: 0x158.
extern "C" void UpdatePartyVisibilityAndBrightnessTransition(unsigned char* p) {
 void* resources=GameResources_GetInstance();
 unsigned* global=SystemState_GetGlobalFlags();
 if(p[0x4a4]==0) {
 unsigned char* display=NavigationMessage_GetGlobalInstance();
 display[0x3c9]=(display[0x3c9]&~1)|1;
 TextWindow_ResetGlyphBuffersAndFrameContexts(TextContext_GetSharedInstance());
 *(short*)(p+0x486)=-1;
 *(short*)(p+0x484)=*(short*)(p+0x486);
 p[0x4a5]=0;
 void* state=_ZN9GameState11GetInstanceEv();
 char* list=GameState_GetIndexList(state);
 for(int i=0;i<*(unsigned char*)(list+0xf7c);i++) {
 void* obj=GameState_GetObjectWithFlag100(state,*(unsigned char*)(list+0xf78+i));
 if(obj) _ZN8Object3D11MakeVisibleEv(obj);
 }
 if(_Z28IsBrightnessTransitionActiveP13GameResources(resources)) return;
 _Z22UnlockAndSetBrightnessP13GameResourcesii(resources,0,15);
 p[0x4a4]=1;
 if(*(void**)(p+0x390)) Window_HideAndResetOptionSelection(*(void**)(p+0x390));
 } else if(p[0x4a4]==1) {
 if(_Z28IsBrightnessTransitionActiveP13GameResources(resources)) return;
 if(SystemState_TestAnyFlags(global,0x41)) *(unsigned*)(p+0x464)|=0x800;
 p[0x4a4]=2;
 } else if(p[0x4a4]==2) {
 TextWindow_ResetGlyphBuffersAndFrameContexts(TextContext_GetSharedInstance());
 *(short*)(p+0x486)=-1;
 *(short*)(p+0x484)=*(short*)(p+0x486);
 p[0x4a5]=0;
 p[0x4a3]=0x10;
 p[0x4a4]=0;
 }
}

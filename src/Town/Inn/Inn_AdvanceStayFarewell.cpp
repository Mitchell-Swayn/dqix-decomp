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
extern "C" void* _ZN9GameState11GetInstanceEv();extern "C" char* _ZN9GameState20GetUnknownGameObjectEv(void*);extern "C" unsigned TextContext_GetSharedInstance();extern "C" void* Network_GetConnectionManager();extern "C" bool Network_IsParentOrOffline(unsigned*);extern "C" void TextWindow_ResetGlyphBuffersAndFrameContexts(void*);extern "C" void* ResourceStringTable_GetTextByKey(void*,void*);extern "C" void Inn_StartStayDialogMessage(void*,unsigned);extern "C" void Window_PopCanvasesAndResetSelection(void*,int);
// Original: arm9/ov003 @ 0x0215DA0C; symbol: World_AdvanceConnectionDependentConfirmationPanel; size: 0x120.
extern "C" void Inn_AdvanceStayFarewell(char* self){
char* owner;int phase;void* game=_ZN9GameState11GetInstanceEv();owner=(char*)TextContext_GetSharedInstance();int primary;void* connection=Network_GetConnectionManager();primary=0;if(Network_IsParentOrOffline((unsigned*)connection)&&S(_ZN9GameState20GetUnknownGameObjectEv(game),4)==0)primary=1;int other=0;if(Network_IsParentOrOffline((unsigned*)connection)&&S(_ZN9GameState20GetUnknownGameObjectEv(game),4)!=0)other=1;phase=B(self,0x3b8);if(phase==0){if(B(self,0x3f3)){TextWindow_ResetGlyphBuffersAndFrameContexts(owner);++B(self,0x3b8);return;}int text=0x442;if(B(self,0x3f0)){if(primary){B(self,0x3f1)=1;text=110;}else text=other?116:115;}void* value=ResourceStringTable_GetTextByKey(self+0x64,(void*)text);Inn_StartStayDialogMessage(self,(unsigned)value);++B(self,0x3b8);}if(phase==1&&!I(owner,0x998)){Window_PopCanvasesAndResetSelection(self+0x98,1);B(self,0x3bc)=5;B(self,0x3b8)=0;}
}

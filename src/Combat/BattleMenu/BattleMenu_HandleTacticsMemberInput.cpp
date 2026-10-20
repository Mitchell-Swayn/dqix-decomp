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
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" int Selection_ReadEnabledIndexFromControl(void*);extern "C" int BattleMenu_TestConfirmInputAfterDelay(void*,int);extern "C" void SoundSfx_StartCurrentSequenceArchiveEntry(char*,int,void*);extern "C" char Main_UnknownRoleZeroInitializedStorage[];extern "C" void* BattleMenu_GetSelectedPartyCommandRecord(char*);extern "C" void BattleMenu_OpenPanelForSelectionState(void*,void*,int,int,int);extern "C" int BattleMenu_TestCancelInput(void*);extern "C" void Window_PopCanvasesAndResetSelection(void*,int);extern "C" void BattleMenu_ConfigureGlobalCommandSelection(void*,int,int);
// Original: arm9/ov000 @ 0x0217D324; symbol: Graphics_HandleNestedMenuConfirmOrCancel; size: 0x114.
extern "C" void BattleMenu_HandleTacticsMemberInput(char* self,int a,int b){
H(self,0x1d72)|=256;int selected=Selection_ReadEnabledIndexFromControl(self+0x188);if(selected<0)selected=0;B(self,0x1d6b)=selected;if(BattleMenu_TestConfirmInputAfterDelay(self,0)){SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,1,0);++C(self,0x1d68);B(self+C(self,0x1d68),0x1d60)=4;void* entry=BattleMenu_GetSelectedPartyCommandRecord(self);BattleMenu_OpenPanelForSelectionState(self,entry,4,a,b);}else if(BattleMenu_TestCancelInput(self)){Window_PopCanvasesAndResetSelection(self+0x188,0);B(self+C(self,0x1d68),0x1d60)=0;--C(self,0x1d68);C(self,0x1d6b)=-1;BattleMenu_ConfigureGlobalCommandSelection(self,a,b);}
}

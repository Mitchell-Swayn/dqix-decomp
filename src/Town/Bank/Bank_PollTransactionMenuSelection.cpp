#include <globaldefs.h>
ARM
extern "C" int Selection_DisableDirectionalInput(...);
extern "C" int SoundSfx_StartCurrentSequenceArchiveEntry(...);
extern "C" int Graphics_FormatAndReloadReadyTextRecord(...);
extern "C" int Selection_DisableTouchInput(...);
extern "C" int Selection_ReadEnabledIndexFromControl(...);
extern "C" int Selection_EnableDirectionalInput(...);
extern "C" int Selection_EnableTouchInput(...);
extern "C" int System_TestCombinedReadyFlags(...);
extern "C" int Bank_IsCancelRequested(...);
extern "C" int Bank_ConfigureMenuOrDigitSelectionGrids(...);
extern "C" int Bank_RefreshMenuAmountAndGoldText(...);
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);extern "C" char* strcpy(char*,const char*);extern "C" int sprintf(char*,const char*,...);
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char Main_UnknownRoleZeroInitializedStorage[];

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov003 @ 0x02169B30; symbol: AdvanceSelectionUntilConfirmedOrCancelled.
extern "C" int Bank_PollTransactionMenuSelection(char*self){
int phase=B(self,0x4e9);if(phase==0){Bank_ConfigureMenuOrDigitSelectionGrids(self);Selection_EnableTouchInput(self+228);Selection_EnableDirectionalInput(self+228);B(self,0x4e9)++;}else if(phase==1){B(self,0x59f)|=1;B(self,0x4ed)=Selection_ReadEnabledIndexFromControl(self+228);if(System_TestCombinedReadyFlags(self)){Graphics_FormatAndReloadReadyTextRecord(self,1,1);B(self,0x59f)&=~1;Bank_RefreshMenuAmountAndGoldText(self);B(self,0x4ea)=0;SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,1,0);Selection_DisableTouchInput(self+228);Selection_DisableDirectionalInput(self+228);B(self,0x4e9)=0;return *(signed char*)(self+0x4ed);}if(Bank_IsCancelRequested(self)){B(self,0x59f)&=~1;Selection_DisableTouchInput(self+228);Selection_DisableDirectionalInput(self+228);B(self,0x4e9)=0;return -2;}}return -1;
}

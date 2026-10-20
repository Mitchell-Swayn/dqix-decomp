#include <globaldefs.h>
ARM
extern "C" {char* TextContext_GetSharedInstance();void Window_PopCanvasesAndResetSelection(void*,int);void* ResourceStringTable_GetTextByKey(void*,unsigned);void Church_StartConfiguredMessage(void*,void*);void Network_QueueInnRecoveryValue(unsigned);void* GameResources_GetInstance();void Field_RebuildActiveRosterAndCameraTarget(void*,int,int,int,int);}
// Original: arm9/ov003 @ 0x0215AF00; symbol: InitializeSelectionAndDispatchWhenOwnerIdle; size: 0x9c.
// Initializes selection on state0 then dispatches reset when state1 owner998 is idle.
extern "C" void Church_AdvanceExitAndRestoreFieldParty(unsigned char* self){char* global=TextContext_GetSharedInstance();unsigned state=self[0x580];if(!state){Window_PopCanvasesAndResetSelection(self+0xf4,1);Church_StartConfiguredMessage(self,ResourceStringTable_GetTextByKey(self+0x64,0x442));++self[0x580];}if(state==1 && !*(int*)(global+0x998)){Network_QueueInnRecoveryValue(0);Field_RebuildActiveRosterAndCameraTarget(GameResources_GetInstance(),1,1,1,1);self[0x588]=11;self[0x580]=0;}}

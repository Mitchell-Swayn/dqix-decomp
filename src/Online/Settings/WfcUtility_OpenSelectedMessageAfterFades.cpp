#include <globaldefs.h>
ARM
extern "C" unsigned WfcUtility_IsScreenTransitionBusy(int);
extern "C" void WfcUtility_GetScreenOperationArguments(unsigned*,unsigned*);
extern "C" void WfcUtility_CreateSlidingDialog(int,int,int,int,int);
extern "C" void WfcUtility_SetMainLoopCallback(void(*)());
extern "C" void WfcUtility_CreateDisplayResourceAfterMessageCompletion();
// Original data: arm9/ov031 @ 0x22491e4; symbol: data_ov031_022491e4.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 2b0000002b00000049000000.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
struct Modes{int a,b,c;};extern "C" Modes WfcUtilityOpenSelectedMessageAfterFades_UnknownRoleInitializedBytes;
// Original: arm9/ov031 @ 0x022341D8; symbol: StartSelectedSharedModeAndInstallCallback; size: 0x88.
extern "C" void WfcUtility_OpenSelectedMessageAfterFades(void){
Modes modes=WfcUtilityOpenSelectedMessageAfterFades_UnknownRoleInitializedBytes;if(WfcUtility_IsScreenTransitionBusy(1))return;if(WfcUtility_IsScreenTransitionBusy(0))return;unsigned selected;WfcUtility_GetScreenOperationArguments(0,&selected);WfcUtility_CreateSlidingDialog(((int*)&modes)[selected],1,1,-1,0);WfcUtility_SetMainLoopCallback(WfcUtility_CreateDisplayResourceAfterMessageCompletion);
}

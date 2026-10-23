#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290d10; symbol: data_ov031_02290d10.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char* WfcUtilityDestroySlidingDialog_UnknownRoleZeroInitializedStorage;
extern "C" void WfcUtility_GetSpriteGroupPosition(void*,int,unsigned*,int*);
extern "C" void WfcUtility_SetDialogVerticalPosition(int);
extern "C" void WfcUtility_SetTaskCallback(void*,void (*)(void*,void*));
extern "C" void Graphics_AdvanceBrightnessFade(void*,void*);
extern "C" void WfcUtility_DestroySlidingDialog(void*,void*);
// Original: arm9/ov031 @ 0x022384F8; symbol: AdvancePackedEntryAndChooseCallback; size: 0x90.
// Advances packed entry low field by12 and selects callback at threshold192.
extern "C" void WfcUtility_AdvanceDialogSlideOut(void* object,void*){
 unsigned high;int low;WfcUtility_GetSpriteGroupPosition(*(void**)WfcUtilityDestroySlidingDialog_UnknownRoleZeroInitializedStorage,0,&high,&low);
 low+=12;WfcUtility_SetDialogVerticalPosition(low);if(low<192)return;
 if(WfcUtilityDestroySlidingDialog_UnknownRoleZeroInitializedStorage[0x1e])WfcUtility_SetTaskCallback(object,Graphics_AdvanceBrightnessFade);
 else WfcUtility_SetTaskCallback(object,WfcUtility_DestroySlidingDialog);
}

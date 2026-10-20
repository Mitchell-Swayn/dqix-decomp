#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290cd0; symbol: data_ov031_02290cd0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char InitializeBG2SharedSelectionAndCallback_UnknownRoleZeroInitializedStorage[];
extern "C" char* WfcUtility_GetConnectionProfileStorage();
extern "C" int System_AdvanceSharedSequenceOrDispatchPriorityState(void*);
extern "C" void* WfcUtility_GetPersistentIdentifierHeader();
extern "C" void MI_CpuCopy8(const void*,void*,unsigned);
extern "C" void WfcUtility_DestroyAnimatedStatusSprite();
extern "C" void Graphics_ClearIndexedMainBackgroundCharacterData(int);
extern "C" void WfcUtility_DisableDisplayPlanes(int,int);
extern "C" void WfcUtility_SetNavigationContext(int,int);
extern "C" void WfcUtility_SetMainLoopCallback(void(*)());
extern "C" void System_InitializeAndInstallMainLoopCallback();
extern "C" void System_LoadMainBG2AndScheduleMode0x2DCallback();
// Original: arm9/ov031 @ 0x02233CE0; symbol: CopyDefaultRecordsAndSelectSharedLoopCallback; size: 0xa4.
extern "C" void WfcUtility_RestoreProfileHeadersAndSelectNextScreen() {
 char* state=WfcUtility_GetConnectionProfileStorage();if(*(void**)(InitializeBG2SharedSelectionAndCallback_UnknownRoleZeroInitializedStorage+4) && !System_AdvanceSharedSequenceOrDispatchPriorityState(*(void**)(InitializeBG2SharedSelectionAndCallback_UnknownRoleZeroInitializedStorage+4)))return;
 MI_CpuCopy8(WfcUtility_GetPersistentIdentifierHeader(),state+0xf0,14);MI_CpuCopy8(WfcUtility_GetPersistentIdentifierHeader(),state+0x1f0,14);WfcUtility_DestroyAnimatedStatusSprite();Graphics_ClearIndexedMainBackgroundCharacterData(0);WfcUtility_DisableDisplayPlanes(0,21);
 if(!InitializeBG2SharedSelectionAndCallback_UnknownRoleZeroInitializedStorage[0]){WfcUtility_SetNavigationContext(0,1);WfcUtility_SetMainLoopCallback(System_InitializeAndInstallMainLoopCallback);}else{WfcUtility_SetNavigationContext(0,1);WfcUtility_SetMainLoopCallback(System_LoadMainBG2AndScheduleMode0x2DCallback);}
}

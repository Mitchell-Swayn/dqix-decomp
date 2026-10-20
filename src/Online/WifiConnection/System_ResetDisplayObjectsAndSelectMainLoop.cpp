#include <globaldefs.h>
ARM
extern "C" unsigned WfcUtility_IsScreenTransitionBusy(int);
extern "C" int WfcUtility_IsModeSpriteExitInactive();
extern "C" int WfcUtility_IsBottomButtonBarAbsentOrNotClosing();
extern "C" void Network_UnlinkNodeAndReleaseRecords(void*);
extern "C" void Overlay_ClearFourSharedObjects();
extern "C" void Overlay_ProcessPendingFlag();
extern "C" void WfcUtility_FreeArchiveResourceAndReturnPoolEntry(void*);
extern "C" void WfcUtility_LoadLocalizedResourceAndApply(void*,void(*)());
extern "C" void LoadToMainObjStandardPalette();
extern "C" void WfcUtility_DisableDisplayPlanes(unsigned,unsigned);
extern "C" void WfcUtility_SetNavigationContext(unsigned,unsigned);
extern "C" void WfcUtility_SetMainLoopCallback(void(*)());
extern "C" void WfcUtility_InitializeMainMenu();
extern "C" void WfcConnectionMethod_InitializeChooser();
extern "C" void WfcSettingsList_InitializeScreen();
extern "C" void WfcUtility_InitializeMessageScreenWithAnimatedHeader();
extern "C" char* WfcUtility_GetEditableConnectionProfile();
extern "C" void WfcUtility_SetScreenOperationArguments(unsigned,unsigned);
extern "C" void WfcSettingsList_SetEntryOriginMode(unsigned char);
extern "C" void WfcUtility_FreeAllocationAndClearPointer(void**);
// Original data: arm9/ov031 @ 0x2290cc0; symbol: data_ov031_02290cc0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char ConfigureSecondContextDisplay_UnknownRoleZeroInitializedStorage[],System_ResetDisplayObjectsAndSelectMainLoop_PathCharYbObjMainNclL[];
// Original data: arm9/ov031 @ 0x2290cc4; symbol: data_ov031_02290cc4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" void* SystemResetDisplayObjectsAndSelectMainLoop_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x02232B44; symbol: func_ov031_02232b44; size: 0x1A4.
extern "C" void System_ResetDisplayObjectsAndSelectMainLoop(){
 if(WfcUtility_IsScreenTransitionBusy(1))return;
 if(WfcUtility_IsScreenTransitionBusy(0))return;
 if(!WfcUtility_IsModeSpriteExitInactive())return;
 if(!WfcUtility_IsBottomButtonBarAbsentOrNotClosing())return;
 {char* global=ConfigureSecondContextDisplay_UnknownRoleZeroInitializedStorage;unsigned i=0;do{void* object=*(void**)(*(char**)(global+4)+4+i*4);if(object)Network_UnlinkNodeAndReleaseRecords(object);i++;}while(i<3);}
 {char* global=ConfigureSecondContextDisplay_UnknownRoleZeroInitializedStorage;unsigned i=0;do{void* object=*(void**)(*(char**)(global+4)+16+i*4);if(object)Network_UnlinkNodeAndReleaseRecords(object);i++;}while(i<3);}
 Overlay_ClearFourSharedObjects();Overlay_ProcessPendingFlag();
 WfcUtility_FreeArchiveResourceAndReturnPoolEntry(**(void***)(ConfigureSecondContextDisplay_UnknownRoleZeroInitializedStorage+4));
 WfcUtility_LoadLocalizedResourceAndApply(System_ResetDisplayObjectsAndSelectMainLoop_PathCharYbObjMainNclL,LoadToMainObjStandardPalette);
 WfcUtility_DisableDisplayPlanes(1,1);WfcUtility_DisableDisplayPlanes(0,20);
 if(*(unsigned char*)(*(char**)(ConfigureSecondContextDisplay_UnknownRoleZeroInitializedStorage+4)+0x1d)==2){WfcUtility_SetNavigationContext(0,0);WfcUtility_SetMainLoopCallback(WfcUtility_InitializeMainMenu);}
 else switch(*(unsigned char*)ConfigureSecondContextDisplay_UnknownRoleZeroInitializedStorage){
 case 0:case 1:case 2:
 WfcUtility_SetNavigationContext(2,0);
 if(*(unsigned char*)(WfcUtility_GetEditableConnectionProfile()+0xe7)==255)WfcUtility_SetMainLoopCallback(WfcConnectionMethod_InitializeChooser);
 else {WfcUtility_SetScreenOperationArguments(0,0);WfcSettingsList_SetEntryOriginMode(0);WfcUtility_SetMainLoopCallback(WfcSettingsList_InitializeScreen);}
 break;
 case 3:WfcUtility_SetNavigationContext(2,1);WfcUtility_SetMainLoopCallback(WfcUtility_InitializeMessageScreenWithAnimatedHeader);break;
 }
 WfcUtility_FreeAllocationAndClearPointer(&SystemResetDisplayObjectsAndSelectMainLoop_UnknownRoleZeroInitializedStorage);
}

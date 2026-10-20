#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((p)+(o)))
#define P(p,o) (*(unsigned char**)((p)+(o)))
#define H(p,o) (*(short*)((p)+(o)))
#define U(p,o) (*(unsigned short*)((p)+(o)))
// Original data: arm9/ov031 @ 0x2290c7c; symbol: data_ov031_02290c7c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" {unsigned WfcUtility_IsScreenTransitionBusy(int);int WfcUtility_IsBottomButtonBarAbsentOrNotClosing();int WfcUtility_IsConnectionContextAbsent();void WfcUtility_DestroyAnimatedStatusSprite();unsigned Graphics_ClearIndexedMainBackgroundCharacterData(unsigned);int Overlay_ProcessPendingFlag();void WfcUtility_DisableDisplayPlanes(unsigned,unsigned);void WfcUtility_SetNavigationContext(unsigned,unsigned);void WfcUtility_SetMainLoopCallback(void(*)());void Graphics_InitializeMappedPaletteScreenAndCallback();void WfcUtility_InitializeResponsePrompt();void WfcUtility_InitializeShortTextPrompt();extern unsigned char SystemInitializeModeCallbacks_UnknownRoleZeroInitializedStorage;}
// Original: arm9/ov031 @ 0x0222AD40; symbol: Graphics_AdvanceModeExitAndChooseMainLoop; size: 0xf8.
// Waits for display and control readiness then chooses mode-specific main-loop callback.
extern "C" void WfcUtility_FinishContextPromptExit(){if(WfcUtility_IsScreenTransitionBusy(0))return;if(!SystemInitializeModeCallbacks_UnknownRoleZeroInitializedStorage&&WfcUtility_IsScreenTransitionBusy(1))return;if(!WfcUtility_IsBottomButtonBarAbsentOrNotClosing())return;if(!SystemInitializeModeCallbacks_UnknownRoleZeroInitializedStorage&&!WfcUtility_IsConnectionContextAbsent())return;WfcUtility_DestroyAnimatedStatusSprite();Graphics_ClearIndexedMainBackgroundCharacterData(0);if(!SystemInitializeModeCallbacks_UnknownRoleZeroInitializedStorage){Overlay_ProcessPendingFlag();WfcUtility_DisableDisplayPlanes(1,1);}WfcUtility_DisableDisplayPlanes(0,21);if(!SystemInitializeModeCallbacks_UnknownRoleZeroInitializedStorage){WfcUtility_SetNavigationContext(0,1);WfcUtility_SetMainLoopCallback(Graphics_InitializeMappedPaletteScreenAndCallback);}else if(SystemInitializeModeCallbacks_UnknownRoleZeroInitializedStorage==2){WfcUtility_SetNavigationContext(0,1);WfcUtility_SetMainLoopCallback(WfcUtility_InitializeResponsePrompt);}else{WfcUtility_SetNavigationContext(0,1);WfcUtility_SetMainLoopCallback(WfcUtility_InitializeShortTextPrompt);}}

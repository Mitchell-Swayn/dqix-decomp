#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290c78; symbol: data_ov031_02290c78.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char ConfigureThirdContextFromSharedState_UnknownRoleZeroInitializedStorage[];
extern "C" int WfcUtility_IsConnectionContextAbsent();
extern "C" void Graphics_ClearIndexedMainBackgroundCharacterData(unsigned);
extern "C" void WfcUtility_DisableDisplayPlanes(unsigned,unsigned);
extern "C" int Overlay_ProcessPendingFlag();
extern "C" void WfcUtility_SetNavigationContext(unsigned,unsigned);
extern "C" void WfcUtility_SetMainLoopCallback(void(*)());
extern "C" void WfcUtility_InitializeResponsePrompt(),Graphics_InitializeMappedPaletteScreenAndCallback(),System_InitializeMenuAndScheduleCallback();
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
// Original: arm9/ov031 @ 0x0222A9C0; symbol: System_TransitionPendingScreenByTwoSharedFlags; size: 0xc8.
// Waits for pending screen work then clears planes and dispatches one of three callbacks from two flag bytes.
extern "C" void System_TransitionPendingScreenByTwoSharedFlags(){if(ConfigureThirdContextFromSharedState_UnknownRoleZeroInitializedStorage[0]||!ConfigureThirdContextFromSharedState_UnknownRoleZeroInitializedStorage[1])if(!WfcUtility_IsConnectionContextAbsent())return;Graphics_ClearIndexedMainBackgroundCharacterData(0);WfcUtility_DisableDisplayPlanes(0,21);if(!ConfigureThirdContextFromSharedState_UnknownRoleZeroInitializedStorage[1]){Overlay_ProcessPendingFlag();WfcUtility_DisableDisplayPlanes(1,1);}WfcUtility_SetNavigationContext(0,1);if(ConfigureThirdContextFromSharedState_UnknownRoleZeroInitializedStorage[0])WfcUtility_SetMainLoopCallback(WfcUtility_InitializeResponsePrompt);else if(!ConfigureThirdContextFromSharedState_UnknownRoleZeroInitializedStorage[1]){WfcUtility_DisableDisplayPlanes(1,1);WfcUtility_SetMainLoopCallback(Graphics_InitializeMappedPaletteScreenAndCallback);}else WfcUtility_SetMainLoopCallback(System_InitializeMenuAndScheduleCallback);}

#include <globaldefs.h>
ARM
extern "C" void WfcMultiScreen_LoadStatusBackground(void);
extern "C" void System_ConvertSharedRegionByteToIndexPlusFive(void);
extern "C" void Graphics_SubmitIndexedConfiguredBuffer(unsigned int);
extern "C" void WfcUtility_CreateAnimatedStatusSprite(unsigned int);
extern "C" void WfcUtility_SetMainLoopCallback(void (*)(void));
extern "C" void Ov031_SetDisplayPlaneAndNextCallback(void);
// Original data: arm9/ov031 @ 0x2290cb0; symbol: data_ov031_02290cb0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char DispatchOverlayStateTransition_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x02231558; symbol: System_InitializeMode2AAndScheduleCallback; size: 0x3C.
// Clears readiness, runs setup helpers, selects mode 0x2a, applies state 2, and schedules callback.
extern "C" void System_InitializeMode2AAndScheduleCallback(void) {
 DispatchOverlayStateTransition_UnknownRoleZeroInitializedStorage = 0;
 WfcMultiScreen_LoadStatusBackground();
 System_ConvertSharedRegionByteToIndexPlusFive();
 Graphics_SubmitIndexedConfiguredBuffer(0x2a);
 WfcUtility_CreateAnimatedStatusSprite(2);
 WfcUtility_SetMainLoopCallback(Ov031_SetDisplayPlaneAndNextCallback);
}

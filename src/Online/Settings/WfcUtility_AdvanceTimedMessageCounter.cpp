#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290c70; symbol: data_ov031_02290c70.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern unsigned char WfcUtilityAdvanceTimedMessageCounter_UnknownRoleZeroInitializedStorage;
typedef void (*MainLoopCallback)(void);
extern "C" void WfcUtility_SetMainLoopCallback(MainLoopCallback callback);
extern "C" void WfcUtility_BeginTimedMessageFadeOut(void);
// Original: arm9/ov031 @ 0x0222A328; symbol: func_ov031_0222a328; size: 0x34.
extern "C" void WfcUtility_AdvanceTimedMessageCounter(void) {
    unsigned char value = ++WfcUtilityAdvanceTimedMessageCounter_UnknownRoleZeroInitializedStorage;
    if (value >= 0x78) WfcUtility_SetMainLoopCallback(WfcUtility_BeginTimedMessageFadeOut);
}

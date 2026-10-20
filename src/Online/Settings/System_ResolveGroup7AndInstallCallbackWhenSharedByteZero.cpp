#include <globaldefs.h>
ARM
extern "C" int WfcUtility_GetBottomButtonSelection(void);
extern "C" void WfcUtility_SetMainLoopCallback(void (*callback)(void));
extern "C" void WfcUtility_PlaySequenceArchiveEntry(unsigned int);
extern "C" void System_SetSharedContextAndCallback(void);
// Original: arm9/ov031 @ 0x02228F54; symbol: System_ResolveGroup7AndInstallCallbackWhenSharedByteZero; size: 0x28.
// When the shared signed byte is zero, resolves group 7 and installs the next main-loop callback.
extern "C" void System_ResolveGroup7AndInstallCallbackWhenSharedByteZero(void) { if (!WfcUtility_GetBottomButtonSelection()) { WfcUtility_PlaySequenceArchiveEntry(7); WfcUtility_SetMainLoopCallback(System_SetSharedContextAndCallback); } }

#include <globaldefs.h>
ARM
extern "C" int WfcUtility_IsDialogActive(void);
extern "C" void WfcUtility_SetMainLoopCallback(void (*callback)(void));
extern "C" void System_SetSharedContextAndInstallThirdCallback(void);
// Original: arm9/ov031 @ 0x022324E8; symbol: func_ov031_022324e8; size: 0x20.
extern "C" void WfcUtility_ResumeReadinessScreenAfterDialog(void) { if (!WfcUtility_IsDialogActive()) WfcUtility_SetMainLoopCallback(System_SetSharedContextAndInstallThirdCallback); }

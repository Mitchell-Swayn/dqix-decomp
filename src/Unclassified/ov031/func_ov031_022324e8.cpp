#include <globaldefs.h>
ARM
extern "C" int HasSharedObjectPointer(void);
extern "C" void SetMainLoopCallback(void (*callback)(void));
extern "C" void System_SetSharedContextAndInstallThirdCallback(void);
// Original: arm9/ov031 @ 0x022324E8; symbol: func_ov031_022324e8; size: 0x20.
extern "C" void func_ov031_022324e8(void) { if (!HasSharedObjectPointer()) SetMainLoopCallback(System_SetSharedContextAndInstallThirdCallback); }

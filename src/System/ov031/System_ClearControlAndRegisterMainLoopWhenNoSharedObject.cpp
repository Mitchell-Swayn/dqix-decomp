#include <globaldefs.h>
ARM
extern "C" int HasSharedObjectPointer(void);
extern "C" void ClearGlobalControlByte18(void);
extern "C" void SetMainLoopCallback(void (*callback)(void));
extern "C" void System_RunNextThreeInitializationHelpers(void);
// Original: arm9/ov031 @ 0x02233154; symbol: func_ov031_02233154; size: 0x24.
extern "C" void System_ClearControlAndRegisterMainLoopWhenNoSharedObject(void) { if (!HasSharedObjectPointer()) { ClearGlobalControlByte18(); SetMainLoopCallback(System_RunNextThreeInitializationHelpers); } }

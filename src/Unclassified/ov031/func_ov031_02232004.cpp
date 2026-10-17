#include <globaldefs.h>
ARM
extern "C" int HasSharedObjectPointer(void);
extern "C" void SetMainLoopCallback(void (*callback)(void));
extern "C" void System_SetSharedByteAndInstallMode8Callback(void);
// Original: arm9/ov031 @ 0x02232004; symbol: func_ov031_02232004; size: 0x20.
extern "C" void func_ov031_02232004(void) {
    if (!HasSharedObjectPointer()) SetMainLoopCallback(System_SetSharedByteAndInstallMode8Callback);
}

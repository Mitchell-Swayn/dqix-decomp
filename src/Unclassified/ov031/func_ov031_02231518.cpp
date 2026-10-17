#include <globaldefs.h>
ARM
extern "C" int HasSharedObjectPointer(void);
extern "C" void SetMainLoopCallback(void (*callback)(void));
extern "C" void System_ConfigureSharedByteAndAlternateCallback(void);
// Original: arm9/ov031 @ 0x02231518; symbol: func_ov031_02231518; size: 0x20.
extern "C" void func_ov031_02231518(void) {
    if (!HasSharedObjectPointer()) SetMainLoopCallback(System_ConfigureSharedByteAndAlternateCallback);
}

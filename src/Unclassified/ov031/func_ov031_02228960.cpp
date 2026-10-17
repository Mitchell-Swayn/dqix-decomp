#include <globaldefs.h>
ARM
extern "C" int HasSharedObjectPointer(void);
extern "C" void SetMainLoopCallback(void (*callback)(void));
extern "C" void System_ConfigureSharedByteAndCallback(void);
// Original: arm9/ov031 @ 0x02228960; symbol: func_ov031_02228960; size: 0x20.
extern "C" void func_ov031_02228960(void) {
    if (!HasSharedObjectPointer()) SetMainLoopCallback(System_ConfigureSharedByteAndCallback);
}

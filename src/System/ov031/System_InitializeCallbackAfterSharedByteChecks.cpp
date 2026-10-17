#include <globaldefs.h>
ARM

extern "C" int ReadSharedSignedByteAtOffset22();
extern "C" void DispatchGlobalPointerOffset94WithZero();
extern "C" void System_ResolveGlobalGroupEntry(unsigned value);
extern "C" void SetMainLoopCallback(void (*callback)(void));
extern "C" void func_ov031_02234b2c(void);
extern "C" unsigned char data_ov031_02290ce4;

// Original: arm9/ov031 @ 0x02234AE0; symbol: func_ov031_02234ae0; size: 0x4C.
extern "C" void System_InitializeCallbackAfterSharedByteChecks(void) {
    if (data_ov031_02290ce4 != 0) return;
    if (ReadSharedSignedByteAtOffset22() != 0) return;
    data_ov031_02290ce4 = 2;
    DispatchGlobalPointerOffset94WithZero();
    System_ResolveGlobalGroupEntry(7);
    SetMainLoopCallback(func_ov031_02234b2c);
}

#include <globaldefs.h>
ARM
extern unsigned char data_ov031_02290c80;
extern "C" void DispatchGlobalPointerOffset94WithZero(void);
extern "C" void System_ResolveGlobalGroupEntry(int);
extern "C" void func_ov031_0222b1f0(void);
extern "C" void SetMainLoopCallback(void (*)(void), void *, int);
// Original: arm9/ov031 @ 0x0222B420; symbol: func_ov031_0222b420; size: 0x30.
extern "C" void System_InitializeCallbackStateAndInstallMainLoopCallback(void) {
    DispatchGlobalPointerOffset94WithZero();
    System_ResolveGlobalGroupEntry(7);
    data_ov031_02290c80 = 0;
    SetMainLoopCallback(func_ov031_0222b1f0, &data_ov031_02290c80, 0);
}

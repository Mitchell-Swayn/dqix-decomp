#include <globaldefs.h>
ARM

extern "C" void DispatchGlobalPointerOffset94WithZero(void);
extern "C" void System_ResolveGlobalGroupEntry(unsigned int);
extern "C" void Ov031_SetGlobalObjectField1E298(unsigned int);
extern "C" void SetMainLoopCallback(void (*callback)(void));
extern "C" void System_InitializeSharedCallbackSequence(void);
extern "C" unsigned char data_ov031_02290c7c[];

// Original: arm9/ov031 @ 0x0222AE38; symbol: func_ov031_0222ae38; size: 0x5C.
extern "C" void System_InitializeModeCallbacks(int mode) {
    DispatchGlobalPointerOffset94WithZero();
    if (mode == 0) {
        data_ov031_02290c7c[0] = 1;
        System_ResolveGlobalGroupEntry(0x10);
    } else {
        data_ov031_02290c7c[0] = 2;
        System_ResolveGlobalGroupEntry(0x12);
    }
    Ov031_SetGlobalObjectField1E298(0);
    SetMainLoopCallback(System_InitializeSharedCallbackSequence);
}

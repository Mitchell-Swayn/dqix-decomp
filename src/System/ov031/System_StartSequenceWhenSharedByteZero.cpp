#include <globaldefs.h>
ARM
extern "C" int ReadSharedSignedByteAtOffset22(void);
extern "C" void DispatchGlobalPointerOffset94WithZero(void);
extern "C" unsigned int System_ResolveGlobalGroupEntry(unsigned int index);
extern "C" void SetMainLoopCallback(void (*callback)(void));
extern "C" void System_InitializeSharedCallbackSequence(void);
// Original: arm9/ov031 @ 0x0222AC5C; symbol: func_ov031_0222ac5c; size: 0x2C.
extern "C" void System_StartSequenceWhenSharedByteZero(void) {
    if (ReadSharedSignedByteAtOffset22() != 0)
        return;
    DispatchGlobalPointerOffset94WithZero();
    System_ResolveGlobalGroupEntry(7);
    SetMainLoopCallback(System_InitializeSharedCallbackSequence);
}

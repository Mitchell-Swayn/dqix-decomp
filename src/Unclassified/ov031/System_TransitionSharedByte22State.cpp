#include <globaldefs.h>
ARM
extern "C" int ReadSharedSignedByteAtOffset22(void);
extern "C" void System_ResolveGlobalGroupEntry(int);
extern "C" void SetMainLoopCallback(void (*)(void));
extern "C" void System_ConfigureSharedByteAndCallback(void);
extern "C" void System_TransitionFromSharedContextState(void);
extern "C" void func_ov031_02237b2c(unsigned int, unsigned int, unsigned int, int, unsigned int);
extern "C" void SetSharedByte18(void);
// Original: arm9/ov031 @ 0x0222876C; symbol: func_ov031_0222876c; size: 0x68.
extern "C" void System_TransitionSharedByte22State(void) {
    int state = ReadSharedSignedByteAtOffset22();
    if (state == 0) goto zero_state;
    if (state == 1) goto one_state;
    return;
zero_state:
    System_ResolveGlobalGroupEntry(7);
    SetMainLoopCallback(System_ConfigureSharedByteAndCallback);
    return;
one_state:
    System_ResolveGlobalGroupEntry(6);
    func_ov031_02237b2c(0x18, 0, 1, -1, 0);
    SetSharedByte18();
    SetMainLoopCallback(System_TransitionFromSharedContextState);
}

#include <globaldefs.h>
ARM
extern "C" int ReadSharedObjectSignedByte1B(void);
extern "C" void System_ResolveGlobalGroupEntry(int);
extern "C" void CreateSharedDisplayResource(void);
extern "C" unsigned char data_ov031_02290c58;
extern "C" void SetMainLoopCallback(void (*)(void));
extern "C" void func_ov031_02228960(void);
// Original: arm9/ov031 @ 0x02228910; symbol: func_ov031_02228910; size: 0x50.
extern "C" void System_TransitionFromSharedContextState(void) {
    int state = ReadSharedObjectSignedByte1B();
    if (state != 0) {
        if (state != 1) return;
        System_ResolveGlobalGroupEntry(0xe);
        data_ov031_02290c58 = 1;
    } else {
        System_ResolveGlobalGroupEntry(7);
    }
    CreateSharedDisplayResource();
    SetMainLoopCallback(func_ov031_02228960);
}

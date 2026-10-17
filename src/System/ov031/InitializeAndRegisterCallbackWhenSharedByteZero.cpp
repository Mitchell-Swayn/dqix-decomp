#include <globaldefs.h>
ARM
extern "C" int ReadSharedSignedByteAtOffset22(void);
extern "C" void System_ResolveGlobalGroupEntry(unsigned int);
extern "C" void func_ov031_02228b0c(void);
extern "C" void SetMainLoopCallback(void (*)(void));
// Original: arm9/ov031 @ 0x02228AE4; symbol: func_ov031_02228ae4; size: 0x28.
extern "C" void InitializeAndRegisterCallbackWhenSharedByteZero(void) {
    if (ReadSharedSignedByteAtOffset22() == 0) {
        System_ResolveGlobalGroupEntry(6);
        SetMainLoopCallback(func_ov031_02228b0c);
    }
}

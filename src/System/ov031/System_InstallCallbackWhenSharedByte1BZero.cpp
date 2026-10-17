#include <globaldefs.h>
ARM
extern "C" int ReadSharedObjectSignedByte1B(void);
extern "C" void System_ResolveGlobalGroupEntry(int);
extern "C" void CreateSharedDisplayResource(void);
extern "C" void SetMainLoopCallback(void (*callback)(void));
extern "C" void func_ov031_02231968(void);
// Original: arm9/ov031 @ 0x0223193C; symbol: func_ov031_0223193c; size: 0x2C.
extern "C" void System_InstallCallbackWhenSharedByte1BZero(void) {
    if (ReadSharedObjectSignedByte1B() != 0)
        return;
    System_ResolveGlobalGroupEntry(6);
    CreateSharedDisplayResource();
    SetMainLoopCallback(func_ov031_02231968);
}

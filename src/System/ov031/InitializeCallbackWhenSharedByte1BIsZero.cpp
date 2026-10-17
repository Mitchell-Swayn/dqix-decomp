#include <globaldefs.h>
ARM
extern "C" int ReadSharedObjectSignedByte1B(void);
extern "C" void System_ResolveGlobalGroupEntry(unsigned int value);
extern "C" void CreateSharedDisplayResource(void);
extern "C" void func_ov031_02232004(void);
extern "C" void SetMainLoopCallback(void (*callback)(void));
// Original: arm9/ov031 @ 0x02231FD8; symbol: func_ov031_02231fd8; size: 0x2C.
extern "C" void InitializeCallbackWhenSharedByte1BIsZero(void) {
    if (ReadSharedObjectSignedByte1B() != 0) return;
    System_ResolveGlobalGroupEntry(6);
    CreateSharedDisplayResource();
    SetMainLoopCallback(func_ov031_02232004);
}

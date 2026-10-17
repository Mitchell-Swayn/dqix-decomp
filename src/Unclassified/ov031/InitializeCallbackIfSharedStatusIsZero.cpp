#include <globaldefs.h>
ARM
extern "C" void func_ov031_0223429c(void);
extern "C" void func_ov031_022342a0(void);
extern "C" int ReadSharedObjectSignedByte1B(void);
extern "C" void System_ResolveGlobalGroupEntry(int);
extern "C" void CreateSharedDisplayResource(void);
extern "C" void SetMainLoopCallback(void*);
extern "C" void func_ov031_022342a4(void);
// Original: arm9/ov031 @ 0x02234260; symbol: func_ov031_02234260; size: 0x3C.
extern "C" void InitializeCallbackIfSharedStatusIsZero(void) {
    func_ov031_0223429c();
    func_ov031_022342a0();
    if (ReadSharedObjectSignedByte1B())
        return;
    System_ResolveGlobalGroupEntry(6);
    CreateSharedDisplayResource();
    System_ResolveGlobalGroupEntry(6);
    SetMainLoopCallback((void*)func_ov031_022342a4);
}

#include <globaldefs.h>
ARM
extern "C" int ReadSharedObjectSignedByte1B();
extern "C" void System_ResolveGlobalGroupEntry(unsigned);
extern "C" void CreateSharedDisplayResource();
extern "C" void SetMainLoopCallback(void (*)());
extern "C" void func_ov031_02234e40();
extern "C" unsigned char data_ov031_02290ce4[];
// Original: arm9/ov031 @ 0x02234DE4; symbol: func_ov031_02234de4; size: 0x5C.
extern "C" void System_SelectTransitionCallbackBySharedMode(void) {
    int mode = ReadSharedObjectSignedByte1B();
    if (mode == 0) goto zero;
    if (mode != 1) return;
    data_ov031_02290ce4[0] = 3;
    System_ResolveGlobalGroupEntry(6);
    goto common;
zero:
    data_ov031_02290ce4[0] = 1;
    System_ResolveGlobalGroupEntry(7);
common:
    CreateSharedDisplayResource();
    SetMainLoopCallback(func_ov031_02234e40);
}

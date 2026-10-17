#include <globaldefs.h>
extern "C" unsigned ReadSelectedContextByte9(int);
extern "C" void func_ov031_02223568(unsigned);
extern "C" void System_ClearAndRegisterSecondCallbackUnlessSharedByteMinusTwo();
extern "C" void SetMainLoopCallback(void (*)());
// Original: arm9/ov031 @ 0x02232188; symbol: func_ov031_02232188; size: 0x3C.
extern "C" ARM void Ov031_InstallCallbackWhenContextsIdle() {
    if (ReadSelectedContextByte9(1)) return;
    if (ReadSelectedContextByte9(0)) return;
    func_ov031_02223568(1);
    SetMainLoopCallback(System_ClearAndRegisterSecondCallbackUnlessSharedByteMinusTwo);
}

#include <globaldefs.h>
extern "C" unsigned ReadSelectedContextByte9(int);
extern "C" void func_ov031_02223568(int);
extern "C" void SetMainLoopCallback(void (*)());
extern "C" void System_ClearAndRegisterCallbackUnlessSharedByteMinusTwo();
// Original: arm9/ov031 @ 0x0222E82C; symbol: func_ov031_0222e82c; size: 0x3C.
extern "C" void System_InstallCallbackWhenBothContextBytesClear() {
    if (ReadSelectedContextByte9(1)) return;
    if (ReadSelectedContextByte9(0)) return;
    func_ov031_02223568(4);
    SetMainLoopCallback(System_ClearAndRegisterCallbackUnlessSharedByteMinusTwo);
}

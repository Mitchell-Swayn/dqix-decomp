#include <globaldefs.h>
ARM
extern "C" unsigned int ReadSelectedContextByte9(int);
extern "C" void func_ov031_02223568(int);
extern "C" void SetMainLoopCallback(void (*)(void));
extern "C" void System_InstallThirdMainLoopCallbackUnlessSharedByteIsMinus2(void);
// Original: arm9/ov031 @ 0x0222BAE0; symbol: func_ov031_0222bae0; size: 0x3C.
extern "C" void System_InstallContextCallbackWhenIdleThird(void) {
    if (ReadSelectedContextByte9(1) != 0) return;
    if (ReadSelectedContextByte9(0) != 0) return;
    func_ov031_02223568(0);
    SetMainLoopCallback(System_InstallThirdMainLoopCallbackUnlessSharedByteIsMinus2);
}

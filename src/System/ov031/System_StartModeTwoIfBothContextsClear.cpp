#include <globaldefs.h>
ARM
extern "C" unsigned ReadSelectedContextByte9(int screen);
extern "C" void func_ov031_02223568(unsigned);
extern "C" void SetMainLoopCallback(void (*)());
extern "C" void System_InstallMainLoopCallbackUnlessSharedByteIsMinus2();
// Original: arm9/ov031 @ 0x02228EB8; symbol: func_ov031_02228eb8; size: 0x3C.
extern "C" void System_StartModeTwoIfBothContextsClear(void) {
    if (ReadSelectedContextByte9(1)) return;
    if (ReadSelectedContextByte9(0)) return;
    func_ov031_02223568(2);
    SetMainLoopCallback(System_InstallMainLoopCallbackUnlessSharedByteIsMinus2);
}

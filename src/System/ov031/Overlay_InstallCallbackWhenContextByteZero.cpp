#include <globaldefs.h>
ARM
extern "C" unsigned int ReadSelectedContextByte9(int screen);
extern "C" void func_ov031_02223568(int);
extern "C" void SetMainLoopCallback(void (*callback)(void));
extern "C" void System_InstallFourthMainLoopCallbackUnlessSharedByteIsMinus2(void);
// Original: arm9/ov031 @ 0x02231230; symbol: func_ov031_02231230; size: 0x2C.
extern "C" void Overlay_InstallCallbackWhenContextByteZero(void) {
    if (ReadSelectedContextByte9(0) != 0)
        return;
    func_ov031_02223568(1);
    SetMainLoopCallback(System_InstallFourthMainLoopCallbackUnlessSharedByteIsMinus2);
}

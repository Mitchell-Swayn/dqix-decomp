#include <globaldefs.h>
ARM

extern "C" unsigned int ReadSelectedContextByte9(int);
extern "C" void func_ov031_02223568(unsigned);
extern "C" void SetMainLoopCallback(void (*)(void));
extern "C" void System_ClearControlAndInstallCallbackUnlessSentinel(void);

// Original: arm9/ov031 @ 0x0223466C; symbol: func_ov031_0223466c; size: 0x3C.
extern "C" void System_InitializeCallbackWhenBothContextsClear(void) {
    if (ReadSelectedContextByte9(1) != 0) {
        return;
    }
    if (ReadSelectedContextByte9(0) != 0) {
        return;
    }
    func_ov031_02223568(6);
    SetMainLoopCallback(System_ClearControlAndInstallCallbackUnlessSentinel);
}

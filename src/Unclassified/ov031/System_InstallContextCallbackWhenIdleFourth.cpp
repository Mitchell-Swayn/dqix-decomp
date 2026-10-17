#include <globaldefs.h>
ARM
extern "C" unsigned int ReadSelectedContextByte9(int);
extern "C" void func_ov031_02223568(int);
extern "C" void SetMainLoopCallback(void (*)(void));
extern "C" void ClearControlAndRegisterCallback33510UnlessValueMinusTwo(void);
// Original: arm9/ov031 @ 0x022334AC; symbol: func_ov031_022334ac; size: 0x3C.
extern "C" void System_InstallContextCallbackWhenIdleFourth(void) {
    if (ReadSelectedContextByte9(1) != 0) return;
    if (ReadSelectedContextByte9(0) != 0) return;
    func_ov031_02223568(0);
    SetMainLoopCallback(ClearControlAndRegisterCallback33510UnlessValueMinusTwo);
}

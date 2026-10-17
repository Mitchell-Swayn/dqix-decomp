#include <globaldefs.h>
ARM
extern "C" void func_ov031_0223c078(unsigned, unsigned, unsigned, unsigned);
extern "C" void EnableDisplayControlPlaneBits(int, unsigned);
extern "C" void SetMainLoopCallback(void (*)());
extern "C" void System_SetMainLoopCallbackIfContextByte9IsZero();
// Original: arm9/ov031 @ 0x0222A814; symbol: func_ov031_0222a814; size: 0x34.
extern "C" void System_ConfigureDisplayPlaneAndCallback(void) {
    func_ov031_0223c078(2, 0, 0x15, 8);
    EnableDisplayControlPlaneBits(0, 0x15);
    SetMainLoopCallback(System_SetMainLoopCallbackIfContextByte9IsZero);
}

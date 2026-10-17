#include <globaldefs.h>
extern "C" void func_ov031_0223c078(int, int, int, int);
extern "C" void EnableDisplayControlPlaneBits(int, unsigned);
extern "C" void SetMainLoopCallback(void (*)());
extern "C" void Overlay_SetMainLoopCallbackWhenContextByteZero();
// Original: arm9/ov031 @ 0x0222A210; symbol: func_ov031_0222a210; size: 0x34.
extern "C" void System_ConfigureDisplayAndRegisterMainLoop() {
    func_ov031_0223c078(2, 0, 0x15, 8);
    EnableDisplayControlPlaneBits(0, 0x15);
    SetMainLoopCallback(Overlay_SetMainLoopCallbackWhenContextByteZero);
}

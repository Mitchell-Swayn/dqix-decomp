#include <globaldefs.h>
extern "C" void func_ov031_0223c078(unsigned, unsigned, unsigned, unsigned);
extern "C" void EnableDisplayControlPlaneBits(int, unsigned);
extern "C" void Overlay_InitializeCallbacksWhenContextByteZero();
extern "C" void SetMainLoopCallback(void (*)());
// Original: arm9/ov031 @ 0x0222982C; symbol: func_ov031_0222982c; size: 0x34.
extern "C" ARM void Ov031_SetDisplayPlaneAndCallback() {
    func_ov031_0223c078(2, 0, 0x15, 8);
    EnableDisplayControlPlaneBits(0, 0x15);
    SetMainLoopCallback(Overlay_InitializeCallbacksWhenContextByteZero);
}

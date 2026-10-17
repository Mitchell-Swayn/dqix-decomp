#include <globaldefs.h>
extern "C" void func_ov031_0223c078(unsigned, unsigned, unsigned, unsigned);
extern "C" void EnableDisplayControlPlaneBits(int, unsigned);
extern "C" void SetMainLoopCallback(void (*)());
extern "C" void System_InstallCallbackIfScreenZeroContextByteIsClear();
// Original: arm9/ov031 @ 0x0222B4F8; symbol: func_ov031_0222b4f8; size: 0x34.
extern "C" void OV031_InitializeDisplayTask(void) {
    func_ov031_0223c078(2, 0, 0x15, 8);
    EnableDisplayControlPlaneBits(0, 0x15);
    SetMainLoopCallback(System_InstallCallbackIfScreenZeroContextByteIsClear);
}

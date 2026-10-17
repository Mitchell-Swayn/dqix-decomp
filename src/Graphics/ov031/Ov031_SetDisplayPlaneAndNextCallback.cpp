#include <globaldefs.h>
extern "C" void func_ov031_0223c078(unsigned, unsigned, unsigned, unsigned);
extern "C" void EnableDisplayControlPlaneBits(int, unsigned);
extern "C" void InitializeContextCallbackWhenByte9IsZero();
extern "C" void SetMainLoopCallback(void (*)());
// Original: arm9/ov031 @ 0x02231614; symbol: func_ov031_02231614; size: 0x34.
extern "C" ARM void Ov031_SetDisplayPlaneAndNextCallback() {
    func_ov031_0223c078(2, 0, 0x15, 8);
    EnableDisplayControlPlaneBits(0, 0x15);
    SetMainLoopCallback(InitializeContextCallbackWhenByte9IsZero);
}

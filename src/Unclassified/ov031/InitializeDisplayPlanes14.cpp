#include <globaldefs.h>
ARM
extern "C" void func_ov031_0223c078(int, int, int, int);
extern "C" void EnableDisplayControlPlaneBits(int, unsigned);
extern "C" void SetMainLoopCallback(void*);
extern "C" void func_ov031_022341d8(void);
// Original: arm9/ov031 @ 0x02234184; symbol: func_ov031_02234184; size: 0x54.
extern "C" void InitializeDisplayPlanes14(void) {
    func_ov031_0223c078(2, 1, 1, 8);
    func_ov031_0223c078(2, 0, 0x14, 8);
    EnableDisplayControlPlaneBits(1, 1);
    EnableDisplayControlPlaneBits(0, 0x14);
    SetMainLoopCallback((void*)func_ov031_022341d8);
}

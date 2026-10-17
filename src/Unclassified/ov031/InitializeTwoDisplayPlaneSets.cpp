#include <globaldefs.h>
ARM
extern "C" void func_ov031_0223c078(int, int, int, int);
extern "C" void EnableDisplayControlPlaneBits(int, unsigned);
extern "C" void SetMainLoopCallback(void*);
extern "C" void func_ov031_0222d9a4(void);
// Original: arm9/ov031 @ 0x0222D950; symbol: func_ov031_0222d950; size: 0x54.
extern "C" void InitializeTwoDisplayPlaneSets(void) {
    func_ov031_0223c078(2, 1, 1, 8);
    func_ov031_0223c078(2, 0, 0x15, 8);
    EnableDisplayControlPlaneBits(1, 1);
    EnableDisplayControlPlaneBits(0, 0x15);
    SetMainLoopCallback((void*)func_ov031_0222d9a4);
}

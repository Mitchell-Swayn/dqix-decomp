#include <globaldefs.h>
ARM
extern "C" void func_ov031_0223c078(int, int, int, int);
extern "C" void EnableDisplayControlPlaneBits(int, unsigned);
extern "C" void SetMainLoopCallback(void*);
extern "C" void func_ov031_02233f1c(void);
// Original: arm9/ov031 @ 0x02233EE8; symbol: func_ov031_02233ee8; size: 0x34.
extern "C" void InitializeDisplayPlaneTransition(void) {
    func_ov031_0223c078(2, 0, 0x15, 8);
    EnableDisplayControlPlaneBits(0, 0x15);
    SetMainLoopCallback((void*)func_ov031_02233f1c);
}

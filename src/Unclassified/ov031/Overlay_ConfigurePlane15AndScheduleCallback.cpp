#include <globaldefs.h>
ARM
extern "C" void func_ov031_0223c078(unsigned, unsigned, unsigned, unsigned);
extern "C" void EnableDisplayControlPlaneBits(int, unsigned);
extern "C" void SetMainLoopCallback(void*);
extern "C" void func_ov031_02229cb8(void);
// Original: arm9/ov031 @ 0x02229C84; symbol: func_ov031_02229c84; size: 0x34.
extern "C" void Overlay_ConfigurePlane15AndScheduleCallback(void) {
    func_ov031_0223c078(2, 0, 0x15, 8);
    EnableDisplayControlPlaneBits(0, 0x15);
    SetMainLoopCallback((void*)func_ov031_02229cb8);
}

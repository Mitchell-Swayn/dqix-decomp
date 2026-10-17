#include <globaldefs.h>
ARM
extern "C" void func_ov031_0223c078(unsigned, unsigned, unsigned, unsigned);
extern "C" void EnableDisplayControlPlaneBits(int, unsigned);
extern "C" void ReadOptionalSharedWords18And1C(unsigned*, unsigned*);
extern "C" void SetMainLoopCallback(void*);
extern "C" void func_ov031_02233c40(void);
// Original: arm9/ov031 @ 0x02233BD4; symbol: func_ov031_02233bd4; size: 0x6C.
extern "C" void Overlay_ConfigureDisplayWhenSharedWordIsClear(void) {
    func_ov031_0223c078(2, 0, 0x15, 8);
    EnableDisplayControlPlaneBits(0, 0x15);
    unsigned value;
    ReadOptionalSharedWords18And1C(0, &value);
    if (value == 0) {
        func_ov031_0223c078(2, 1, 1, 8);
        EnableDisplayControlPlaneBits(1, 1);
    }
    SetMainLoopCallback((void*)func_ov031_02233c40);
}

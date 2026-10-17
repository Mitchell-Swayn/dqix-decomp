#include <globaldefs.h>
ARM
extern "C" void func_ov031_0223c078(unsigned, unsigned, unsigned, unsigned);
extern "C" void EnableDisplayControlPlaneBits(int screen, unsigned planes);
extern "C" void SetMainLoopCallback(void (*callback)(void));
extern "C" void OV031_StartCallbackWhenContextsClear(void);
// Original: arm9/ov031 @ 0x0222AFBC; symbol: func_ov031_0222afbc; size: 0x54.
extern "C" void Overlay_ConfigureDisplayModeTwoAndCallback(void) {
    func_ov031_0223c078(2, 1, 1, 8);
    func_ov031_0223c078(2, 0, 0x15, 8);
    EnableDisplayControlPlaneBits(1, 1);
    EnableDisplayControlPlaneBits(0, 0x15);
    SetMainLoopCallback(OV031_StartCallbackWhenContextsClear);
}

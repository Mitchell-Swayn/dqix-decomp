#include <globaldefs.h>
ARM
extern "C" void func_ov031_0223c078(unsigned first, unsigned second, unsigned third, unsigned fourth);
extern "C" void EnableDisplayControlPlaneBits(int screen, unsigned planes);
extern "C" void SetMainLoopCallback(void (*callback)(void));
extern "C" void Overlay_InstallCallbackWhenContextByteZero(void);
// Original: arm9/ov031 @ 0x022311FC; symbol: func_ov031_022311fc; size: 0x34.
extern "C" void Overlay_ConfigureDisplayPlanesAndCallback(void) {
    func_ov031_0223c078(2, 0, 0x15, 8);
    EnableDisplayControlPlaneBits(0, 0x15);
    SetMainLoopCallback(Overlay_InstallCallbackWhenContextByteZero);
}

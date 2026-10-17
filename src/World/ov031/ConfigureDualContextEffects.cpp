#include <globaldefs.h>
ARM
extern "C" void func_ov031_0223c078(int, int, int, int);
extern "C" void SetMainLoopCallback(void*);
extern "C" void Overlay_ConfigureTransitionCallbackFromState();
// Original: arm9/ov031 @ 0x02227F74; symbol: func_ov031_02227f74; size: 0x3C.
extern "C" void ConfigureDualContextEffects() {
    func_ov031_0223c078(2, 1, 2, 0x14);
    func_ov031_0223c078(2, 0, 2, 0x14);
    SetMainLoopCallback((void*)Overlay_ConfigureTransitionCallbackFromState);
}

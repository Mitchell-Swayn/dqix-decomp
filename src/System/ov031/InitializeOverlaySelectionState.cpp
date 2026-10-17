#include <globaldefs.h>
ARM
extern "C" void func_ov031_02233524(void);
extern "C" void func_ov031_022336a8(void);
extern "C" void Overlay_TransitionSharedStateAndCallback(void);
// Original: arm9/ov031 @ 0x02233510; symbol: func_ov031_02233510; size: 0x14.
extern "C" void InitializeOverlaySelectionState(void) {
    func_ov031_02233524();
    func_ov031_022336a8();
    Overlay_TransitionSharedStateAndCallback();
}

#include <globaldefs.h>
ARM
extern "C" void Graphics_LoadStepThreeBackgroundAssets(void);
extern "C" void System_ConvertSharedRegionByteToIndexPlusFive(void);
extern "C" void func_ov031_02236174(void);
extern "C" void System_ConfigureDisplayPlanesMask14(void);
extern "C" void SetMainLoopCallback(void (*callback)(void));
// Original: arm9/ov031 @ 0x02230F00; symbol: func_ov031_02230f00; size: 0x20.
extern "C" void InitializeOverlayStateAndScheduleCallback(void) {
    Graphics_LoadStepThreeBackgroundAssets();
    System_ConvertSharedRegionByteToIndexPlusFive();
    func_ov031_02236174();
    SetMainLoopCallback(System_ConfigureDisplayPlanesMask14);
}

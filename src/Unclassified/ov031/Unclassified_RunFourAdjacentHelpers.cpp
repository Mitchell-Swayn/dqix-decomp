#include <globaldefs.h>
ARM
extern "C" void Input_UpdateSelectionFromRectangleGroups(void);
extern "C" void func_ov031_022244d4(void);
extern "C" void System_UpdateActiveInputRegionAndRepeatCounter(void);
extern "C" void func_ov031_02224a74(void);
// Original: arm9/ov031 @ 0x022242D4; symbol: func_ov031_022242d4; size: 0x18.
extern "C" void Unclassified_RunFourAdjacentHelpers(void) {
    Input_UpdateSelectionFromRectangleGroups();
    func_ov031_022244d4();
    System_UpdateActiveInputRegionAndRepeatCounter();
    func_ov031_02224a74();
}

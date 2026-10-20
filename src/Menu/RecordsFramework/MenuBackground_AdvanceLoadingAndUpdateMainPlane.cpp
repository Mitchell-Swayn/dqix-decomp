#include <globaldefs.h>
ARM
extern "C" void Graphics_AdvanceTaskAndToggleMainPlaneZero(int, int, int, int);
// Original: arm9/ov023 @ 0x021FBDAC; symbol: func_ov023_021fbdac; size: 0x10.
extern "C" void MenuBackground_AdvanceLoadingAndUpdateMainPlane(int a0, int a1, int a2, int a3) {
    Graphics_AdvanceTaskAndToggleMainPlaneZero(a0 + 0x20, a1, a2, a3);
}

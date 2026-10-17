#include <globaldefs.h>
ARM
extern "C" void Script_SetBrightnessByMode(int, int, int);
// Original: arm9/ov001 @ 0x0215B5DC; symbol: func_ov001_0215b5dc; size: 0x1C.
extern "C" int Util_CallTargetWithType6(int a0, int a1) {
    Script_SetBrightnessByMode(6, a0, a1);
    return 1;
}

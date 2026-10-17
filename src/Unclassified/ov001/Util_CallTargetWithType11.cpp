#include <globaldefs.h>
ARM
extern "C" void Script_SetBrightnessByMode(int, int, int);
// Original: arm9/ov001 @ 0x0215B668; symbol: func_ov001_0215b668; size: 0x1C.
extern "C" int Util_CallTargetWithType11(int a0, int a1) {
    Script_SetBrightnessByMode(0xb, a0, a1);
    return 1;
}

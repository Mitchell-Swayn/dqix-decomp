#include <globaldefs.h>
ARM
extern "C" void Script_SetBrightnessByMode(unsigned int, unsigned int, unsigned int);
// Original: arm9/ov001 @ 0x0215B630; symbol: func_ov001_0215b630; size: 0x1C.
extern "C" int CallFunctionWithMode9AndReturnOne(unsigned int first, unsigned int second) {
    Script_SetBrightnessByMode(9, first, second);
    return 1;
}

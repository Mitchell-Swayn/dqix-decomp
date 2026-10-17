#include <globaldefs.h>
ARM
extern "C" void Graphics_SelectBackgroundStateRecord(void *object);
// Original: arm9/ov023 @ 0x021FBDCC; symbol: func_ov023_021fbdcc; size: 0x10.
extern "C" void Ov023_ForwardObjectAt20(void *object) {
    Graphics_SelectBackgroundStateRecord((char *)object + 0x20);
}

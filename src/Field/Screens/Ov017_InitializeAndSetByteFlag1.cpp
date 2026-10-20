#include <globaldefs.h>
ARM
extern "C" void Graphics_RemoveDisplayEntry12AndRestoreSavedVram(void *self);
// Original: arm9/ov017 @ 0x021A6B84; symbol: func_ov017_021a6b84; size: 0x18.
extern "C" void Ov017_InitializeAndSetByteFlag1(unsigned char *self) {
    Graphics_RemoveDisplayEntry12AndRestoreSavedVram(self);
    self[1] = 1;
}

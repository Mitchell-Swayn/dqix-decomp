#include <globaldefs.h>
ARM
extern "C" void func_ov017_021a6b30(void *self);
// Original: arm9/ov017 @ 0x021A6B84; symbol: func_ov017_021a6b84; size: 0x18.
extern "C" void Ov017_InitializeAndSetByteFlag1(unsigned char *self) {
    func_ov017_021a6b30(self);
    self[1] = 1;
}

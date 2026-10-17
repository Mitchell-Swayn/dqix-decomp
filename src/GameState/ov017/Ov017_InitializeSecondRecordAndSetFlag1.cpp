#include <globaldefs.h>
ARM
extern "C" void func_ov017_021beb48(void *self);
// Original: arm9/ov017 @ 0x021BEB8C; symbol: func_ov017_021beb8c; size: 0x18.
extern "C" void Ov017_InitializeSecondRecordAndSetFlag1(unsigned char *self) {
    func_ov017_021beb48(self);
    self[1] = 1;
}

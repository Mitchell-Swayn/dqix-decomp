#include <globaldefs.h>
ARM
extern "C" void RemoveDisplayEntry5AndDestroyAllocator(void *self);
// Original: arm9/ov017 @ 0x021BEB8C; symbol: func_ov017_021beb8c; size: 0x18.
extern "C" void Field_CancelGrottoReturnEffect(unsigned char *self) {
    RemoveDisplayEntry5AndDestroyAllocator(self);
    self[1] = 1;
}

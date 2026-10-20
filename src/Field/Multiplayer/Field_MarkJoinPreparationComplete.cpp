#include <globaldefs.h>
ARM
// Original: arm9/ov017 @ 0x021AFB10; symbol: func_ov017_021afb10; size: 0xC.
extern "C" void Field_MarkJoinPreparationComplete(void *arg) {
    *(int *)((char *)arg + 0x28) = 1;
}

#include <globaldefs.h>
ARM
// Original: arm9/ov017 @ 0x021D4AB8; symbol: func_ov017_021d4ab8; size: 0x20.
extern "C" void Ov017_AppendThreeAndValue(void *object, unsigned int value) {
    **(unsigned int **)((char *)object + 0x14) = 3;
    unsigned int *old = *(unsigned int **)((char *)object + 0x14);
    *(unsigned int **)((char *)object + 0x14) = old + 2;
    old[1] = value;
}

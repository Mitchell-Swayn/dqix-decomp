#include <globaldefs.h>
ARM
// Original: arm9/ov017 @ 0x021C2B1C; symbol: func_ov017_021c2b1c; size: 0xC.
extern "C" void FieldMonsterCall_CompleteRequest(void *object) {
    *((unsigned char *)object + 1) = 1;
}

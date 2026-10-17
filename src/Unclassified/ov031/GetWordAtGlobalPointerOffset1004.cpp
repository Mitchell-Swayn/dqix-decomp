#include <globaldefs.h>
ARM
extern "C" void *data_ov031_0224e60c;
// Original: arm9/ov031 @ 0x02219220; symbol: func_ov031_02219220; size: 0x18.
extern "C" unsigned int GetWordAtGlobalPointerOffset1004(void) {
    return *(unsigned int *)((char *)data_ov031_0224e60c + 0x1004);
}

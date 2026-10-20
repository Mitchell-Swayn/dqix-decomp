#include <globaldefs.h>
ARM
// Original: arm9/ov002 @ 0x02168C00; symbol: func_ov002_02168c00; size: 0x38.
extern "C" int BothObjectFieldsAreSentinels(void* object) {
    unsigned first = *(unsigned*)((char*)object + 0x60) == 0xffffffffu;
    unsigned second = *(unsigned*)((char*)object + 0x64) == 0xffffffffu;
    if ((first & second) != 0) return 1;
    return 0;
}

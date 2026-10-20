#include <globaldefs.h>
ARM
// Original: arm9/ov017 @ 0x021D4B9C; symbol: func_ov017_021d4b9c; size: 0x2C.
extern "C" unsigned int Script_PopExecutionFrame(void *object) {
    unsigned int *cursor = *(unsigned int **)((char *)object + 0x28) - 3;
    *(unsigned int **)((char *)object + 0x28) = cursor;
    *(unsigned int *)((char *)object + 0x30) = cursor[1];
    *(unsigned int *)((char *)object + 0x34) = ((unsigned int *)*(unsigned int **)((char *)object + 0x28))[2];
    return **(unsigned int **)((char *)object + 0x28);
}

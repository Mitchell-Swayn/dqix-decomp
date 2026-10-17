#include <globaldefs.h>
ARM
extern "C" unsigned int Memory_AllocateZeroedBlock(void *, unsigned int);
// Original: arm9/ov031 @ 0x02227CC8; symbol: func_ov031_02227cc8; size: 0x10.
extern "C" unsigned int func_ov031_02227cc8(void *object) {
    return Memory_AllocateZeroedBlock(object, 0x20);
}

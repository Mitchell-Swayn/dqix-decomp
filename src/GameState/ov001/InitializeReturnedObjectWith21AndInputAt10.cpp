#include <globaldefs.h>
ARM
extern "C" unsigned int *Pool_AllocateAndAppendNode(void);
// Original: arm9/ov001 @ 0x0215A654; symbol: func_ov001_0215a654; size: 0x20.
extern "C" unsigned int *InitializeReturnedObjectWith21AndInputAt10(unsigned int unused, unsigned int value) {
    unsigned int *object = Pool_AllocateAndAppendNode();
    if (object) {
        object[0] = 0x15;
        *(unsigned int *)((char *)object + 0x10) = value;
    }
    return object;
}

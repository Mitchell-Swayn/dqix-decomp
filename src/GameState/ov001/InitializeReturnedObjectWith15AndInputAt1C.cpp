#include <globaldefs.h>
ARM
extern "C" unsigned int *Queue_AllocateAndAppendNode(void);
// Original: arm9/ov001 @ 0x021591B0; symbol: func_ov001_021591b0; size: 0x20.
extern "C" unsigned int *InitializeReturnedObjectWith15AndInputAt1C(unsigned int unused, unsigned int value) {
    unsigned int *object = Queue_AllocateAndAppendNode();
    if (object) {
        object[0] = 15;
        *(unsigned int *)((char *)object + 0x1c) = value;
    }
    return object;
}

#include <globaldefs.h>
ARM
extern "C" void *Queue_AppendNodeFromFreeList(void *object);
// Original: arm9/ov001 @ 0x021590DC; symbol: func_ov001_021590dc; size: 0x20.
extern "C" void *Ov001_InitializeReturnedObject(void *object, unsigned int value) {
    void *result = Queue_AppendNodeFromFreeList(object);
    if (result) {
        *(unsigned int *)result = 10;
        *(unsigned int *)((char *)result + 0x1c) = value;
    }
    return result;
}

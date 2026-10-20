#include <globaldefs.h>
ARM
extern "C" void *Memory_AppendFreePoolNode(void *);

// Original: arm9/ov001 @ 0x0215A69C; symbol: func_ov001_0215a69c; size: 0x20.
extern "C" void *Event_QueueSoundDelay(void *context, unsigned int value) {
    void *result = Memory_AppendFreePoolNode(context);
    if (result != 0) {
        *(unsigned int *)result = 0x17;
        *(unsigned int *)((unsigned char *)result + 0x10) = value;
    }
    return result;
}

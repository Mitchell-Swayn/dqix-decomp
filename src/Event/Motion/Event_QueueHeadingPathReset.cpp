#include <globaldefs.h>
ARM
extern "C" void *Pool_AppendFreeNode(void);

// Original: arm9/ov001 @ 0x0215A3C0; symbol: func_ov001_0215a3c0; size: 0x18.
extern "C" void *Event_QueueHeadingPathReset(void) {
    void *result = Pool_AppendFreeNode();
    if (result != 0)
        *(int *)result = 3;
    return result;
}

#include <globaldefs.h>
ARM
extern "C" void *Queue_AppendNode(void);

// Original: arm9/ov001 @ 0x021590C4; symbol: func_ov001_021590c4; size: 0x18.
extern "C" void *Queue_AppendType9Node(void) {
    void *result = Queue_AppendNode();
    if (result != 0)
        *(int *)result = 9;
    return result;
}

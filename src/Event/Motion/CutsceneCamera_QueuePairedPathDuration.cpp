#include <globaldefs.h>
ARM
extern "C" unsigned *Queue_AppendNode(void *object);
// Original: arm9/ov001 @ 0x0215905C; symbol: func_ov001_0215905c; size: 0x20.
extern "C" void CutsceneCamera_QueuePairedPathDuration(void *object, unsigned value) {
    unsigned *p = Queue_AppendNode(object);
    if (p) {
        p[0] = 7;
        *(unsigned *)((char *)p + 0x1c) = value;
    }
}

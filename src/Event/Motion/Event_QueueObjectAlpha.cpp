#include <globaldefs.h>
ARM
extern "C" unsigned *Pool_AllocateAndAppendNode(void *object);
// Original: arm9/ov001 @ 0x0215A4C8; symbol: func_ov001_0215a4c8; size: 0x20.
extern "C" void Event_QueueObjectAlpha(void *object, unsigned value) {
    unsigned *p = Pool_AllocateAndAppendNode(object);
    if (p) {
        p[0] = 0x12;
        *(unsigned *)((char *)p + 0x10) = value;
    }
}

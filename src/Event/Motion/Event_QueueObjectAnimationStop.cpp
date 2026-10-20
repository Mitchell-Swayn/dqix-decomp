#include <globaldefs.h>
ARM
extern "C" unsigned *Pool_AllocateAndLinkNode(void);
// Original: arm9/ov001 @ 0x0215A5F0; symbol: func_ov001_0215a5f0; size: 0x18.
extern "C" void Event_QueueObjectAnimationStop(void) {
    unsigned *p = Pool_AllocateAndLinkNode();
    if (p)
        *p = 0xe;
}

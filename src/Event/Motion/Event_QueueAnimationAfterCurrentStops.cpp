#include <globaldefs.h>
ARM
extern "C" char *strcpy(char *, const char *);
extern "C" void *Pool_AllocateAndLinkNode(void);

// Original: arm9/ov001 @ 0x0215A594; symbol: func_ov001_0215a594; size: 0x44.
extern "C" void Event_QueueAnimationAfterCurrentStops(void *queue, const char *name, unsigned int first, unsigned int second) {
    unsigned char *entry = (unsigned char *)Pool_AllocateAndLinkNode();
    if (entry == 0) return;
    *(unsigned int *)entry = 0xb;
    strcpy((char *)entry + 0x1c, name);
    *(unsigned int *)(entry + 0x10) = first;
    *(unsigned int *)(entry + 0x14) = second;
    *(unsigned int *)(entry + 0x18) = 0;

}

#include <globaldefs.h>
extern "C" void *GameResources_GetInstance();
extern "C" void Field_InitializeTravelConfirmation(signed char *);
extern "C" void LinkedQueue_AppendAndMarkActive(unsigned *, unsigned);
// Original: arm9/ov017 @ 0x021A72F4; symbol: func_ov017_021a72f4; size: 0x34.
extern "C" void Field_QueueTravelConfirmation(void *unused, unsigned value) {
    unsigned char *resources = (unsigned char *)GameResources_GetInstance() + 0x3000;
    unsigned *list = *(unsigned **)(resources + 0x6fc);
    signed char *node = *(signed char **)(resources + 0xb94);
    Field_InitializeTravelConfirmation(node);
    *(unsigned *)(node + 0xc) = value;
    LinkedQueue_AppendAndMarkActive(list, (unsigned)node);
}

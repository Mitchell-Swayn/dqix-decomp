#include <globaldefs.h>
ARM
extern "C" void InitializeType23LinkedNode(void *node);
extern "C" void LinkedQueue_AppendAndMarkActive(unsigned *list, unsigned node);
// Original: arm9/ov017 @ 0x021B6728; symbol: func_ov017_021b6728; size: 0x68.
extern "C" void Field_QueuePartyManagementWithSelectionMode(void *state, int mode, unsigned char value) {
    unsigned char *bytes = (unsigned char *)state;
    InitializeType23LinkedNode(*(void **)(bytes + 0x3b00));
    LinkedQueue_AppendAndMarkActive(*(unsigned **)(bytes + 0x36fc), (unsigned)*(void **)(bytes + 0x3b00));
    if (mode == 1) {
        unsigned char *node = *(unsigned char **)(bytes + 0x3b00);
        node[0x1f] = 4;
        (*(volatile unsigned char **)(bytes + 0x3b00))[0x20] = value;
    } else if (mode == 0) {
        unsigned char *node = *(unsigned char **)(bytes + 0x3b00);
        node[0x1f] = 3;
    }
}

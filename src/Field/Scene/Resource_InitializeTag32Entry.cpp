#include <globaldefs.h>
ARM
extern "C" void LinkedQueue_InitializeNodeStatus(signed char *);
// Original: arm9/ov017 @ 0x021BDBF0; symbol: func_ov017_021bdbf0; size: 0x44.
extern "C" void Resource_InitializeTag32Entry(signed char *entry) {
    LinkedQueue_InitializeNodeStatus(entry);
    entry[0] = 0x32;
    entry[0x10] = 0;
    entry[0x11] = 1;
    for (int i = 0; i < 4; i++) *(short *)(entry + 8 + i * 2) = -1;
}

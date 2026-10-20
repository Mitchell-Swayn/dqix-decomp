#include <globaldefs.h>
ARM
extern "C" void Network_SubmitSocketCommand(int);

// Original: arm9/ov031 @ 0x0220527C; symbol: func_ov031_0220527c; size: 0x10.
extern "C" void Network_SubmitReceiveCommand(void *object) {
    Network_SubmitSocketCommand(*(int *)((unsigned char *)object + 0x64));
}

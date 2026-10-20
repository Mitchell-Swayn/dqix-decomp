#include <globaldefs.h>
ARM
extern "C" void Network_SubmitSocketCommand(int);
// Original: arm9/ov031 @ 0x0220528C; symbol: func_ov031_0220528c; size: 0x10.
extern "C" void Network_SubmitSendCommand(int a0) {
    Network_SubmitSocketCommand(*(int *)(a0 + 0x68));
}
